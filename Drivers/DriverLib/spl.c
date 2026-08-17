

#if defined IS_ALB32RP65

#include "spl.h"

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @defgroup SPL_Exported_Functions  SPL Exported Functions
  * @{
  */

/** @defgroup SPL_Exported_Functions_Group1 Take and Release functions
  *  @brief    SPL Take and Release functions
  *
@verbatim
 ==============================================================================
              ##### SPL Take and Release functions #####
 ==============================================================================
[..] This section provides functions allowing to:
      (+) Take a semaphore with 2 Step method
      (+) Fast Take a semaphore with 1 Step method
      (+) Check semaphore state Taken or not
      (+) Release a semaphore
      (+) Release all semaphore at once

@endverbatim
  * @{
  */


/**
  * @brief  Take a semaphore in 2 Step mode.
  * @param  SemID: semaphore ID from 0 to 15
  * @param  ProcessID: Process ID from 0 to 255
  * @retval HAL status
  */
int  SPL_Take(uint32_t SemID, uint32_t ProcessID)
{
  /* Check the parameters */
  ASSERT(IS_SPL_SEMID(SemID));
  ASSERT(IS_SPL_PROCESSID(ProcessID));

  ASSERT(IS_SPL_COREID(COREID));


  /* First step  write R register with MasterID, processID and take bit=1*/
  SPL->R[SemID] = (ProcessID | (COREID<<SPL_CR_COREID_Pos) | SPL_R_LOCK);

  /* second step : read the R register . Take achieved if MasterID and processID match and take bit set to 1 */
  if (SPL->R[SemID] == (ProcessID | (COREID<<SPL_CR_COREID_Pos) | SPL_R_LOCK))
  {
    /*take success when MasterID and ProcessID match and take bit set*/
    return 0;
  }


  /* Semaphore take fails*/
  return -1;
}

/**
  * @brief  Fast Take a semaphore with 1 Step mode.
  * @param  SemID: semaphore ID from 0 to 31
  * @retval HAL status
  */
int SPL_FastTake(uint32_t SemID)
{
  /* Check the parameters */
  ASSERT(IS_SPL_SEMID(SemID));
  ASSERT(IS_SPL_COREID(COREID));


  /* Read the RLR register to take the semaphore */
  if (SPL->RLR[SemID] == (( (COREID<<SPL_CR_COREID_Pos)) | SPL_RLR_LOCK))
  {
    /*take success when MasterID match and take bit set*/
    return 0;
  }


  /* Semaphore take fails */
  return -1;
}
/**
  * @brief  Check semaphore state Taken or not.
  * @param  SemID: semaphore ID
  * @retval HAL SPL state
  */
uint32_t SPL_IsSemTaken(uint32_t SemID)
{
  return (((SPL->R[SemID] & SPL_R_LOCK) != 0U) ? 1UL : 0UL);
}


/**
  * @brief  Release a semaphore.
  * @param  SemID: semaphore ID from 0 to 31
  * @param  ProcessID: Process ID from 0 to 255
  * @retval None
  */
void  SPL_Release(uint32_t SemID, uint32_t ProcessID)
{
  /* Check the parameters */
  ASSERT(IS_SPL_SEMID(SemID));
  ASSERT(IS_SPL_PROCESSID(ProcessID));
  ASSERT(IS_SPL_COREID(COREID));
  /* Clear the semaphore by writing to the R register : the MasterID , the processID and take bit = 0  */
  SPL->R[SemID] = (ProcessID |  (COREID<<SPL_CR_COREID_Pos));


}

/**
  * @brief  Release All semaphore used by a given Master .
  * @param  Key: Semaphore Key , value from 0 to 0xFFFF
  * @param  CoreID: CoreID of the CPU that is using semaphores to be released
  * @retval None
  */
void SPL_ReleaseAll(uint32_t Key, uint32_t CoreID)
{
  ASSERT(IS_SPL_KEY(Key));
  ASSERT(IS_SPL_COREID(CoreID));

  SPL->CR = ((Key << SPL_CR_KEY_Pos) | (CoreID << SPL_CR_COREID_Pos));
}

/**
  * @}
  */

/** @defgroup SPL_Exported_Functions_Group2 SPL Set and Get Key functions
  *  @brief    SPL Set and Get Key functions.
  *
@verbatim
  ==============================================================================
              ##### SPL Set and Get Key functions #####
  ==============================================================================
    [..]  This section provides functions allowing to:
      (+) Set semaphore Key
      (+) Get semaphore Key
@endverbatim

  * @{
  */

/**
  * @brief  Set semaphore Key .
  * @param  Key: Semaphore Key , value from 0 to 0xFFFF
  * @retval None
  */
void  SPL_SetClearKey(uint32_t Key)
{
  ASSERT(IS_SPL_KEY(Key));

  MODIFY_REG(SPL->KEYR, SPL_KEYR_KEY, (Key << SPL_KEYR_KEY_Pos));

}

/**
  * @brief  Get semaphore Key .
  * @retval Semaphore Key , value from 0 to 0xFFFF
  */
uint32_t SPL_GetClearKey(void)
{
  return (SPL->KEYR >> SPL_KEYR_KEY_Pos);
}


/**
  * @}
  */

/** @defgroup SPL_Exported_Functions_Group3 SPL IRQ handler management
  *  @brief    SPL Notification functions.
  *
@verbatim
  ==============================================================================
      ##### SPL IRQ handler management and Notification functions #####
  ==============================================================================
[..]  This section provides SPL IRQ handler and Notification function.

@endverbatim
  * @{
  */

/**
  * @brief  Activate Semaphore release Notification for a given Semaphores Mask .
  * @param  SemMask: Mask of Released semaphores
  * @retval Semaphore Key
  */
void SPL_ActivateNotification(uint32_t SemMask)
{

	SPL->IER |= SemMask;

}

/**
  * @brief  Deactivate Semaphore release Notification for a given Semaphores Mask .
  * @param  SemMask: Mask of Released semaphores
  * @retval Semaphore Key
  */
void SPL_DeactivateNotification(uint32_t SemMask)
{

	SPL->IER &= ~SemMask;

}

/**
  * @brief  This function handles SPL interrupt request
  * @retval None
  */
void SPL_IRQHandler(void)
{
  uint32_t statusreg;
  /* Get the list of masked freed semaphores*/
  statusreg = SPL->MISR;

  /*Disable Interrupts*/
  SPL->IER &= ~((uint32_t)statusreg);

  /*Clear Flags*/
  SPL->ICR = ((uint32_t)statusreg);


  /* Call FreeCallback */
  SPL_FreeCallback(statusreg);
}

/**
  * @brief Semaphore Released Callback.
  * @param SemMask: Mask of Released semaphores
  * @retval None
  */
__attribute__((weak))  void SPL_FreeCallback(uint32_t SemMask)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(SemMask);

  /* NOTE : This function should not be modified, when the callback is needed,
  the SPL_FreeCallback can be implemented in the user file
    */
}

#endif
/**
  * @}
  */

/**
  * @}
  */


/**
  * @}
  */

/**
  * @}
  */
