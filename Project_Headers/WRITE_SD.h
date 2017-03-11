

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




#define  LED	SIU.GPDO[76].B.PDO	//改
#define array_size 500

extern struct mea_res result[];

void delay(void);
/*SD卡初始化*/
void init_SD_FatFs();
/*写入采集的数据*/
int WRITE_SD(struct mea_res result[]);
/*创建文件*/
short file_create(long timestamp);
#endif /* WRITE_SD_H_ */
