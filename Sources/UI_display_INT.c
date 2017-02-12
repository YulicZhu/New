//数码管显示电压
#include "MPC5604B.h"
#include "MODULE_Init.h"
#include "IntcInterrupts.h"
#define CLEAR_EIRQ6 (SIU.ISR.B.EIF6 = 1)
void display(int num);
void display(int num){
	int i,j;
	int bit_sel[4]={10,63,62,76};//A10,D15,D14,E12
	int seg_sel[8]={8,61,6,121,67,3,34,33};	//A8,D13,A6,H9,E3,A3,C2,C1(dp)
	char lcd[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	int val=0,bit;
	for(i=0;i<4;i++){
	  //位选
	  bit=num%10;
	  num/=10;
	  SIU.GPDO[10].B.PDO=(i==0);
	  SIU.GPDO[63].B.PDO=(i==1);
	  SIU.GPDO[62].B.PDO=(i==2);
	  SIU.GPDO[76].B.PDO=(i==3);
	  }
	  //段选
	  for(j=0;j<8;j++){
		if((lcd[bit]>>j)&0x01){
		val=1;
		}
		switch(j){
			case 0:SIU.GPDO[8].B.PDO=val;break;
			case 1:SIU.GPDO[61].B.PDO=val;break;
			case 2:SIU.GPDO[6].B.PDO=val;break;
			case 3:						break;
			case 4:SIU.GPDO[67].B.PDO=val;break;
			case 5:SIU.GPDO[3].B.PDO=val;break;
			case 6:SIU.GPDO[34].B.PDO=val;break;
			case 7:SIU.GPDO[33].B.PDO=val;break;
		}
	}
}

void EIRQ0_handler(void)
{
	CLEAR_EIRQ6;//clear
	display(ADC.CDR[15].B.CDATA*5000/0x3FF);
	//SIU.GPDO[15].B.PDO^=1;
}
void eMIOS_handler(void)
{
	EMIOS_0.CH[5].CSR.B.FLAG=1;//clear
	display(ADC.CDR[36].B.CDATA*5000/0x3FF);
	//SIU.GPDO[15].B.PDO^=1;
	
}
void ExINT_Init(){
	//A5,H10,C3
	INTC_InitINTCInterrupts();
	
	SIU.IRER.B.EIRE6 = 1; // enable EIRQ[6] 
	SIU.IREER.B.IREE6 = 1; // enable RIRQ[6] rising edge trigger
	SIU.PCR[35].R = 0x0103; // SW3,pin C3 input config
	INTC_InstallINTCInterruptHandler(EIRQ0_handler, 41, 2); // install intc handler
	
	//SW1/2,pin A5 input config,即SIU.PCR[5].R = 0x0500;
	SIU.PCR[5].B.PA=1;
	SIU.PCR[5].B.IBE=1;
	SIU.PCR[66].B.PA = 1;	//E2
	SIU.PCR[66].B.IBE = 1;
	//SW2,config channe18,即EMIOS_0.CH[18].CCR.R= 0x00020082
	EMIOS_0.CH[18].CCR.B.FEN=1;
	EMIOS_0.CH[18].CCR.B.EDPOL=1;
	EMIOS_0.CH[18].CCR.B.MODE=0x02;
	//SW1,config channe5,即EMIOS_0.CH[5].CCR.R= 0x00020082;
	EMIOS_0.CH[5].CCR.B.FEN=1;
	EMIOS_0.CH[5].CCR.B.EDPOL=1;
	EMIOS_0.CH[5].CCR.B.MODE=0x02;
	
	INTC_InstallINTCInterruptHandler(eMIOS_handler,143, 3); // install intc handler
	
	INTC.CPR.B.PRI = 0;
}
