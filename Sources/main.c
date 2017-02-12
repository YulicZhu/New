//光编OK硬件未测试，LED硬件不完全成功，两路PWM配置成功但电机不能运转，数码管转义OK硬件未测试，测试台SD卡硬件测试成功，按键中断成功，旋钮调节电压成功
#include "MPC5604B.h"
#include "WRITE_SD.h"
#include "MODULE_Init.h"
#include "UI_display_INT.h"
void Single_Collection();
struct mea_res result[1024];
int main(void) {
	int t;
	SYSTEM_Init();
	SIU_Init();
	EMIOS_Cnf();
	ADC_Init();//AR1,AR2
	ExINT_Init();
	init_SD_FatFs();
	for(t=0;t<4;t++){
		//Measure_Conf();											//调整AR，并用数码管显示,按x键继续
		Single_Collection();
	}
}
void Single_Collection(){
	long sys_clock_base,t,ticktock;
	EMIOS_0.CH[16].CCR.B.MODE = 0x00;
	EMIOS_0.CH[16].CCR.B.MODE = 0x13; 							// Modulus Counter(MC),输入模式 ,external clock*/，启动计数器
	STM.CR.B.TEN = 1;											// STM enable and start
	ADC_Enable();
	sys_clock_base=Read_Stm();
	while(file_create(sys_clock_base)){}						//通过时间戳创建文件
	LED=0;
	/*Measuring*/
	for(t=0;t<array_size;t++)
	{	while((ticktock=Read_Stm()-sys_clock_base)%7000>10){}	//调整，使7ms一个周期;容差10us
		result[t].ticktock=ticktock;							//时钟，分度值1us
		result[t].volt=ADC.CDR[15].B.CDATA*5000/0x3FF;;			//current_capture();
		result[t].current=ADC.CDR[36].B.CDATA*5000/0x3FF;; 		//volt_capture();
		result[t].counter=(uint32_t)EMIOS_0.CH[16].CCNTR.B.CCNTR;
	}															//使7ms1个
	/*Saving*/
	WRITE_SD(result);
	EMIOS_0.CH[18].CCR.B.MODE = 00;//MS计数器清零
} 
