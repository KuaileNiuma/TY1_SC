/**
 *************************************************************************************
 * @file dhry_1.c
 * @author Albatross
 * @brief This file contains the source file.
 * @version 1.0.0
 * @date 2025-07-30
 *************************************************************************************
 * @copyright Copyright (c) 2025 Albatross Semiconductor(Hangzhou) Co.,Ltd.
 * BSD-3-Clause License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ************************************************************************************
 */
/*
 ****************************************************************************
 *
 *                   "DHRYSTONE" Benchmark Program
 *                   -----------------------------
 *                                                                            
 *  Version:    C, Version 2.1
 *                                                                            
 *  File:       dhry_1.c (part 2 of 3)
 *
 *  Date:       May 25, 1988
 *
 *  Author:     Reinhold P. Weicker
 *
 ****************************************************************************
 */

#include "dhry.h"
#include "device.h"
#include "alb32r003x_evb.h"
#include <stdlib.h>
#include <string.h>
/* Global Variables: */

Rec_Pointer     Ptr_Glob,
                Next_Ptr_Glob;
int             Int_Glob;
Boolean         Bool_Glob;
char            Ch_1_Glob,
                Ch_2_Glob;
int             Arr_1_Glob [50];
int             Arr_2_Glob [50] [50];

extern void     *malloc (unsigned int);
  /* forward declaration necessary since Enumeration may not simply be int */

#ifndef REG
        Boolean Reg = false;
#define REG
        /* REG becomes defined as empty */
        /* i.e. no register variables   */
#else
        Boolean Reg = true;
#endif

/* variables for time measurement: */

#ifdef TIMES
struct tms      time_info;
extern  int     times ();
                /* see library function "times" */
#define Too_Small_Time (2*HZ)
                /* Measurements should last at least about 2 seconds */
#endif
#ifdef TIME
extern long     time();
                /* see library function "time"  */
#define Too_Small_Time 2
                /* Measurements should last at least 2 seconds */
#endif
#ifdef MSC_CLOCK
extern uint64_t myclock(void);
#define Too_Small_Time (2*HZ)
#endif

unsigned long     Begin_Time,
                  End_Time,
                  User_Time;
volatile float           Microseconds,
                Dhrystones_Per_Second,
				Vax_Mips;


void Proc_1 (REG Rec_Pointer Ptr_Val_Par);
void Proc_2 (One_Fifty   * Int_Par_Ref);
void Proc_3 (Rec_Pointer * Ptr_Ref_Par);
void Proc_4 (void);
void Proc_5 (void);

/* end of variables for time measurement */
void benchmark_dhry_main (unsigned int run_loops)
/*****/

  /* main program, corresponds to procedures        */
  /* Main and Proc_0 in the Ada version             */
{
        One_Fifty       Int_1_Loc;
  REG   One_Fifty       Int_2_Loc;
        One_Fifty       Int_3_Loc;
  REG   char            Ch_Index;
        Enumeration     Enum_Loc;
        Str_30          Str_1_Loc;
        Str_30          Str_2_Loc;
  REG   int             Run_Index;
  REG   int             Number_Of_Runs;

  /* Initializations */

  Next_Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));
  Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));

  Ptr_Glob->Ptr_Comp                    = Next_Ptr_Glob;
  Ptr_Glob->Discr                       = Ident_1;
  Ptr_Glob->variant.var_1.Enum_Comp     = Ident_3;
  Ptr_Glob->variant.var_1.Int_Comp      = 40;
  strcpy (Ptr_Glob->variant.var_1.Str_Comp, 
          "DHRYSTONE PROGRAM, SOME STRING");
  strcpy (Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING");

  Arr_2_Glob [8][7] = 10;
        /* Was missing in published program. Without this statement,    */
        /* Arr_2_Glob [8][7] would have an undefined value.             */
        /* Warning: With 16-Bit processors and Number_Of_Runs > 32000,  */
        /* overflow may occur for this array element.                   */

  log_printf ("\n");
  log_printf ("Dhrystone Benchmark, Version 2.1 (Language: C)\n");
  log_printf ("\n");
  if (Reg)
  {
    log_printf ("Program compiled with 'register' attribute\n");
    log_printf ("\n");
  }
  else
  {
    log_printf ("Program compiled without 'register' attribute\n");
    log_printf ("\n");
  }
  log_printf ("Please give the number of runs through the benchmark: ");
  {
    //scanf ("%d", &n);
    Number_Of_Runs = run_loops;
  }
  log_printf ("\n");

  log_printf ("Execution starts, %d runs through Dhrystone\n", Number_Of_Runs);

  /***************/
  /* Start timer */
  /***************/
 
#ifdef TIMES
  times (&time_info);
  Begin_Time = (long) time_info.tms_utime;
#endif
#ifdef TIME
  Begin_Time = time();
#endif
#ifdef MSC_CLOCK
  Begin_Time = myclock();
#endif

  for (Run_Index = 1; Run_Index <= Number_Of_Runs; ++Run_Index)
  {

    Proc_5();
    Proc_4();
      /* Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == true */
    Int_1_Loc = 2;
    Int_2_Loc = 3;
    strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
    Enum_Loc = Ident_2;
    Bool_Glob = ! Func_2 (Str_1_Loc, Str_2_Loc);
      /* Bool_Glob == 1 */
    while (Int_1_Loc < Int_2_Loc)  /* loop body executed once */
    {
      Int_3_Loc = 5 * Int_1_Loc - Int_2_Loc;
        /* Int_3_Loc == 7 */
      Proc_7 (Int_1_Loc, Int_2_Loc, &Int_3_Loc);
        /* Int_3_Loc == 7 */
      Int_1_Loc += 1;
    } /* while */
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Proc_8 (Arr_1_Glob, Arr_2_Glob, Int_1_Loc, Int_3_Loc);
      /* Int_Glob == 5 */
    Proc_1 (Ptr_Glob);
    for (Ch_Index = 'A'; Ch_Index <= Ch_2_Glob; ++Ch_Index)
                             /* loop body executed twice */
    {
      if (Enum_Loc == Func_1 (Ch_Index, 'C'))
          /* then, not executed */
        {
        Proc_6 (Ident_1, &Enum_Loc);
        strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 3'RD STRING");
        Int_2_Loc = Run_Index;
        Int_Glob = Run_Index;
        }
    }
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    Int_2_Loc = Int_2_Loc * Int_1_Loc;
    Int_1_Loc = Int_2_Loc / Int_3_Loc;
    Int_2_Loc = 7 * (Int_2_Loc - Int_3_Loc) - Int_1_Loc;
      /* Int_1_Loc == 1, Int_2_Loc == 13, Int_3_Loc == 7 */
    Proc_2 (&Int_1_Loc);
      /* Int_1_Loc == 5 */

  } /* loop "for Run_Index" */

  /**************/
  /* Stop timer */
  /**************/
  
#ifdef TIMES
  times (&time_info);
  End_Time = (long) time_info.tms_utime;
#endif
#ifdef TIME
  End_Time = time();
#endif
#ifdef MSC_CLOCK
  End_Time = myclock();
#endif

  log_printf ("Execution ends\n");
  log_printf ("\n");
  log_printf ("Final values of the variables used in the benchmark:\n");
  log_printf ("\n");
  log_printf ("Int_Glob:            %d\n", Int_Glob);
  log_printf ("        should be:   %d\n", 5);
  log_printf ("Bool_Glob:           %d\n", Bool_Glob);
  log_printf ("        should be:   %d\n", 1);
  log_printf ("Ch_1_Glob:           %c\n", Ch_1_Glob);
  log_printf ("        should be:   %c\n", 'A');
  log_printf ("Ch_2_Glob:           %c\n", Ch_2_Glob);
  log_printf ("        should be:   %c\n", 'B');
  log_printf ("Arr_1_Glob[8]:       %d\n", Arr_1_Glob[8]);
  log_printf ("        should be:   %d\n", 7);
  log_printf ("Arr_2_Glob[8][7]:    %d\n", Arr_2_Glob[8][7]);
  log_printf ("        should be:   Number_Of_Runs + 10\n");
  log_printf ("Ptr_Glob->\n");
  log_printf ("  Ptr_Comp:          %d\n", (int) Ptr_Glob->Ptr_Comp);
  log_printf ("        should be:   (implementation-dependent)\n");
  log_printf ("  Discr:             %d\n", Ptr_Glob->Discr);
  log_printf ("        should be:   %d\n", 0);
  log_printf ("  Enum_Comp:         %d\n", Ptr_Glob->variant.var_1.Enum_Comp);
  log_printf ("        should be:   %d\n", 2);
  log_printf ("  Int_Comp:          %d\n", Ptr_Glob->variant.var_1.Int_Comp);
  log_printf ("        should be:   %d\n", 17);
  log_printf ("  Str_Comp:          %s\n", Ptr_Glob->variant.var_1.Str_Comp);
  log_printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  log_printf ("Next_Ptr_Glob->\n");
  log_printf ("  Ptr_Comp:          %d\n", (int) Next_Ptr_Glob->Ptr_Comp);
  log_printf ("        should be:   (implementation-dependent), same as above\n");
  log_printf ("  Discr:             %d\n", Next_Ptr_Glob->Discr);
  log_printf ("        should be:   %d\n", 0);
  log_printf ("  Enum_Comp:         %d\n", Next_Ptr_Glob->variant.var_1.Enum_Comp);
  log_printf ("        should be:   %d\n", 1);
  log_printf ("  Int_Comp:          %d\n", Next_Ptr_Glob->variant.var_1.Int_Comp);
  log_printf ("        should be:   %d\n", 18);
  log_printf ("  Str_Comp:          %s\n",
                                Next_Ptr_Glob->variant.var_1.Str_Comp);
  log_printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  log_printf ("Int_1_Loc:           %d\n", Int_1_Loc);
  log_printf ("        should be:   %d\n", 5);
  log_printf ("Int_2_Loc:           %d\n", Int_2_Loc);
  log_printf ("        should be:   %d\n", 13);
  log_printf ("Int_3_Loc:           %d\n", Int_3_Loc);
  log_printf ("        should be:   %d\n", 7);
  log_printf ("Enum_Loc:            %d\n", Enum_Loc);
  log_printf ("        should be:   %d\n", 1);
  log_printf ("Str_1_Loc:           %s\n", Str_1_Loc);
  log_printf ("        should be:   DHRYSTONE PROGRAM, 1'ST STRING\n");
  log_printf ("Str_2_Loc:           %s\n", Str_2_Loc);
  log_printf ("        should be:   DHRYSTONE PROGRAM, 2'ND STRING\n");
  log_printf ("\n");

  User_Time = End_Time - Begin_Time;

  if (User_Time < Too_Small_Time)
  {
    log_printf ("Measured time too small to obtain meaningful results\n");
    log_printf ("Please increase number of runs\n");
    log_printf ("\n");
  }
  else
  {
#ifdef TIME
    Microseconds = (float) User_Time * Mic_secs_Per_Second 
                        / (float) Number_Of_Runs;
    Dhrystones_Per_Second = (float) Number_Of_Runs / (float) User_Time;
#else
    Microseconds = (float) User_Time * Mic_secs_Per_Second 
                        / ((float) HZ * ((float) Number_Of_Runs));
    Dhrystones_Per_Second = ((float) HZ * (float) Number_Of_Runs)
                        / (float) User_Time;
#endif
    Vax_Mips = Dhrystones_Per_Second / 1757.0;
    log_printf ("Microseconds for one run through Dhrystone: ");
    log_printf ("%6.1f \n", Microseconds);
    log_printf ("Dhrystones per Second:                      ");
    log_printf ("%6.1f \n", Dhrystones_Per_Second);
    log_printf ("\n");
    log_printf ("VAX  MIPS rating =                          ");
    log_printf ("%6.2lf \n",Vax_Mips);
    log_printf ("%DMIP/MHz =                                 ");
    log_printf ("%6.2lf \n",Vax_Mips / (SystemClock_Get() / 1000000.0f));
    log_printf ("\n");
    log_printf ("\n");
    log_printf("User_Time = %u\n", User_Time);
    log_printf("\nCSV, Benchmark, Iterations, Cycles, DMIPS/MHz\n");
  }
  
}

void Proc_1 (Ptr_Val_Par)
/******************/

REG Rec_Pointer Ptr_Val_Par;
    /* executed once */
{
  REG Rec_Pointer Next_Record = Ptr_Val_Par->Ptr_Comp;  
                                        /* == Ptr_Glob_Next */
  /* Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    */
  /* corresponds to "rename" in Ada, "with" in Pascal           */
  
  structassign (*Ptr_Val_Par->Ptr_Comp, *Ptr_Glob); 
  Ptr_Val_Par->variant.var_1.Int_Comp = 5;
  Next_Record->variant.var_1.Int_Comp 
        = Ptr_Val_Par->variant.var_1.Int_Comp;
  Next_Record->Ptr_Comp = Ptr_Val_Par->Ptr_Comp;
  Proc_3 (&Next_Record->Ptr_Comp);
    /* Ptr_Val_Par->Ptr_Comp->Ptr_Comp 
                        == Ptr_Glob->Ptr_Comp */
  if (Next_Record->Discr == Ident_1)
    /* then, executed */
  {
    Next_Record->variant.var_1.Int_Comp = 6;
    Proc_6 (Ptr_Val_Par->variant.var_1.Enum_Comp, 
           &Next_Record->variant.var_1.Enum_Comp);
    Next_Record->Ptr_Comp = Ptr_Glob->Ptr_Comp;
    Proc_7 (Next_Record->variant.var_1.Int_Comp, 10, 
           &Next_Record->variant.var_1.Int_Comp);
  }
  else /* not executed */
    structassign (*Ptr_Val_Par, *Ptr_Val_Par->Ptr_Comp);
} /* Proc_1 */


void Proc_2 (Int_Par_Ref)
/******************/
    /* executed once */
    /* *Int_Par_Ref == 1, becomes 4 */

One_Fifty   *Int_Par_Ref;
{
  One_Fifty  Int_Loc;  
  Enumeration   Enum_Loc;

  Int_Loc = *Int_Par_Ref + 10;
  do /* executed once */
    if (Ch_1_Glob == 'A')
      /* then, executed */
    {
      Int_Loc -= 1;
      *Int_Par_Ref = Int_Loc - Int_Glob;
      Enum_Loc = Ident_1;
    } /* if */
  while (Enum_Loc != Ident_1); /* true */
} /* Proc_2 */


void Proc_3 (Ptr_Ref_Par)
/******************/
    /* executed once */
    /* Ptr_Ref_Par becomes Ptr_Glob */

Rec_Pointer *Ptr_Ref_Par;

{
  if (Ptr_Glob != Null)
    /* then, executed */
    *Ptr_Ref_Par = Ptr_Glob->Ptr_Comp;
  Proc_7 (10, Int_Glob, &Ptr_Glob->variant.var_1.Int_Comp);
} /* Proc_3 */


void Proc_4 () /* without parameters */
/*******/
    /* executed once */
{
  Boolean Bool_Loc;

  Bool_Loc = Ch_1_Glob == 'A';
  Bool_Glob = Bool_Loc | Bool_Glob;
  Ch_2_Glob = 'B';
} /* Proc_4 */


void Proc_5 () /* without parameters */
/*******/
    /* executed once */
{
  Ch_1_Glob = 'A';
  Bool_Glob = false;
} /* Proc_5 */


        /* Procedure for the assignment of structures,          */
        /* if the C compiler doesn't support this feature       */
#ifdef  NOSTRUCTASSIGN
memcpy (d, s, l)
register char   *d;
register char   *s;
register int    l;
{
        while (l--) *d++ = *s++;
}
#endif

