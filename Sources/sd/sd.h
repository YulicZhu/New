/**
 * @file sd.h
 * @author Yulic_zhu
 * @date Feb 24, 2017
 * @brief ����mcu��sd����ͨ�ţ�����spiЭ�飩
 * 
 * ʵ��Ӳ�������ϣ�ֱ�Ӷ�дsd��block�Ĺ���
 */
#include"spi.h"
#include"pad.h"
#include"mpc5604b.h"
#ifndef SD_H_
#define SD_H_
#define SD_select()        SIU.GPDO[15].B.PDO=0        //QS3�͵�ƽ
#define SD_deselect()      SIU.GPDO[15].B.PDO=1        //QS3�ߵ�ƽ


/**
 * @brief ����spiͨ��ָ�ʵ���ض�Ŀ�ģ����õײ�SPI_Byte��д������
 * 
 * @example SD_send_command(8,0x1aa);
 * @param cmd SPIָ��,ָ���ض����ܣ���	�����λ����ʼ��������ѹ��Χ����д���ݿ�
 * @param arg ָ���ض�������ȱʡ����0
 */
extern uint8_t SD_send_command(uint8_t cmd, uint32_t arg);

/**
 * @brief SD����λ
 * 
 * ʹ�ô˺�����ʼ��sd����������sd����ͨ�ţ����Ҫ��ʼ������ʹ�á�
 * 
 * @example SD_Reset();
 * @return 0 �ɹ�
 * @return 1/2/3 ���ɹ�
 */
extern uint8_t SD_Reset(void);

/**
 * @brief SD��block������
 * 
 * ��ȡ512�ֽ�
 * 
 * @example read_block(0x00, BUFFER)
 * @param sector ����
 * @param buffer ������ָ��
 */
extern uint8_t read_block(uint32_t sector, uint8_t* buffer);

/**
 * @brief SD��blockд����
 * 
 * д��512�ֽ�
 * 
 * @example (write_block(0x1FF,BUFFER)
 * @param sector ����
 * @param buffer ������ָ��
 */
extern uint8_t write_block(uint32_t sector,uint8_t* buffer);

uint8_t SD_write_multiple_block(uint32_t sector, uint8_t n, const uint8_t buffer[][512]);
#endif /* SD_H_ */
