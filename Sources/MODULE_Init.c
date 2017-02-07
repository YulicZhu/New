#include "MPC5604B.h"
#include "Macro.h"
void SYSTEM_Init(void)
{
	short sys_clk_select_status;

	ME.RUNPC[0].B.RUN0 = 1;			//������������0:RUN0����
	ME.MCTL.R = 0x40005AF0;			//����RUN0ģʽ
	ME.MCTL.R = 0x4000A50F;
	while(ME.GS.B.S_MTRANS){}

	sys_clk_select_status = CGM.SC_SS.B.SELSTAT;

	if(sys_clk_select_status!=0){	//assert sysclk is 16MHZ
		while(1);
	}
	// SIUL: ѡ�� ME.RUNPC[0]������  
	ME.PCTL[68].R = 0x00;             
	// DSPI0: ѡ�� ME.RUNPC[0]������  
	ME.PCTL[4].R = 0x00;    
	/*stm����*/
	STM.CR.B.CPS=0xf;//1MHz;
}
void SIU_Init(void)
{
	//switch-external_interupt
	SIU.PCR[35].B.IBE = 1;	//C3
	SIU.PCR[5].B.IBE = 1;	//A5
	SIU.PCR[122].B.IBE = 1;	//H10
	SIU.IREER.B.IREE0 = 1;
	SIU.IRER.B.EIRE0 = 1;

	//INTC_InstallINTCInterruptHandler(Intc_hadnler, 41, 2);

	/*Clock&pwm*/
	SIU.PCR[2].B.PA=01;				//Pwm2 output channel PA2-E0UC[2]
	SIU.PCR[68].B.PA=01;			//Pwm1 output channel PE4-E0UC[20]
	SIU.PCR[66].B.PA=01;			//ENCODER_CLK-Modulus Counter channel input-E2-E0UC[18];
	//	SIU.PCR[71].B.PA=01;//������			//Timebase channel	PE7
	SIU.PCR[64].B.PA=01;				//Timebase channel-16	PE0
	SIU.PCR[0].B.PA=01;					//Timebase channel-0

	/*ADC-initial*/
/*	SIU.PCR[70].B.APC=1;//Vmotor1 adc E6-MA[1]
	SIU.PCR[71].B.APC=1;//Vmotor2 adc E7-MA[0]		//ע����Ų���PAλ��alternate function04
	SIU.PCR[69].B.APC=1;//VADJ_SIG E5-MA[2]
	SIU.PCR[42].B.APC=1;//VCURRENT C10-MA[1]		//MA-����������ţ�ADC���;;�ظ���
*/
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

	/*SDcard-initial*/
	SIU.PCR[13].R = 0x0604;        //����PA[13]ΪSOUT�ӿ�
	SIU.PCR[12].R = 0x0103;        //����PA[12]ΪSIN�ӿ�
	SIU.PCR[14].R = 0x0604;        //����PA[14]ΪSCK�ӿ�
	SIU.PCR[15].R = 0x0223;        //����PA[15]Ϊ��©�������ΪCS��ʹ���ڲ���������
}
void EMIOS_Cnf(){
	/*���ö˿�*/
	EMIOS_0.UCDIS.B.CHDIS0 = 0;	
	EMIOS_0.UCDIS.B.CHDIS16 = 0;	
	EMIOS_0.UCDIS.B.CHDIS2 = 0;
	EMIOS_0.UCDIS.B.CHDIS18 = 0;	
	EMIOS_0.UCDIS.B.CHDIS20 = 0;	
	/*����EMIOSģ��*/
	EMIOS_0.MCR.B.GPREN= 0;			//Disable Global Prescale

	//config timebase channel
	EMIOS_0.CH[0].CCR.B.UCPEN =0;	//Disable UC prescaler of timebase channel
	EMIOS_0.CH[0].CCNTR.B.CCNTR =0;
	EMIOS_0.CH[0].CADR.B.CADR = 533;//30kHZ when MCR.GPRE=0
	EMIOS_0.CH[0].CCR.B.MODE =022;	//Set channel mode to MC up mode (internal clock)
	EMIOS_0.CH[0].CCR.B.UCPRE=0;	//channel prescaler pass through
	EMIOS_0.CH[0].CCR.B.UCPEN =1;	//Disable UC prescaler of timebase channel
	//	
	EMIOS_0.CH[16].CCR.B.UCPEN =0;	//Disable UC prescaler of timebase channel
	EMIOS_0.CH[16].CCNTR.B.CCNTR =0;
	EMIOS_0.CH[16].CADR.B.CADR = 533;//30kHZ when MCR.GPRE=0
	EMIOS_0.CH[16].CCR.B.MODE =022;	//Set channel mode to MC up mode (internal clock)
	EMIOS_0.CH[16].CCR.B.UCPRE=0;	//channel prescaler pass through
	EMIOS_0.CH[16].CCR.B.UCPEN =1;	//Disable UC prescaler of timebase channel

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
	EMIOS_0.UCDIS.B.CHDIS8 = 0;
	EMIOS_0.CH[18].CCR.B.MODE = 0x13; /* Modulus Counter(MC),����ģʽ ,external clock*/
	EMIOS_0.CH[18].CCR.B.EDPOL=1;
	EMIOS_0.CH[18].CCR.B.EDSEL=0;
	EMIOS_0.CH[18].CADR.B.CADR =0xffff;

	//ʹ��EMIOS_0ȫ��ʱ��
	EMIOS_0.MCR.B.GPRE = 0;	    	//Global Prescaler pass through
	EMIOS_0.MCR.B.GPREN = 1;		//Enable Global Prescaler
	EMIOS_0.MCR.B.GTBE = 1;			//Enable Global Timebase
		
}
long Read_Stm(){
	//STM.CH[0].CCR.B.CEN = 1;//enable
	return STM.CNT.R;
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
void Measure_Conf(){//�����ⲿ����
	//sin_gen[500];
	
	//�ж�
}
//PWM,�жϸ���ռ�ձȣ�
//ADC���������ԭ��
//LED���ӿڲ�����lcd���
