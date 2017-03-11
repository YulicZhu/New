/*
 * MODULE_Init.h

 *
 *  Created on: Nov 27, 2016
 *      Author: Yulic_zhu
 */

#ifndef MODULE_INIT_H_
#define MODULE_INIT_H_
//#include"typedefs.h"
#include "MPC5604B.h"
#include "Macro.h"
#include "DIGTUBE_LED.h"
struct mea_res{
	uint32_t ticktock;
	uint16_t volt;
	uint16_t current;
	uint32_t counter;
};						 		//结构体的声明，不能在.h中定义结构体
void SYSTEM_Init();
void SIU_Init();
long Read_Stm();

#endif /* MODULE_INIT_H_ */
