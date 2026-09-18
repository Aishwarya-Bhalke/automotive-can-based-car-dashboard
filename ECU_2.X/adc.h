/* 
 * File:   adc.h
 * Author: Hp
 *
 * Created on 7 October, 2025, 5:44 PM
 */

#ifndef ADC_H
#define	ADC_H

#define CHANNEL4		0x04

void init_adc(void);
unsigned short read_adc(unsigned char channel);

#endif	/* ADC_H */

