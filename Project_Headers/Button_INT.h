/*
 * Button_INT.h
 *
 *  Created on: Mar 5, 2017
 *      Author: Yulic_zhu
 */

#ifndef BUTTON_INT_H_
#define BUTTON_INT_H_

#include "MPC5604B.h"
#include "MODULE_Init.h"
#include "IntcInterrupts.h"
#include "DIGTUBE_LED.h"

#define CLEAR_EIRQ6 (SIU.ISR.B.EIF6 = 1)

void ExINT_Init(void);

void PIT_INT();


#endif /* BUTTON_INT_H_ */
