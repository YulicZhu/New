/*
 * WRITE_SD.c
��
 *
 *  Created on: Nov 27, 2016
 *      Author: Yulic_zhu
 */
#include "MPC5604B.h"
#include "SD_hardware.h"
#include "WRITE_SD.h"
#include "includes.h"
#include "ff.h"
#include "stdio.h"
FIL fil;
TCHAR tchar[30];
void init_SD_FatFs(){
	SD_Init();			//����ͨѶ
	LED=1;
	FatFs_Init();		//�ļ�ϵͳ��ʼ��
}
short file_create(long timestamp){
	sprintf(tchar,"%ld.txt",timestamp);
	if (FR_OK == f_open(&fil, tchar, FA_OPEN_ALWAYS))
	{
		if (FR_OK == f_close(&fil))return 0;
		else return 2;
	}
	else return 1;
}
int WRITE_SD(struct mea_res result[])
{	unsigned short wr;
	char strbuff[40]={"\0"};
	int t;
	if (FR_OK == f_open(&fil, tchar, FA_WRITE)){
		for(t=0;t<array_size;t++)
    	{	sprintf(strbuff,"\r\n%d\t%d\t%d\t%d",result[t].ticktock,result[t].volt,result[t].current,result[t].counter);
    		f_write(&fil, (const void *)&(strbuff), sizeof(strbuff), &wr);	
    		f_lseek(&fil,f_size(&fil)); //�ƶ�ָ��λ��
    	}
    }
    /*close file*/
    if (FR_OK == f_close(&fil))return 0;
    else return 5;
}
