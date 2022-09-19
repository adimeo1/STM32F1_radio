/*
 * spi.c
 *
 *  Created on: Jan 24, 2022
 *      Author: Adrian
 */


#include "platform_specific.h"

#include "gpio_f1.h"

#include "spi.h"

void spi_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_SPI1EN;

	gpio_pin_cfg(GPIOA, PA0, gpio_mode_output_PP_10MHz); /* GPIO -> CS (Chip Select)  SS (Slave Select). low state activates listening in the device to which data is to be transferred.*/
	gpio_pin_cfg(GPIOA, PA1, gpio_mode_output_PP_10MHz); /* GPIO -> D/C (Data/Command) - low status on this line causes that the received data are read as commands to the controller. Otherwise, as regular data.*/
	gpio_pin_cfg(GPIOA, PA2, gpio_mode_output_PP_10MHz); /* GPIO -> RES (Reset) - sa low state on this line resets the display.*/
	gpio_pin_cfg(GPIOA, PA5, gpio_mode_alternate_PP_10MHz); /* SCK CLK (Clock)  */
	gpio_pin_cfg(GPIOA, PA6, gpio_mode_input_pull); /* MISO */
	gpio_pin_cfg(GPIOA, PA7, gpio_mode_alternate_PP_10MHz); /* MOSI DIN (Data In/Device In) - i*/

	SPI1->CR1 |= SPI_CR1_SSM | SPI_CR1_SSI | SPI_CR1_SPE | SPI_CR1_MSTR;

}



uint16_t spi_rw(uint16_t data)
{
//Transmit buffer empty
while( !(SPI1->SR & SPI_SR_TXE) );
SPI1->DR = data;
//Receive buffer not empty
while( !(SPI1->SR & SPI_SR_RXNE) );
data = SPI1->DR;
return data;
}
