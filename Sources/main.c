//光编OK，LEDOK，PWM配置成功但电机不能运转，数码管转义OK，测试台SD卡硬件OK，按键中断OK，旋钮调节电压OK
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
	//PIT_INT();//设置PWM为正弦波
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
	EMIOS_0.CH[ENCODER_CLK].CCR.B.MODE = 0x13; 							// Modulus Counter(MC),输入模式 ,external clock/，启动计数器
	STM.CR.B.TEN = 1;											// STM enable and start
	sys_clock_base=Read_Stm();
	while(file_create(sys_clock_base)){}						//通过时间戳创建文件
	LED=0;
	for(t=0;t<array_size;t++)
	{	while((ticktock=Read_Stm()-sys_clock_base)%7000>10){}	//调整，使7ms一个周期;容差10us
		result[t].ticktock=ticktock;							//时钟，分度值1us
		result[t].volt=ADC.CDR[Vcurrent].B.CDATA*5000/0x3FF;			//current_capture();
		result[t].current=ADC.CDR[VADJ_SIG].B.CDATA*5000/0x3FF; 		//volt_capture();
		result[t].counter=(uint32_t)EMIOS_0.CH[ENCODER_CLK].CCNTR.B.CCNTR;
	}															//使7ms1个
	WRITE_SD(result);
	EMIOS_0.CH[ENCODER_CLK].CCR.B.MODE = 00;//MS计数器清零
} 
*/
