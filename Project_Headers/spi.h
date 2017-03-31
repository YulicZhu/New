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
 * @brief ��ʼ��ģ��(low speed)
 * 
 * �˺�����ʼ����Ӧ�Ĵ��ڣ����Ҫ��ʼ������ʹ�á�
 * 
 * @example SPI_init(void);
 */
void SPI_Init(void);
/**
 * @brief ����SPI����
 * 
 * ��spi��ʼ���󣬵��ô˺������ò�����Ϊ4MHz
 * 
 * @example SPI_4M();
 */
void SPI_4M(void);
/**
 * @brief ����/�����ֽ�����
 * 
 * ��дͬʱ���У���ÿ�� Clock ������, SPI �豸���ᷢ�Ͳ�����һ�� bit ��С������, �൱�ڸ��豸��һ�� bit ��С�����ݱ�������Data Exchange���ˣ�
 * ��Ҫд����ʱ�����������Ҫ��ʱ��ȡ����ֵ��
 * @param value ��Ҫ���͵�����(һ�ֽ�)
 * @return ��ȡ���ֽ�
 */
uint8_t SPI_Byte(uint8_t value);

#endif /* SPI_H_ */
