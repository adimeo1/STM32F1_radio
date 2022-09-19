/*
 * encoder.c
 *
 *  Created on: 26 sty 2022
 *      Author: Adrian
 */

#include "platform_specific.h"
#include "gpio_f1.h"
#include "encoder.h"
#include "i2c.h"
#include "SSD1331.h"

void encoder_init(void)
{
	//APB2 peripheral clock enable register
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_TIM1EN | RCC_APB2ENR_AFIOEN;
	gpio_pin_cfg(GPIOA, PA8, gpio_mode_input_pull);
	gpio_pin_cfg(GPIOA, PA9, gpio_mode_input_pull);
	BB(GPIOA->ODR, PA8) = 1;
	BB(GPIOA->ODR, PA9) = 1;

	//slave mode control register Encoder mode 1, 2, 3
	TIM1->SMCR |= TIM_SMCR_SMS_0;

	//Input capture 1,2  filter
	TIM1->CCMR1 |= TIM_CCMR1_IC1F | TIM_CCMR1_IC2F;

	//auto-reload register
	TIM1->ARR = 10;

	//DMA/interrupt enable register
	//TIM1->DIER |= TIM_DIER_UIE;

	//TIM1 and TIM8 control register 1 enable counter
	TIM1->CR1 |= TIM_CR1_CEN;

///////////////////////////////////////////interrupt from encoder pin PA8///////////////////////
	//External interrupt configuration register 3 - PA8
	AFIO->EXTICR[2] |= AFIO_EXTICR3_EXTI8_PA;

	//Interrupt mask register Interrupt Mask on line x
	EXTI->IMR |= EXTI_IMR_MR8;

	//Falling trigger selection register
	EXTI->FTSR |= EXTI_FTSR_TR8;

	//Rising trigger selection register
	//EXTI->RTSR |= EXTI_RTSR_TR8;

	//functions enabling and disabling a specific interrupt in the NVIC controller
	//in the controller only interrupts from the microcontroller peripherals are activated
	NVIC_EnableIRQ(EXTI9_5_IRQn);


	////////////////////////////////////////////button PB12//

	gpio_pin_cfg(GPIOB, PB12, gpio_mode_input_floating);

	AFIO->EXTICR[3] |= AFIO_EXTICR4_EXTI12_PB;

	EXTI->IMR |= EXTI_IMR_MR12;
	EXTI->FTSR |= EXTI_FTSR_TR12;

	NVIC_EnableIRQ(EXTI15_10_IRQn);

	////////////////////////////////////////////button PB13//

	gpio_pin_cfg(GPIOB, PB13, gpio_mode_input_floating);

	AFIO->EXTICR[3] |= AFIO_EXTICR4_EXTI13_PB;

	EXTI->IMR |= EXTI_IMR_MR13;
	EXTI->FTSR |= EXTI_FTSR_TR13;

	NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/*
Pending register (EXTI_PR)
Pending bit
0: No trigger request occurred
1: selected trigger request occurred
This bit is set when the selected edge event arrives on the external interrupt line.
This bit is cleared by writing a ‘1’ into the bit.

Port input data register (GPIOx_IDR) (x=A..G)
Bits 15:0 IDRy: Port input data (y= 0 .. 15)
These bits are read only and can be accessed in Word mode only. They contain the input
value of the corresponding I/O port.
 */
__attribute__((interrupt)) void EXTI9_5_IRQHandler(void) {
if ( EXTI->PR & EXTI_PR_PR8) {
EXTI->PR |= EXTI_PR_PR8;

if ( GPIOA->IDR & PA9 ){
menu_next();
}
else {
	menu_prev();
}
}
}


__attribute__((interrupt)) void EXTI15_10_IRQHandler(void) {
if ( EXTI->PR & EXTI_PR_PR12) {
EXTI->PR |= EXTI_PR_PR12;

menu_enter();
}

if ( EXTI->PR & EXTI_PR_PR13) {
EXTI->PR |= EXTI_PR_PR13;

menu_back();

}
}

/*
volatile uint16_t pulse_count;
volatile uint16_t positions;
pulse_count = TIM1->CNT;
positions = pulse_count/2;
*/
