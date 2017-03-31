#include "MODULE_Init.h"
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
	/*led2-7initial*/
	SIU.PCR[orange].R = 0x0220;        //B15-LED2;
	led_off(orange);
	SIU.PCR[blue].R = 0x0220;          //B14-LED3;
	led_off(blue);
	SIU.PCR[yellow].R = 0x0220;       //B13-LED4;
	led_off(yellow);
	SIU.PCR[blue2].R = 0x0220;        //B12-LED5;
	led_off(blue2);
	SIU.PCR[red].R = 0x0220;          //B11-LED6;
	led_off(red);
	SIU.PCR[yellow2].R = 0x0220;        //D10-LED7;
	led_off(yellow2);	
	/*digtube��initial*/
	SIU.PCR[10].R = 0x0223; 		// ���ÿ�©���
	SIU.PCR[63].R = 0x0223; 
	SIU.PCR[62].R = 0x0223; 
	SIU.PCR[76].R = 0x0223; 
	
	SIU.PCR[3].R = 0x0223;
	SIU.PCR[6].R = 0x0223;		               				
	SIU.PCR[34].R = 0x0223;					
	SIU.PCR[36].R = 0x0223;
	SIU.PCR[45].R = 0x0223;
	SIU.PCR[61].R = 0x0223;
	SIU.PCR[67].R = 0x0223;
	SIU.PCR[69].R = 0x0223;
	/*SDcard-initial*/
	SIU.PCR[13].R = 0x0604;        //����PA[13]ΪSOUT�ӿ�
	SIU.PCR[12].R = 0x0103;        //����PA[12]ΪSIN�ӿ�
	SIU.PCR[14].R = 0x0604;        //����PA[14]ΪSCK�ӿ�
	SIU.PCR[15].R = 0x0223;        //����PA[15]Ϊ��©�������ΪCS��ʹ���ڲ���������
}
long Read_Stm(){
	//STM.CH[0].CCR.B.CEN = 1;//enable
	return STM.CNT.R;
}
