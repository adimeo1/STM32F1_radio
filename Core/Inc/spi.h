/*
 * spi.h
 *
 *  Created on: Jan 24, 2022
 *      Author: Adrian
 */

#ifndef _SPI_H_
#define _SPI_H_

void spi_init(void);

uint16_t spi_rw(uint16_t data);

#endif /* INC_SPI_H_ */
