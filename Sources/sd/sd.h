/**
 * @file sd.h
 * @author Yulic_zhu
 * @date Feb 24, 2017
 * @brief 建立mcu与sd卡的通信（基于spi协议）
 * 
 * 实现硬件层面上，直接读写sd卡block的功能
 */
#include"spi.h"
#include"pad.h"
#include"mpc5604b.h"
#ifndef SD_H_
#define SD_H_
#define SD_select()        SIU.GPDO[15].B.PDO=0        //QS3低电平
#define SD_deselect()      SIU.GPDO[15].B.PDO=1        //QS3高电平


/**
 * @brief 发送spi通信指令，实现特定目的（调用底层SPI_Byte读写函数）
 * 
 * @example SD_send_command(8,0x1aa);
 * @param cmd SPI指令,指代特定功能，如	软件复位、初始化、检测电压范围、读写数据块
 * @param arg 指令特定参数，缺省则填0
 */
extern uint8_t SD_send_command(uint8_t cmd, uint32_t arg);

/**
 * @brief SD卡复位
 * 
 * 使用此函数初始化sd卡，建立与sd卡的通信，务必要初始化才能使用。
 * 
 * @example SD_Reset();
 * @return 0 成功
 * @return 1/2/3 不成功
 */
extern uint8_t SD_Reset(void);

/**
 * @brief SD卡block读操作
 * 
 * 读取512字节
 * 
 * @example read_block(0x00, BUFFER)
 * @param sector 扇区
 * @param buffer 缓冲区指针
 */
extern uint8_t read_block(uint32_t sector, uint8_t* buffer);

/**
 * @brief SD卡block写操作
 * 
 * 写入512字节
 * 
 * @example (write_block(0x1FF,BUFFER)
 * @param sector 扇区
 * @param buffer 缓冲区指针
 */
extern uint8_t write_block(uint32_t sector,uint8_t* buffer);

uint8_t SD_write_multiple_block(uint32_t sector, uint8_t n, const uint8_t buffer[][512]);
#endif /* SD_H_ */
