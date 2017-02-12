#include "MPC5604B.h"
#include "Macro.h"
void SYSTEM_Init(void)
{
	short sys_clk_select_status;

	ME.RUNPC[0].B.RUN0 = 1;			//外设运行配置0:RUN0启用
	ME.MCTL.R = 0x40005AF0;			//进入RUN0模式
	ME.MCTL.R = 0x4000A50F;
	while(ME.GS.B.S_MTRANS){}

	sys_clk_select_status = CGM.SC_SS.B.SELSTAT;

	if(sys_clk_select_status!=0){	//assert sysclk is 16MHZ
		while(1);
	}
	// SIUL: 选择 ME.RUNPC[0]的配置  
	ME.PCTL[68].R = 0x00;             
	// DSPI0: 选择 ME.RUNPC[0]的配置  
	ME.PCTL[4].R = 0x00;    
	/*stm设置*/
	STM.CR.B.CPS=0xf;//1MHz;
}
void SIU_Init(void)
{
	//switch-external_interupt，见ExINT_Init();
	/*Clock&pwm*/
	SIU.PCR[2].B.PA=01;				//Pwm2 output channel PA2-E0UC[2]
	SIU.PCR[68].B.PA=01;			//Pwm1 output channel PE4-E0UC[20]
	SIU.PCR[64].B.PA=01;			//ENCODER_CLK-Modulus Counter channel input-E0-E0UC[16];
	SIU.PCR[71].B.PA=01;			//Timebase channel	PE7
	
	/*ADC-initial*/
	SIU.PCR[48].B.APC=1;//Vmotor1 adc D0-GPI[4]
	SIU.PCR[49].B.APC=1;//Vmotor2 adc D1-GPI[5]
	SIU.PCR[50].B.APC=1;//VADJ_SIG adc D2-GPI[6]
	SIU.PCR[51].B.APC=1;//VCURRENT adc D3-GPI[7]
	
	SIU.PCR[59].B.APC=1;//AR1 ADC D11-GPI[15]
	SIU.PCR[60].B.APC=1;//AR2 ADC D12-ANS[4]
	/*led2-7initial*/
	SIU.PCR[31].R = 0x0220;        //B15-LED2
	SIU.PCR[30].R = 0x0220;        //B14-LED3
	SIU.PCR[29].R = 0x0220;        //B13-LED4
	SIU.PCR[28].R = 0x0220;        //B12-LED5
	SIU.PCR[27].R = 0x0220;        //B11-LED6
	SIU.PCR[58].R = 0x0220;        //D10-LED7
	/*oled—initial*/
	
	SIU.PCR[3].R = 0x0220;
	SIU.PCR[6].R = 0x0220;		
	SIU.PCR[8].R = 0x0220;               
	SIU.PCR[10].R = 0x0220;               // 设置开漏输出
	SIU.PCR[34].R = 0x0220;		
	SIU.PCR[36].R = 0x0220;
	SIU.PCR[61].R = 0x0220;
	SIU.PCR[62].R = 0x0220;               
	SIU.PCR[63].R = 0x0220;     
	SIU.PCR[67].R = 0x0220;
	SIU.PCR[69].R = 0x0220;
	SIU.PCR[76].R = 0x0220; 
	

	/*SDcard-initial*/
	SIU.PCR[13].R = 0x0604;        //设置PA[13]为SOUT接口
	SIU.PCR[12].R = 0x0103;        //设置PA[12]为SIN接口
	SIU.PCR[14].R = 0x0604;        //设置PA[14]为SCK接口
	SIU.PCR[15].R = 0x0223;        //设置PA[15]为开漏输出，作为CS，使能内部上拉电阻
}
void EMIOS_Cnf(){
	/*配置端口*/;	
	EMIOS_0.UCDIS.B.CHDIS2 = 0;	
	EMIOS_0.UCDIS.B.CHDIS16 = 0;	
	EMIOS_0.UCDIS.B.CHDIS20 = 0;	
	EMIOS_0.UCDIS.B.CHDIS23 = 0;
	/*设置EMIOS模块*/
	EMIOS_0.MCR.B.GPREN=0;		//Disable Global Prescale
	//config timebase channel
	EMIOS_0.CH[23].CCR.B.UCPEN =0;	//Disable UC prescaler of timebase channel
	EMIOS_0.CH[23].CCNTR.B.CCNTR =0;
	EMIOS_0.CH[23].CADR.B.CADR = 533;//30kHZ when MCR.GPRE=0
	EMIOS_0.CH[23].CCR.B.MODE =022;	//Set channel mode to MC up mode (internal clock)
	EMIOS_0.CH[23].CCR.B.UCPRE=0;	//channel prescaler pass through
	EMIOS_0.CH[23].CCR.B.UCPEN =1;	//Disable UC prescaler of timebase channel
	//config output channel
	EMIOS_0.CH[2].CCR.B.UCPEN=00;
	EMIOS_0.CH[2].CADR.B.CADR =00;
	EMIOS_0.CH[2].CBDR.B.CBDR =0x900;
	EMIOS_0.CH[2].CCR.B.BSL=00;
	EMIOS_0.CH[2].CCR.B.MODE =0140;//set channel mode to OPWMB(only A1 match FLAG)
	EMIOS_0.CH[2].CCR.B.UCPRE=00;	//channel prescaler pass through
	EMIOS_0.CH[2].CCR.B.UCPEN =1;	//Disable UC prescaler of timebase channel
	//
	EMIOS_0.CH[20].CCR.B.UCPEN=00;
	EMIOS_0.CH[20].CADR.B.CADR =00;
	EMIOS_0.CH[20].CBDR.B.CBDR =0x100;
	EMIOS_0.CH[20].CCR.B.BSL=00;
	EMIOS_0.CH[20].CCR.B.MODE =0140;//set channel mode to OPWMB(only A1 match FLAG)
	EMIOS_0.CH[20].CCR.B.UCPRE=00;	//channel prescaler pass through
	EMIOS_0.CH[20].CCR.B.UCPEN =1;	//Disable UC prescaler of timebase channelA
	//config mc counter
	EMIOS_0.CH[16].CCR.B.MODE = 0x13; /* Modulus Counter(MC),输入模式 ,external clock*/
	EMIOS_0.CH[16].CCR.B.EDPOL=1;
	EMIOS_0.CH[16].CCR.B.EDSEL=0;
	EMIOS_0.CH[16].CADR.B.CADR =0xffff;

	//使能EMIOS_0全局时钟
	EMIOS_0.MCR.B.GPRE = 0;	    	//Global Prescaler pass through
	EMIOS_0.MCR.B.GPREN = 1;		//Enable Global Prescaler
	EMIOS_0.MCR.B.GTBE = 1;			//Enable Global Timebase
}
long Read_Stm(){
	//STM.CH[0].CCR.B.CEN = 1;//enable
	return STM.CNT.R;
}
void ADC_Init(void) {
	short adc_result_1,adc_result_2;
	//配置ADC,即ADC.MCR.R = 0x20000000;
	ADC.MCR.B.MODE=1;//scan mode
	ADC.MCR.B.PWDN=0;
	
	SIU.PCR[59].B.APC=1;//AR1 ADC D11-GPI[15]
	SIU.PCR[60].B.APC=1;//AR2 ADC D12-ANS[4],ch36

	ADC.NCMR[0].B.CH15 = 1;			//enable normal sampling
	ADC.NCMR[1].B.CH4 = 1;			//ch36	
//  for (;;) {
	  ADC.MCR.B.NSTART =1;			//start
	  while(ADC.CDR[15].B.VALID!=1){}
	  while(ADC.CDR[36].B.VALID!=1){}
	  adc_result_1=(short)ADC.CDR[15].B.CDATA*5000/0x3FF;//AR1
	  adc_result_2=(short)ADC.CDR[36].B.CDATA*5000/0x3FF;//AR2
//  }
 }
void ADC_Enable(){
	ADC.NCMR[0].B.CH4 = 1;
	ADC.NCMR[0].B.CH5 = 1;
	ADC.NCMR[0].B.CH6 = 1;
	ADC.NCMR[0].B.CH7 = 1;
}
uint16_t ADC_Volt(){
	ADC.MCR.B.NSTART =1;							//start
	while(ADC.CDR[6].B.VALID!=1){}
	return (uint16_t)ADC.CDR[6].B.CDATA*5000/0x3FF;	//volt_val
}
uint16_t ADC_Vcurrent(){
	ADC.MCR.B.NSTART =1;							//start
	while(ADC.CDR[7].B.VALID!=1){}
	return (uint16_t)ADC.CDR[7].B.CDATA*5000/0x3FF;	//volt_val
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
void Measure_Conf(){//配置外部参数
	//pwm
}
