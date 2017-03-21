/*
 * adc.c
 *
 *  Created on: Mar 5, 2017
 *      Author: Yulic_zhu
 */
#include"adc.h"

void ADC_Init(void) {
//	short adc_result_1,adc_result_2;
	ADC.MCR.B.MODE=1;//scan mode
	ADC.MCR.B.PWDN=0;
	
	SIU.PCR[AR1_pcr].B.APC=1;		//AR1 ADC D11-GPI[15]
	SIU.PCR[AR2_pcr].B.APC=1;		//AR2 ADC D12-ANS[4],ch36
	SIU.PCR[VADJ_DIG_pcr].B.APC=1;	//VADJ_SIG adc D2-GPI[6]
	SIU.PCR[Vcurrent_pcr].B.APC=1;	//VCURRENT adc D3-GPI[7]
	/*Enable normal sampling*/
	ADC.NCMR[0].B.CH15 = 1;			
	ADC.NCMR[1].B.CH4 = 1;			//ANS[4],ch36
	ADC.NCMR[0].B.CH6 = 1;	
	ADC.NCMR[0].B.CH7 = 1;	

	ADC.MCR.B.NSTART =1;			//start

 }

	
