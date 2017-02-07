//数码管显示电压
#include "MPC5604B.h"
#include "MODULE_Init.h"
void display(int num);
void Show_Number(int num){
	int bit_sel[4]={10,63,62,76};			//A10,D15,D14,E12
	int i,temp=num;
//	ADC_Detection();
	for(i=0;i<4;i++){
		SIU.GPDO[bit_sel[i]].B.PDO=1;
		display(temp%10);
		//delay();
		temp/=10;
	}
}
void display(int num){
	int seg_sel[7]={8,61,6,121,67,3,34};	//A8,D13,A6,H9,E3,A3,C2
	char lcd[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
/*	struct{
		vuint32_t SIU.GPDO[seg_sel[0]].B.PDO:1;
		vuint32_t SIU.GPDO[seg_sel[1]].B.PDO:1;
		vuint32_t SIU.GPDO[seg_sel[2]].B.PDO:1;
		vuint32_t SIU.GPDO[seg_sel[3]].B.PDO:1;
		vuint32_t SIU.GPDO[seg_sel[4]].B.PDO:1;
		vuint32_t SIU.GPDO[seg_sel[5]].B.PDO:1;
		vuint32_t SIU.GPDO[seg_sel[6]].B.PDO:1;
	}seg_reg;
	seg_reg=lcd[num];
	//位与；union
*/
}
