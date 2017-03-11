#include "sd/file_handler/file_handle.h"
FATFS fatfs1;
char strbuff[128]={"\0"};
void FatFs_Init(){
	char g_sdcard_status=0;
	TCHAR *path = "0:";
	/* 挂载TF卡文件系统，f_mount很必要 */
	while(g_sdcard_status==0){
	if(FR_OK == f_mount(&fatfs1, path, 1))
	{
	g_sdcard_status=1;
	/* 文件读写测试,可省 */
	g_sdcard_status=test_file_system();
	}
  }
}
short test_file_system()
{
	FIL fil1, fil2, fil3;
	TCHAR *tchar = "TExT.txt";
	unsigned short br;
	unsigned short wr;
	unsigned char test_write_to_TFCard[15] = "Yulic!";
	unsigned char test_read_from_TFCard[15] = "";
//	disk_initialize(0);

	if (FR_OK == f_open(&fil1, tchar, FA_CREATE_ALWAYS))
	{
		if (FR_OK == f_close(&fil1)){}
		else return 2;
	}
	else return 1;
	if (FR_OK == f_open(&fil2, tchar, FA_WRITE))
	{
		if (FR_OK == f_write(&fil2, (const void *)&test_write_to_TFCard, sizeof(test_write_to_TFCard), &wr))
		{
			if(FR_OK == f_close(&fil2)){}
			else return 5;
		}
		else return 4;
	}
	else return 3;

	if (FR_OK == f_open(&fil3, tchar, FA_READ))
	{
		if (FR_OK == f_read(&fil3, (void *)&test_read_from_TFCard, sizeof(test_read_from_TFCard), &br))
		{
			if (FR_OK == f_close(&fil3)){}
			else return 8;
		}
		else return 7;
	}
	else return 6;
	if (test_write_to_TFCard == test_read_from_TFCard)return 0;
	else return 7;
}
