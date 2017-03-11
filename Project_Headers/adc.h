/*
 * adc.h
 *
 *  Created on: Mar 5, 2017
 *      Author: Yulic_zhu
 */

#ifndef ADC_H_
#define ADC_H_
#include "MPC5604B.h"
#include "pad.h"
typedef enum{
	AR1=15,
	AR2=36,
	Vmotor1=4,
	Vmotor2=5,
	VADJ_SIG=6,
	Vcurrent=7
}ADC_CHn;
void ADC_Init(void);
#endif /* ADC_H_ */
