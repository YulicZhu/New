/*
 * DIGTUBE_LED.h
 *
 *  Created on: Mar 5, 2017
 *      Author: Yulic_zhu
 */

#ifndef DIGTUBE_LED_H_
#define DIGTUBE_LED_H_
#include "pad.h"
#include "MPC5604B.h"
#include "MODULE_Init.h"
#define led_on(color) SIU.GPDO[color].B.PDO=0;
#define led_off(color) SIU.GPDO[color].B.PDO=1;
void display(float num);

extern float DIS_NUM;


#endif /* DIGTUBE_LED_H_ */
