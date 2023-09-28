/*
 * general.c
 *
 *  Created on: Sep 25, 2023
 *      Author: admin
 */


#include "general.h"

void gpio_init()
{
	RCC->AHBENR|= RCC_AHBENR_GPIOAEN
			 |RCC_AHBENR_GPIOBEN
			 |RCC_AHBENR_GPIOCEN
			 |RCC_AHBENR_GPIOFEN
				;

	GPIOA->MODER = 0x3<<2*0
				|0x1<<2*1
				|0x2<<2*2
				|0x2<<2*3
				|0x3<<2*4
				|0x3<<2*5
				|0x3<<2*6
				|0x3<<2*7
				|0x2<<2*8
				|0x2<<2*9
				|0x2<<2*10
				|0x2<<2*11
				|0x2<<2*12
				|0x2<<2*13
				|0x2<<2*14
				|0x2<<2*15
				;

	GPIOA->OSPEEDR = 0xfffffff;

	GPIOA->AFR[0]=0x0<<4*0
				|0x0<<4*1
				|0x7<<4*2
				|0x7<<4*3
				|0x0<<4*4
				|0x0<<4*5
				|0x0<<4*6
				|0x0<<4*7
				;

	GPIOA->AFR[1]=0xd<<4*0
				|0xd<<4*1
				|0xd<<4*2
				|0xd<<4*3
				|0xd<<4*4
				|0x0<<4*5
				|0x0<<4*6
				|0xd<<4*7
				;

	GPIOB->MODER = 0x3<<2*0
				|0x3<<2*1
				|0x3<<2*2
				|0x2<<2*3
				|0x3<<2*4
				|0x3<<2*5
				|0x3<<2*6
				|0x3<<2*7
				|0x3<<2*8
				|0x3<<2*9
				|0x1<<2*10
				|0x1<<2*11
				|0x2<<2*12
				|0x2<<2*13
				|0x2<<2*14
				|0x2<<2*15
				;

	GPIOB->OSPEEDR = 0xfffffff;

	GPIOB->AFR[0]=0
				;

	GPIOB->AFR[1]=0x0<<4*0
				|0x0<<4*1
				|0x0<<4*2
				|0x0<<4*3
				|0xd<<4*4
				|0xd<<4*5
				|0xd<<4*6
				|0xd<<4*7
				;

	GPIOC->MODER =   0x3<<2*0
					|0x3<<2*1
					|0x3<<2*2
					|0x3<<2*3
					|0x3<<2*4
					|0x3<<2*5
					|0x0<<2*6
					|0x0<<2*7
					|0x0<<2*8
					|0x0<<2*9
					|0x2<<2*10
					|0x2<<2*11
					|0x0<<2*12
					|0x0<<2*13
					|0x0<<2*14
					|0x0<<2*15
					;

	GPIOC->OSPEEDR = 0xfffffff;

	GPIOC->AFR[0]=0x0
				;

	GPIOC->AFR[1]=0x0<<4*0
				|0x0<<4*1
				|0x7<<4*2
				|0x7<<4*3
				|0x0<<4*4
				|0x0<<4*5
				|0x0<<4*6
				|0x0<<4*7
				;

}

void hrtim_init()
{
	__HAL_RCC_HRTIM1_CONFIG(RCC_HRTIM1CLK_PLLCLK);
	__HRTIM1_CLK_ENABLE();

	//RCC->APB2ENR|=RCC_APB2ENR_HRTIM1EN;

	/* DLL calibration: periodic calibration enabled, period set to 14μs */
	HRTIM1->sCommonRegs.DLLCR = HRTIM_CALIBRATIONRATE_14| HRTIM_DLLCR_CALEN;
	/* Check DLL end of calibration flag */
	while(HRTIM1->sCommonRegs.ISR & HRTIM_IT_DLLRDY == RESET);

	HRTIM1->sCommonRegs.OENR = HRTIM_OENR_TD2OEN; /* Enable TD2 output */

}

void adc_init()
{
	__ADC1_CLK_ENABLE();

	ADC1->SQR1=0x5<<ADC_SQR1_L_Pos
			|0x6<<ADC_SQR1_SQ1_Pos
			|0x7<<ADC_SQR1_SQ2_Pos
			|0x8<<ADC_SQR1_SQ3_Pos
			|0x9<<ADC_SQR1_SQ4_Pos
			;

	ADC1->SQR2=0x5<<ADC_SQR2_SQ5_Pos
							;

	ADC1->SMPR1 = 0x7<<ADC_SMPR1_SMP1_Pos
				|0x7<<ADC_SMPR1_SMP2_Pos
				|0x7<<ADC_SMPR1_SMP3_Pos
				|0x7<<ADC_SMPR1_SMP4_Pos
				|0x7<<ADC_SMPR1_SMP5_Pos
				;

	ADC1->CFGR|=ADC_CFGR_DMAEN;

	ADC1_2_COMMON->CCR&=~ADC_CCR_CKMODE;
	ADC1_2_COMMON->CCR|=0x2<<ADC_CCR_CKMODE_Pos;

	ADC1->CR&=~ADC_CR_ADVREGEN;
	ADC1->CR|=0x1<<ADC_CR_ADVREGEN_Pos;

	ADC1->CR|=ADC_CR_ADCAL;
	while(ADC1->CR&ADC_CR_ADCAL){}



}
void dma_init();


















