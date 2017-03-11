/*
 * pad.h
 *
 *  Created on: Mar 5, 2017
 *      Author: Yulic_zhu
 */

#ifndef PAD_H_
#define PAD_H_
typedef enum {
			orange=31,
			blue=30,
			yellow=29,
			blue2=28,
			red=27,
			yellow2=58,//led_color
/*pwm_mc*/	pwm1_pcr=68,
			pwm2_pcr=2,
			encoder_clk_pcr=8,
			timebase_pcr=71,//
/*adc*/ 	AR1_pcr=59,//AR1 ADC D11-GPI[15]
			AR2_pcr=60,//AR2 ADC D12-ANS[4],ch36
			Vmotor1_pcr=48,//Vmotor1 adc D0-GPI[4]
			Vmotor2_pcr=49,//Vmotor2 adc D1-GPI[5]
			VADJ_DIG_pcr=50,//VADJ_SIG adc D2-GPI[6]
			Vcurrent_pcr=51,////VCURRENT adc D3-GPI[7]
}pcrno;


#endif /* PAD_H_ */
