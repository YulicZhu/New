//���OK��LEDOK��PWM���óɹ������������ת�������ת��OK������̨SD��Ӳ��OK�������ж�OK����ť���ڵ�ѹOK
#include "MPC5604B.h"
#include "WRITE_SD.h"
#include "MODULE_Init.h"
#include "DIGTUBE_LED.h"
#include "Button_INT.h"
#include "pwm_mc.h"
#include "adc.h"
//void Single_Collection();
struct mea_res result[1024];
int main(void) {
	int t,temp;
	SYSTEM_Init();
	SIU_Init();
	PWM_MC_config();
	ADC_Init();
	ExINT_Init();
	//PIT_INT();//����PWMΪ���Ҳ�
	//init_SD_FatFs();
	
	DIS_NUM=00;
	while(1){
		display(DIS_NUM);
		ask_duty();
		//Single_Collection();
	}
}
/*
void Single_Collection(){
	long sys_clock_base,t,ticktock;
	EMIOS_0.CH[ENCODER_CLK].CCR.B.MODE = 0x00;
	EMIOS_0.CH[ENCODER_CLK].CCR.B.MODE = 0x13; 							// Modulus Counter(MC),����ģʽ ,external clock/������������
	STM.CR.B.TEN = 1;											// STM enable and start
	sys_clock_base=Read_Stm();
	while(file_create(sys_clock_base)){}						//ͨ��ʱ��������ļ�
	LED=0;
	for(t=0;t<array_size;t++)
	{	while((ticktock=Read_Stm()-sys_clock_base)%7000>10){}	//������ʹ7msһ������;�ݲ�10us
		result[t].ticktock=ticktock;							//ʱ�ӣ��ֶ�ֵ1us
		result[t].volt=ADC.CDR[Vcurrent].B.CDATA*5000/0x3FF;			//current_capture();
		result[t].current=ADC.CDR[VADJ_SIG].B.CDATA*5000/0x3FF; 		//volt_capture();
		result[t].counter=(uint32_t)EMIOS_0.CH[ENCODER_CLK].CCNTR.B.CCNTR;
	}															//ʹ7ms1��
	WRITE_SD(result);
	EMIOS_0.CH[ENCODER_CLK].CCR.B.MODE = 00;//MS����������
} 
*/
