
#ifndef _SPL_H
#define _SPL_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined IS_ALB32RP65

/* Includes ------------------------------------------------------------------*/

#include "hw_common.h"

/******************************************************************************/
/*                                                                            */
/*                        SPL HW Semaphore                                   */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for SPL_R register  ********************/
#define SPL_R_PROCID_Pos         (0U)
#define SPL_R_PROCID_Msk         (0xFFUL << SPL_R_PROCID_Pos)                /*!< 0x000000FF */
#define SPL_R_PROCID             SPL_R_PROCID_Msk                            /*!<Semaphore ProcessID */
#define SPL_R_COREID_Pos         (8U)
#define SPL_R_COREID_Msk         (0xFFUL << SPL_R_COREID_Pos)                /*!< 0x0000FF00 */
#define SPL_R_COREID             SPL_R_COREID_Msk                            /*!<Semaphore CoreID.   */
#define SPL_R_LOCK_Pos           (31U)
#define SPL_R_LOCK_Msk           (0x1UL << SPL_R_LOCK_Pos)                   /*!< 0x80000000 */
#define SPL_R_LOCK               SPL_R_LOCK_Msk                              /*!<Lock indication.    */

/********************  Bit definition for SPL_RLR register  ******************/
#define SPL_RLR_PROCID_Pos       (0U)
#define SPL_RLR_PROCID_Msk       (0xFFUL << SPL_RLR_PROCID_Pos)              /*!< 0x000000FF */
#define SPL_RLR_PROCID           SPL_RLR_PROCID_Msk                          /*!<Semaphore ProcessID */
#define SPL_RLR_COREID_Pos       (8U)
#define SPL_RLR_COREID_Msk       (0xFFUL << SPL_RLR_COREID_Pos)              /*!< 0x0000FF00 */
#define SPL_RLR_COREID           SPL_RLR_COREID_Msk                          /*!<Semaphore CoreID.   */
#define SPL_RLR_LOCK_Pos         (31U)
#define SPL_RLR_LOCK_Msk         (0x1UL << SPL_RLR_LOCK_Pos)                 /*!< 0x80000000 */
#define SPL_RLR_LOCK             SPL_RLR_LOCK_Msk                            /*!<Lock indication.    */


/********************  Bit definition for SPL_CR register  *****************/
#define SPL_CR_COREID_Pos        (8U)
#define SPL_CR_COREID_Msk        (0xFFUL << SPL_CR_COREID_Pos)               /*!< 0x0000FF00 */
#define SPL_CR_COREID            SPL_CR_COREID_Msk                           /*!<CoreID of semaphores to be cleared. */
#define SPL_CR_KEY_Pos           (16U)
#define SPL_CR_KEY_Msk           (0xFFFFUL << SPL_CR_KEY_Pos)                /*!< 0xFFFF0000 */
#define SPL_CR_KEY               SPL_CR_KEY_Msk                              /*!<semaphores clear key. */

/********************  Bit definition for SPL_KEYR register  *****************/
#define SPL_KEYR_KEY_Pos         (16U)
#define SPL_KEYR_KEY_Msk         (0xFFFFUL << SPL_KEYR_KEY_Pos)              /*!< 0xFFFF0000 */
#define SPL_KEYR_KEY             SPL_KEYR_KEY_Msk                            /*!<semaphores clear key. */



typedef struct {
    __IO uint32_t R[32];
    __IO uint32_t RLR[32];
    __IO uint32_t IER;
    __IO uint32_t ICR;
    __IO uint32_t ISR;
    __IO uint32_t MISR;
    __IO uint32_t REV1[60];
    __IO uint32_t CR;
    __IO uint32_t KEYR;
    __IO uint32_t REV2[62];
    __IO uint32_t FSLOCK;
    __IO uint32_t FSCTRL;
    __IO uint32_t FSDATA;
    __IO uint32_t FSINFO;
    __IO uint32_t REV3[58];
    __IO uint32_t PARAM;
    __IO uint32_t REV;
} SPL_TypeDef;
#define SPL     ((SPL_TypeDef *)SPL_BASE)
/**
  * @brief  SemID to mask helper Macro.
  * @param  __SEMID__: semaphore ID from 0 to 31
  * @retval Semaphore Mask.
  */
#define __SPL_SEMID_TO_MASK(__SEMID__) (1 << (__SEMID__))

/**
  * @brief  Enables the specified SPL interrupts.
  * @param  __SEM_MASK__: semaphores Mask
  * @retval None.
  */

#define __SPL_ENABLE_IT(__SEM_MASK__) (SPL->IER |= (__SEM_MASK__))

/**
  * @brief  Disables the specified SPL interrupts.
  * @param  __SEM_MASK__: semaphores Mask
  * @retval None.
  */

#define __SPL_DISABLE_IT(__SEM_MASK__) (SPL->IER &= ~(__SEM_MASK__))


/**
  * @brief  Checks whether interrupt has occurred or not for semaphores specified by a mask.
  * @param  __SEM_MASK__: semaphores Mask
  * @retval semaphores Mask : Semaphores where an interrupt occurred.
  */

#define __SPL_GET_IT(__SEM_MASK__) ((__SEM_MASK__) & SPL->MISR)


/**
  * @brief  Get the semaphores release status flags.
  * @param  __SEM_MASK__: semaphores Mask
  * @retval semaphores Mask : Semaphores where Release flags rise.
  */
#define __SPL_GET_FLAG(__SEM_MASK__) ((__SEM_MASK__) & SPL->ISR)


/**
  * @brief  Clears the SPL Interrupt flags.
  * @param  __SEM_MASK__: semaphores Mask
  * @retval None.
  */

#define __SPL_CLEAR_FLAG(__SEM_MASK__) (SPL->ICR |= (__SEM_MASK__))


/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup SPL_Exported_Functions SPL Exported Functions
  * @{
  */

/** @addtogroup SPL_Exported_Functions_Group1 Take and Release functions
  * @brief    SPL Take and Release functions
  * @{
  */

/* SPL semaphore take (lock) using 2-Step  method ****************************/
int  SPL_Take(uint32_t SemID, uint32_t ProcessID);
/* SPL semaphore fast take (lock) using 1-Step  method ***********************/
int  SPL_FastTake(uint32_t SemID);
/* SPL Release  **************************************************************/
void  SPL_Release(uint32_t SemID, uint32_t ProcessID);
/* SPL Release All************************************************************/
void SPL_ReleaseAll(uint32_t Key, uint32_t CoreID);
/* SPL Check semaphore state Taken or not   **********************************/
uint32_t SPL_IsSemTaken(uint32_t SemID);

/**
  * @}
  */

/** @addtogroup SPL_Exported_Functions_Group2 SPL Set and Get Key functions
  * @brief    SPL Set and Get Key functions.
  * @{
  */
/* SPL Set Clear Key *********************************************************/
void  SPL_SetClearKey(uint32_t Key);
/* SPL Get Clear Key *********************************************************/
uint32_t SPL_GetClearKey(void);
/**
  * @}
  */

/** @addtogroup SPL_Exported_Functions_Group3
  * @brief   SPL Notification functions
  * @{
  */
/* SPL Activate SPL Notification (When a semaphore is released) ) *****************/
void SPL_ActivateNotification(uint32_t SemMask);
/* SPL Deactivate SPL Notification (When a semaphore is released)  ****************/
void SPL_DeactivateNotification(uint32_t SemMask);
/* SPL Free Callback (When a semaphore is released)  *******************************/
void SPL_FreeCallback(uint32_t SemMask);
/* SPL IRQ Handler  **********************************************************/
void SPL_IRQHandler(void);

/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup SPL_Private_Macros SPL Private Macros
  * @{
  */

#define SPL_SEMID_MAX 16
#define SPL_PROCESSID_MAX 256
#define SPL_COREID_MAX 4


#define IS_SPL_SEMID(__SEMID__)         ((__SEMID__) <= SPL_SEMID_MAX )

#define IS_SPL_PROCESSID(__PROCESSID__) ((__PROCESSID__) <= SPL_PROCESSID_MAX )

#define IS_SPL_KEY(__KEY__)             ((__KEY__) <= SPL_CLEAR_KEY_MAX )

#define IS_SPL_COREID(__COREID__)       ((__COREID__) < SPL_COREID_MAX )


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif

#endif
