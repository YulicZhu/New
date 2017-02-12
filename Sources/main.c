//���OKӲ��δ���ԣ�LEDӲ������ȫ�ɹ�����·PWM���óɹ������������ת�������ת��OKӲ��δ���ԣ�����̨SD��Ӳ�����Գɹ��������жϳɹ�����ť���ڵ�ѹ�ɹ�
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
		//Measure_Conf();											//����AR�������������ʾ,��x������
		Single_Collection();
	}
}
void Single_Collection(){
	long sys_clock_base,t,ticktock;
	EMIOS_0.CH[16].CCR.B.MODE = 0x00;
	EMIOS_0.CH[16].CCR.B.MODE = 0x13; 							// Modulus Counter(MC),����ģʽ ,external clock*/������������
	STM.CR.B.TEN = 1;											// STM enable and start
	ADC_Enable();
	sys_clock_base=Read_Stm();
	while(file_create(sys_clock_base)){}						//ͨ��ʱ��������ļ�
	LED=0;
	/*Measuring*/
	for(t=0;t<array_size;t++)
	{	while((ticktock=Read_Stm()-sys_clock_base)%7000>10){}	//������ʹ7msһ������;�ݲ�10us
		result[t].ticktock=ticktock;							//ʱ�ӣ��ֶ�ֵ1us
		result[t].volt=ADC.CDR[15].B.CDATA*5000/0x3FF;;			//current_capture();
		result[t].current=ADC.CDR[36].B.CDATA*5000/0x3FF;; 		//volt_capture();
		result[t].counter=(uint32_t)EMIOS_0.CH[16].CCNTR.B.CCNTR;
	}															//ʹ7ms1��
	/*Saving*/
	WRITE_SD(result);
	EMIOS_0.CH[18].CCR.B.MODE = 00;//MS����������
} 
