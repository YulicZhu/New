//���OK��LEDOK��PWM���óɹ������������ת�������ת��OK������̨SD��Ӳ��OK�������ж�OK����ť���ڵ�ѹOK
#include "MPC5604B.h"
#include "WRITE_SD.h"
#include "MODULE_Init.h"
#include "DIGTUBE_LED.h"
#include "Button_INT.h"
#include "pwm_mc.h"
#include "adc.h"
//void Single_Collection();
int main(void) {
	int t,temp;
	SYSTEM_Init();
	SIU_Init();
	PWM_MC_config();
	ADC_Init();
	ExINT_Init();
	//PIT_INT();//����PWMΪ���Ҳ�
	//init_SD_FatFs();
	
	while(1){
		//display(ask_duty());
		display((uint16_t)EMIOS_0.CH[ENCODER_CLK].CCNTR.B.CCNTR);
	}
}
