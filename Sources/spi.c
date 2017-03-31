/*
 * spi.c
 *
 *  Created on: Mar 5, 2017
 *      Author: Yulic_zhu
 */

#include "spi.h"
void SPI_Init(void) 
{
	DSPI_0.MCR.R = 0x80013001;    		 //����DSPI0Ϊ��ģʽ��CS�źŵ���Ч����ֹFIFO
	DSPI_0.CTAR[0].R = 0x3E0A7727; 		 //����CTAR[0]������Ϊÿ֡����Ϊ8λ����λ��ǰ��������Ϊ100KHz
	DSPI_0.MCR.B.HALT = 0x0;	    	 //DSPI0��������״̬
}
/*************************************************************/
/*                    ����SPIʱ��Ϊ4MHz                      */
/*************************************************************/
void SPI_4M(void) 
{ 
	DSPI_0.MCR.B.HALT = 0x1;	  	    //DSPI0ֹͣ����
	DSPI_0.CTAR[0].R = 0x3E087723; 	    //����CTAR[0]������Ϊÿ֡����Ϊ8λ����λ��ǰ��������Ϊ4MHz
	DSPI_0.MCR.B.HALT = 0x0;	        //DSPI0��������״̬
}
uint8_t SPI_Byte(uint8_t value)
{
	uint8_t input;
	DSPI_0.PUSHR.R = 0x08000000|value;   //��ֵ��Ҫ���͵�����	#0x08EOQλ������	
	while(DSPI_0.SR.B.TCF==0)            //�ȴ��������
	{}
	DSPI_0.SR.B.TCF=1;                   //���������ɱ�־λ
	while(DSPI_0.SR.B.RFDF==0)           //�ȴ����յ�����
	{}
	input=(uint8_t)(DSPI_0.POPR.R);      //��ȡ���յ�������
	DSPI_0.SR.B.RFDF=1;                  //������ձ�־λ

	return(input);    				     //���ؽ��յ�������
}
