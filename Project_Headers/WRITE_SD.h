

#include "MODULE_Init.h"
#ifndef WRITE_SD_H_
#define WRITE_SD_H_
#include "MPC5604B.h"
//#include "SD_hardware.h"
#include "sd/lib/includes.h"
#include "sd/lib/ff.h"
#include "spi.h"
#include "sd/sd.h"
#include "sd/file_handler/file_handle.h"
#include "stdio.h"




#define  LED	SIU.GPDO[76].B.PDO	//��
#define array_size 500

extern struct mea_res result[];

void delay(void);
/*SD����ʼ��*/
void init_SD_FatFs();
/*д��ɼ�������*/
int WRITE_SD(struct mea_res result[]);
/*�����ļ�*/
short file_create(long timestamp);
#endif /* WRITE_SD_H_ */
