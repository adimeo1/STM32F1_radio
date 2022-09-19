/*
 * i2c.c
 *
 *  Created on: 25 sty 2022
 *      Author: Adrian
 */

#include "platform_specific.h"

#include "gpio_f1.h"

#include "i2c.h"

/*
 Reset value: 0x0000 0000
 MCO: Microcontroller clock output	0xx: No clock
 USB prescaler					0: PLL clock is divided by 1.5
 PLL multiplication factor		0000: PLL input clock x 2
 HSE divider for PLL entry		0: HSE clock not divided
 PLL entry clock source			0: HSI oscillator clock / 2 selected as PLL input clock
 ADC prescaler					00: PCLK2 divided by 2
 APB high-speed prescaler (APB2)0xx: HCLK not divided
 APB low-speed prescaler (APB1)	0xx: HCLK not divided
 AHB prescaler					0xxx: SYSCLK not divided
 System clock switch status		00: HSI oscillator used as system clock
 System clock switch			00: HSI selected as system clock

  HSI = 8 MHz	high speed internal
  AHB prescaler = 1
  system clock 8 MHz
  APB1 prescaler = 1 --> 8MHz

 */

void i2c_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;

	gpio_pin_cfg(GPIOB, PB6, gpio_mode_alternate_OD_10MHz); /* GPIO -> SCL*/
	gpio_pin_cfg(GPIOB, PB7, gpio_mode_alternate_OD_10MHz); /* GPIO -> SDA*/

	//tell I2c register APB1 clock frequency
	I2C1->CR2 &= ~(I2C_CR2_FREQ);
	I2C1->CR2 |= (8UL << 0);
	//RISE TIME
	I2C1->TRISE = 8+1;
	//I2C speed (100kHz)
	I2C1->CCR = 40;	//-> 100kHz SCL
	//Enable I2C
	I2C1->CR1 |= I2C_CR1_PE;

}

void	i2c_transfer(uint8_t addrs, uint8_t *pData, uint8_t len)
{
	//send start condidtion
	/*
	POS: Acknowledge/PEC Position (for data reception)
	This bit is set and cleared by software and cleared by hardware when PE=0.
	0: ACK bit controls the (N)ACK of the current byte being received in the shift register. The
	PEC bit indicates that current byte in shift register is a PEC.
	1: ACK bit controls the (N)ACK of the next byte which will be received in the shift register.
	The PEC bit indicates that the next byte in the shift register is a PEC
	 */
	I2C1->CR1 &= ~(I2C_CR1_POS);

	//START: Start generation
	I2C1->CR1 |= (I2C_CR1_START);

	/*
	SB: Start bit (Master mode)
	0: No Start condition
	1: Start condition generated.
	 */
	while(!(I2C1->SR1 & I2C_SR1_SB));

	//send slave address
	I2C1->DR = addrs;

	//wait for ack
	while(!(I2C1->SR1 & I2C_SR1_ADDR));


	//clear adress flag
	__IO uint32_t tempRd = I2C1->SR1;
	tempRd = I2C1->SR2;
	(void)tempRd;

	//send data
	uint8_t dataIdx = 0;
	int8_t dataSize = len;
	while (dataSize>0)
	{
		//check for Tx buffer empty --> send bytee TxE: Data register empty (transmitters)
		while(!(I2C1->SR1 & I2C_SR1_TXE));
		I2C1->DR = pData [dataIdx];
		dataIdx++;
		dataSize--;
		//Wait for BTE flag BTF: Byte transfer finished
		while(!(I2C1->SR1 & I2C_SR1_BTF));

	}
	//generate stop condition
	I2C1->CR1 |= (I2C_CR1_STOP);
}




