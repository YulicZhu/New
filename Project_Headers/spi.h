/*
 * spi.h
 *
 *  Created on: Mar 5, 2017
 *      Author: Yulic_zhu
 */

#ifndef SPI_H_
#define SPI_H_
#include"mpc5604b.h"
/**
 * @brief 初始化模块(low speed)
 * 
 * 此函数初始化相应的串口，务必要初始化才能使用。
 * 
 * @example SPI_init(void);
 */
void SPI_Init(void);
/**
 * @brief 高速SPI设置
 * 
 * 在spi初始化后，调用此函数设置波特率为4MHz
 * 
 * @example SPI_4M();
 */
void SPI_4M(void);
/**
 * @brief 发送/接受字节数据
 * 
 * 读写同时进行（在每个 Clock 周期内, SPI 设备都会发送并接收一个 bit 大小的数据, 相当于该设备有一个 bit 大小的数据被交换（Data Exchange）了）
 * 需要写数据时传入参数，需要读时读取返回值；
 * @param value 需要发送的数据(一字节)
 * @return 读取的字节
 */
uint8_t SPI_Byte(uint8_t value);

#endif /* SPI_H_ */
