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
#include "DIGTUBE_LED.h"
typedef enum{
	AR1=36,
	AR2=15,
	Vmotor1=4,
	Vmotor2=5,
	VADJ_SIG=6,
	Vcurrent=7
}ADC_CHn;
#define assert_valid(ADC_CHn)	while(ADC.CDR[ADC_CHn].B.VALID!=1){}
#define ask_POTENTIAL(ADC_CHn,coefficient) (uint16_t)ADC.CDR[ADC_CHn].B.CDATA*5030.0/0x3FF*coefficient
void ADC_Init(void);
#endif /* ADC_H_ */
