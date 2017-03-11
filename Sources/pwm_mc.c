/*
 * pwm_mc.c
 *
 *  Created on: Mar 5, 2017
 *      Author: Yulic_zhu
 */

#include "pwm_mc.h"

void PWM_MC_config(){
	SIU.PCR[pwm1_pcr].B.PA=01;		//Pwm1 output channel PE4-E0UC[20]		
	SIU.PCR[pwm2_pcr].B.PA=01;		//Pwm2 output channel PA2-E0UC[2]	
	SIU.PCR[encoder_clk_pcr].B.PA=01;				//ENCODER_CLK-Modulus Counter channel input-E0-E0UC[8];
	SIU.PCR[timebase_pcr].B.PA=01;			//Timebase channel	PE7
	
	
	/*配置EMIOS_channel*/;	
	EMIOS_0.UCDIS.B.CHDIS2 = 0;	
	EMIOS_0.UCDIS.B.CHDIS16 = 0;	
	EMIOS_0.UCDIS.B.CHDIS20 = 0;	
	EMIOS_0.UCDIS.B.CHDIS23 = 0;
	/*设置EMIOS模块*/
	EMIOS_0.MCR.B.GPREN=0;		//Disable Global Prescale
	//config timebase channel
	EMIOS_0.CH[Timebase].CCR.B.UCPEN =0;	//Disable UC prescaler of timebase channel
	EMIOS_0.CH[Timebase].CCNTR.B.CCNTR =0;
	EMIOS_0.CH[Timebase].CADR.B.CADR = 533;//30kHZ when MCR.GPRE=0;0x215
	EMIOS_0.CH[Timebase].CCR.B.MODE =022;	//Set channel mode to MC up mode (internal clock)
	EMIOS_0.CH[Timebase].CCR.B.UCPRE=0;	//channel prescaler pass through
	EMIOS_0.CH[Timebase].CCR.B.UCPEN =1;	//Disable UC prescaler of timebase channel
	//config output channel
	EMIOS_0.CH[PWM2].CCR.B.UCPEN=00;
	EMIOS_0.CH[PWM2].CADR.B.CADR =00;
	EMIOS_0.CH[PWM2].CBDR.B.CBDR =0x0;
	EMIOS_0.CH[PWM2].CCR.B.BSL=00;
	EMIOS_0.CH[PWM2].CCR.B.MODE =0140;//set channel mode to OPWMB(only A1 match FLAG)
	EMIOS_0.CH[PWM2].CCR.B.UCPRE=00;	//channel prescaler pass through
	EMIOS_0.CH[PWM2].CCR.B.UCPEN =1;	//Disable UC prescaler of timebase channel
	//
	EMIOS_0.CH[PWM1].CCR.B.UCPEN=00;
	EMIOS_0.CH[PWM1].CADR.B.CADR =00;
	EMIOS_0.CH[PWM1].CBDR.B.CBDR =0x90;
	EMIOS_0.CH[PWM1].CCR.B.BSL=00;
	EMIOS_0.CH[PWM1].CCR.B.MODE =0140;//set channel mode to OPWMB(only A1 match FLAG)
	EMIOS_0.CH[PWM1].CCR.B.UCPRE=00;	//channel prescaler pass through
	EMIOS_0.CH[PWM1].CCR.B.UCPEN =1;	//Disable UC prescaler of timebase channelA
	//config mc counter
	EMIOS_0.CH[ENCODER_CLK].CCR.B.MODE = 0x13; /* Modulus Counter(MC),输入模式 ,external clock*/
	EMIOS_0.CH[ENCODER_CLK].CCR.B.EDPOL=1;
	EMIOS_0.CH[ENCODER_CLK].CCR.B.EDSEL=0;
	EMIOS_0.CH[ENCODER_CLK].CADR.B.CADR =0xffff;

	//使能EMIOS_0全局时钟
	EMIOS_0.MCR.B.GPRE = 0;	    	//Global Prescaler pass through
	EMIOS_0.MCR.B.GPREN = 1;		//Enable Global Prescaler
	EMIOS_0.MCR.B.GTBE = 1;			//Enable Global Timebase	
}

