/*
 * WRITE_SD.c
、
 *
 *  Created on: Nov 27, 2016
 *      Author: Yulic_zhu
 */

#include "WRITE_SD.h"
FIL fil;
TCHAR tchar[30];
/*创建文件*/
short file_create(long timestamp){
	sprintf(tchar,"%ld.txt",timestamp);
	if (FR_OK == f_open(&fil, tchar, FA_OPEN_ALWAYS))
	{
		if (FR_OK == f_close(&fil))return 0;
		else return 2;
	}
	else return 1;
}
/*写入采集的数据*/
int WRITE_SD(struct mea_res result[])
{	unsigned short wr;
	char strbuff[60]={"\0"};
	int t;
	if (FR_OK == f_open(&fil, tchar, FA_WRITE)){
		for(t=0;t<array_size;t++)
    	{	sprintf(strbuff,"\r\n%d\t%d\t%d\t%d\t%d",result[t].ticktock,result[t].duty,result[t].volt,(int)(result[t].current*1000),result[t].counter);
    		f_write(&fil, (const void *)&(strbuff), sizeof(strbuff), &wr);	//ADJ_Voltage如何计算
    		f_lseek(&fil,f_size(&fil)); //移动指针位置
    	}
    }
    /*close file*/
    if (FR_OK == f_close(&fil))return 0;
    else return 5;
}


void delay(){
	int t=0xffff;
	for(;t>0;t--);	
}
/*SD卡初始化*/
void init_SD_FatFs(){
	SPI_Init();				 //建立通讯
	SD_deselect();
	while(SD_Reset()!=0)     //初始化SD卡
	{ 	  
		delay();
	}
	SPI_4M(); 
	LED=1;
	FatFs_Init();		//文件系统初始化		
	
}
