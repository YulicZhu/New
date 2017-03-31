
#include "sd/sd.h"
uint8_t SD_send_command(uint8_t cmd, uint32_t arg)
{
	uint8_t a,b;
	uint8_t retry=0,crc_default=0x95;
	if(cmd==8)crc_default=0x87;
	else if(cmd==41||cmd==55)crc_default=0x01;
	SPI_Byte(0xff);
	SD_select();

	SPI_Byte(cmd | 0x40);//�ֱ�д������
	SPI_Byte(arg>>24);
	SPI_Byte(arg>>16);
	SPI_Byte(arg>>8);
	SPI_Byte(arg);
	SPI_Byte(crc_default);

	while((a = SPI_Byte(0xff)) == 0xff)//�ȴ���Ӧ��
		if(retry++ > 10) break;//��ʱ�˳�
	if(cmd==8){SPI_Byte(0xff);
	SPI_Byte(0xff);
	SPI_Byte(0xff);
	}
	SD_deselect();

	return a;//����״ֵ̬
}
uint8_t SD_Reset(void)
{
	uint8_t i;
	uint8_t retry;
	uint8_t a = 0x00;

	for(i=0;i<10;i++) SPI_Byte(0xff);	//����74��ʱ�ӣ������!!!

	//SD����λ
	//����CMD0������������ʾ�ɹ�����idle״̬
	for(retry=0; a!=0x01; retry++)
	{
		a = SD_send_command(0, 0);	//��idle����
		if(retry>100)
		{
			return 1;
		}
	}

	SD_send_command(8,0x1aa);


	for(retry=0; a!=0x00&&retry<100; retry++){
		SD_send_command(55,0);
		a = SD_send_command(41,0x40<<24);//����ֵΪ0x01,���ڳ�ʼ�����ظ�����ACMD41��ֱ������ֵR1Ϊ0
		if(retry>100)
		{
			return 2;
		}
	}	
	for(retry=0,a=1; a!=0x00; retry++)
	{
		a = SD_send_command(1, 0);	//��idle����
		if(retry>100)
		{
			return 1;
		}
	}


	a = SD_send_command(59, 0);	//��crc
	a = SD_send_command(16, 512);	//��������С512

	return 0;	//��������
}

uint8_t read_block(uint32_t sector, uint8_t* buffer)
{
	uint8_t a;          
	uint16_t i;
	a = SD_send_command(17, sector);  //������ 	
	if(a != 0x00) return a;

	SD_select();
	//�����ݵĿ�ʼ
	while(SPI_Byte(0xff) != 0xfe)
	{ }

	for(i=0; i<512; i++)              //��512������
	{
		*buffer++ = SPI_Byte(0xff);		//���ÿն�
	}

	SPI_Byte(0xff);              
	SPI_Byte(0xff);  	
	SD_deselect();
	SPI_Byte(0xff);              
	return 0;
} 
uint8_t write_block(uint32_t sector,uint8_t* buffer)
{
	uint8_t a;
	uint16_t i;
	if(sector<1) return 0xff;     //Ϊ�˱���SD������������������
	a = SD_send_command(24, sector);//д����
	if(a != 0x00) return a;

	SD_select();

	SPI_Byte(0xff);
	SPI_Byte(0xff);
	SPI_Byte(0xff);

	SPI_Byte(0xfe);//����ʼ��

	for(i=0; i<512; i++)//��512�ֽ�����
	{
		SPI_Byte(*buffer++);
	}

	SPI_Byte(0xff);
	SPI_Byte(0xff);

	a = SPI_Byte(0xff); 	
	if( (a&0x1f) != 0x05)
	{
		SD_deselect();
		return a;
	}
	//�ȴ�������
	while(!SPI_Byte(0xff))
	{}

	SD_deselect();

	return 0;
} 
uint8_t SD_write_multiple_block(uint32_t sector, uint8_t n, const uint8_t buffer[][512])
{
uint8_t a;
uint16_t i;
uint16_t j;
if(sector<1) return 0xff;     //Ϊ�˱���SD������������������
a = SD_send_command(25, sector);//д����
if(a != 0x00) return a;
SD_select();
SPI_Byte(0xff);
SPI_Byte(0xff);
for(i=0;i<n;i++)
{
	SPI_Byte(0xfc);
	for(j=0; j<512; j++)//��512�ֽ�����
	{
		SPI_Byte(buffer[i][j]);
	}

	SPI_Byte(0xff);
	SPI_Byte(0xff);

	a = SPI_Byte(0xff); 	
	if( (a&0x1f) != 0x05)
	{
		SD_deselect();
		return a;
	}
	//�ȴ�������
	while(!SPI_Byte(0xff))
	{}
	SPI_Byte(0xfb);
	while(!SPI_Byte(0xFF)){}
	SD_deselect();

	return 0;
} 
}
