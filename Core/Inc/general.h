/*
 * general.h
 *
 *  Created on: Sep 25, 2023
 *      Author: admin
 */

#ifndef INC_GENERAL_H_
#define INC_GENERAL_H_
#include "main.h"

void gpio_init();
void hrtim_init();
void adc_init();
void dma_init();

uint16_t analog[5];

#define red1      	 GPIOA->ODR&=~0x2;
#define red0      	 GPIOA->ODR|=0x2;

#define green1     	 GPIOB->ODR&=~0x800;
#define green0     	 GPIOB->ODR|=0x800;

#define blue1     	 GPIOB->ODR&=~0x400;
#define blue0     	 GPIOB->ODR|=0x400;

#endif /* INC_GENERAL_H_ */
