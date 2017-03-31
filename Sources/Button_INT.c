/*
 * Button_INT.c
 *
 *  Created on: Mar 5, 2017
 *      Author: Yulic_zhu
 */
#include"Button_INT.h"
#include "pwm_mc.h"
uint16_t tosin[256]={273,280,286,293,299,306,312,318,325,331,338,344,350,356,362,368,374,380,386,392,398,404,409,415,420,425,430,436,441,445,450,455,460,464,468,473,477,481,484,488,492,495,498,502,505,507,510,513,515,517,520,522,523,525,527,528,529,530,531,532,532,533,533,533,533,533,532,532,531,530,529,528,527,525,523,522,520,517,515,513,510,507,505,502,498,495,492,488,484,481,477,473,468,464,460,455,450,445,441,436,430,425,420,415,409,404,398,392,386,380,374,368,362,356,350,344,338,331,325,318,312,306,299,293,286,280,273,267,260,253,247,240,234,227,221,215,208,202,195,189,183,177,171,165,159,153,147,141,135,129,124,118,113,108,103,97,92,88,83,78,73,69,65,60,56,52,49,45,41,38,35,31,28,26,23,20,18,16,13,11,10,8,6,5,4,3,2,1,1,0,0,0,0,0,1,1,2,3,4,5,6,8,10,11,13,16,18,20,23,26,28,31,35,38,41,45,49,52,56,60,65,69,73,78,83,88,92,97,103,108,113,118,124,129,135,141,147,153,159,165,171,177,183,189,195,202,208,215,221,227,234,240,247,253,260,266};
struct mea_res result[array_size];
short status;//标记是否有额外阻尼
void SW3_handler(void)
{
	display(ask_POTENTIAL(Vmotor2,4)-ask_POTENTIAL(Vmotor1,4));
	CLEAR_EIRQ6;//clear
}
void SW1_handler(void)//
{
	Single_Collection();
	DUTY_REGISTER =Timecycle;
	EMIOS_0.CH[5].CSR.B.FLAG=1;//clear
	
}
void SW2_handler(void)
{
	status^=1;
	if(status==0)
		led_off(blue2);
	else
		led_on(blue2);
	EMIOS_0.CH[18].CSR.B.FLAG=1;//clear
}
void ExINT_Init(){
	//A5,E2,C3
	INTC_InitINTCInterrupts();
	
	SIU.IRER.B.EIRE6 = 1; // enable EIRQ[6] 
	SIU.IREER.B.IREE6 = 1; // enable RIRQ[6] rising edge trigger
	SIU.PCR[35].R = 0x0103; // SW3,pin C3 input config
	INTC_InstallINTCInterruptHandler(SW3_handler, 41, 2); // install intc handler
	
	//SW1/2,pin A5 input config,即SIU.PCR[5].R = 0x0500;
	SIU.PCR[5].B.PA=1;
	SIU.PCR[5].B.IBE=1;
	SIU.PCR[66].B.PA = 1;	//E2
	SIU.PCR[66].B.IBE = 1;
	//SW2,config channe18,即EMIOS_0.CH[18].CCR.R= 0x00020082
	EMIOS_0.CH[18].CCR.B.FEN=1;
	EMIOS_0.CH[18].CCR.B.EDPOL=1;
	EMIOS_0.CH[18].CCR.B.MODE=0x02;
	INTC_InstallINTCInterruptHandler(SW2_handler,150, 4);// install intc handler
	//SW1,config channe5,即EMIOS_0.CH[5].CCR.R= 0x00020082;
	EMIOS_0.CH[5].CCR.B.FEN=1;
	EMIOS_0.CH[5].CCR.B.EDPOL=1;
	EMIOS_0.CH[5].CCR.B.MODE=0x02;
	
	INTC_InstallINTCInterruptHandler(SW1_handler,143, 3); // install intc handler
	
	INTC.CPR.B.PRI = 0;
	status=0;//默认无阻尼
}

static void PIT3_isr(void)
{
    //SIU.GPDO[28].R ^= 0x01;
	static int i=0;
	PWM_duty(PWM1,tosin[i]);
	i++;if(i==256)i=0;
    PIT.CH[3].TFLG.B.TIF = 1;
}

void PIT_INT(){
	
	/* MDIS = 0 to enable clock for PITs. */
	/* FRZ = 1 for Timers stopped in debug mode */
	PIT.PITMCR.B.MDIS = 0;
	PIT.PITMCR.B.FRZ = 1;    
	PIT.CH[3].LDVAL.R = 0x15*533;
	/* clear the TIF flag */
	PIT.CH[3].TFLG.B.TIF = 1;
	   	
	/* TIE = 1 for interrupt request enabled */
	/* TEN = 1 for timer active */
	PIT.CH[3].TCTRL.B.TIE = 1;
	PIT.CH[3].TCTRL.B.TEN = 1;
	INTC_InstallINTCInterruptHandler(PIT3_isr,127,1); /* vector127 for PIT3 */
}
void Single_Collection(){
	long sys_clock_base,t,ticktock,vmoter_temp;
	EMIOS_0.CH[ENCODER_CLK].CCR.B.MODE = 0x00;
	EMIOS_0.CH[ENCODER_CLK].CCR.B.MODE = 0x13; 							// Modulus Counter(MC),输入模式 ,external clock*/，启动计数器
	STM.CR.B.TEN = 1;											// STM enable and start
	sys_clock_base=Read_Stm();
	while(file_create(sys_clock_base)){}						//通过时间戳创建文件
	LED=0;
	/*Measuring*/
	
	for(t=0;t<array_size;t++)
	{	
		if(t==100)DUTY_REGISTER =Timecycle*0.4;//set_a_duty
		while((ticktock=Read_Stm())-sys_clock_base<1000){}	//调整，使1ms一个周期
		result[t].ticktock=ticktock;							//时钟，分度值1us
		result[t].duty=(uint16_t)(ask_duty()*1000);
		assert_valid(VADJ_SIG);
		result[t].volt=(uint16_t)(ask_POTENTIAL(VADJ_SIG,3*1.012));			//current_capture();
		assert_valid(Vcurrent);
		result[t].current=ask_POTENTIAL(Vcurrent,1.0/185)-13.75223; 		//volt_capture();
		result[t].counter=(uint32_t)EMIOS_0.CH[ENCODER_CLK].CCNTR.B.CCNTR;
		sys_clock_base=Read_Stm();
	}															//使7ms1个
	/*Saving*/
	WRITE_SD(result,status);
	EMIOS_0.CH[ENCODER_CLK].CCR.B.MODE = 00;//MS计数器清零
} 
