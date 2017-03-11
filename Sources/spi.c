/*
 * spi.c
 *
 *  Created on: Mar 5, 2017
 *      Author: Yulic_zhu
 */

#include "spi.h"
void SPI_Init(void) 
{
	DSPI_0.MCR.R = 0x80013001;    		 //设置DSPI0为主模式，CS信号低有效，禁止FIFO
	DSPI_0.CTAR[0].R = 0x3E0A7727; 		 //配置CTAR[0]，设置为每帧数据为8位，高位在前，波特率为100KHz
	DSPI_0.MCR.B.HALT = 0x0;	    	 //DSPI0处于运行状态
}
/*************************************************************/
/*                    设置SPI时钟为4MHz                      */
/*************************************************************/
void SPI_4M(void) 
{ 
	DSPI_0.MCR.B.HALT = 0x1;	  	    //DSPI0停止运行
	DSPI_0.CTAR[0].R = 0x3E087723; 	    //配置CTAR[0]，设置为每帧数据为8位，高位在前，波特率为4MHz
	DSPI_0.MCR.B.HALT = 0x0;	        //DSPI0处于运行状态
}
uint8_t SPI_Byte(uint8_t value)
{
	uint8_t input;
	DSPI_0.PUSHR.R = 0x08000000|value;   //赋值需要发送的数据	#0x08EOQ位，存疑	
	while(DSPI_0.SR.B.TCF==0)            //等待发送完成
	{}
	DSPI_0.SR.B.TCF=1;                   //清除发送完成标志位
	while(DSPI_0.SR.B.RFDF==0)           //等待接收到数据
	{}
	input=(uint8_t)(DSPI_0.POPR.R);      //读取接收到的数据
	DSPI_0.SR.B.RFDF=1;                  //清除接收标志位

	return(input);    				     //返回接收到的数据
}
