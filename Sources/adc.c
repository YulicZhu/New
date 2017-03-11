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
	SIU.PCR[Vmotor1_pcr].B.APC=1;	//Vmotor1 adc D0-GPI[4]
	SIU.PCR[Vmotor2_pcr].B.APC=1;	//Vmotor2 adc D1-GPI[5]
	SIU.PCR[VADJ_DIG_pcr].B.APC=1;	//VADJ_SIG adc D2-GPI[6]
	SIU.PCR[Vcurrent_pcr].B.APC=1;	//VCURRENT adc D3-GPI[7]
	/*Enable normal sampling*/
	ADC.NCMR[0].B.CH15 = 1;			
	ADC.NCMR[1].B.CH4 = 1;			//ANS[4],ch36
	ADC.NCMR[0].B.CH4 = 1;	
	ADC.NCMR[0].B.CH5 = 1;	
	ADC.NCMR[0].B.CH6 = 1;	
	ADC.NCMR[0].B.CH7 = 1;	

	ADC.MCR.B.NSTART =1;			//start
/*	while(ADC.CDR[15].B.VALID!=1){}
	while(ADC.CDR[36].B.VALID!=1){}
	adc_result_1=(short)ADC.CDR[15].B.CDATA*5000/0x3FF;//AR1
	adc_result_2=(short)ADC.CDR[36].B.CDATA*5000/0x3FF;//AR2
	*/								//test
 }

/*
uint16_t ADC_Volt(){
	ADC.MCR.B.NSTART =1;							//start
	while(ADC.CDR[VADJ_SIG].B.VALID!=1){}
	return (uint16_t)ADC.CDR[6].B.CDATA*5000/0x3FF;	//volt_val
}
uint16_t ADC_Vcurrent(){
	ADC.MCR.B.NSTART =1;							//start
	while(ADC.CDR[Vcurrent].B.VALID!=1){}
	return (uint16_t)ADC.CDR[Vcurrent].B.CDATA*5000/0x3FF;	//volt_val
}
uint16_t ADC_Detection(){
	uint16_t left,right,temp;
	ADC.MCR.B.NSTART =1;							//start
	
	while(ADC.CDR[4].B.VALID!=1){}
	left=(uint16_t)ADC.CDR[4].B.CDATA*5000/0x3FF;	//volt_val
	while(ADC.CDR[5].B.VALID!=1){}
	right=(uint16_t)ADC.CDR[5].B.CDATA*5000/0x3FF;	//volt_val
	if(right>left){temp=left;left=right;right=temp;}
	return left-right;
}
*/
