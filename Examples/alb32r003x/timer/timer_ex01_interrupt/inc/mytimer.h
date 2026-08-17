/*
 * mytimer.h
 *
 *  Created on: Feb 20, 2026
 *      Author: huye
 */

#ifndef INC_MYTIMER_H_
#define INC_MYTIMER_H_


#define TEST_GPIO_PIN     (0)           //!< Test GPIO pin number
#define TIMER_PERIOD      (35000000)    //!< Timer period value
#define MY_TIMER_BASE     TIMER1_BASE   //!< Timer base
#define MY_TIMER_CHANNEL  0             //!< Timer channel number
#define MY_TIMER_IRQ      TIMER1_C1_IRQn

//#define  USE_HARD_SP


#endif /* INC_MYTIMER_H_ */
