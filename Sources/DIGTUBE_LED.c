//数码管显示电压

#include "DIGTUBE_LED.h"

int DIS_NUM;
void delay0(){
	int t=0xfff;
	for(;t>0;t--);
}
void display(int num){
	int i,j;
	int bit_sel[4]={10,63,62,76};//A10,D15,D14,E12
	int seg_sel[8]={45,61,6,69,67,3,34,36};	//C13!,D13,A6,E5!,E3,A3,C2,C4(dp)!
	char lcd[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
	int val=0,bit;
	for(i=0;i<4;i++){
	  //位选
	  bit=num%10;
	  num/=10;
	  SIU.GPDO[76].B.PDO=(i==0);
	  SIU.GPDO[62].B.PDO=(i==1);
	  SIU.GPDO[63].B.PDO=(i==2);
	  SIU.GPDO[10].B.PDO=(i==3);
//段选
	  for(j=0;j<8;j++){
		val=0;
		if((lcd[bit]>>j)&0x01)val=1;
		switch(j){
			case 0:SIU.GPDO[45].B.PDO=val;break;//A
			case 1:SIU.GPDO[61].B.PDO=val;break;//B!
			case 2:SIU.GPDO[6].B.PDO=val;break;//C!
			case 3:SIU.GPDO[36].B.PDO=val;break;//D
			case 4:SIU.GPDO[69].B.PDO=val;break;//DP
			case 5:SIU.GPDO[3].B.PDO=val;break;//F!
			case 6:SIU.GPDO[34].B.PDO=val;break;//G!
			case 7:SIU.GPDO[67].B.PDO=val;break;//E
		}
	}
	  delay0();
  }
}

