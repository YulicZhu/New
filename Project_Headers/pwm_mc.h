/*
 * pwm_mc.h
 *
 *  Created on: Mar 5, 2017
 *      Author: Yulic_zhu
 */

#ifndef PWM_MC_H_
#define PWM_MC_H_
#include "MPC5604B.h"
#include "pad.h"

#define PWM_duty(pwm,value) EMIOS_0.CH[pwm].CBDR.B.CBDR =value



typedef enum{
	PWM2=2,
	PWM1=20,
	ENCODER_CLK=8,
	Timebase=23
}PWM_CHn;
void PWM_MC_config();
#endif /* PWM_MC_H_ */
