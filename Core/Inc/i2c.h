/*
 * i2c.h
 *
 *  Created on: 25 sty 2022
 *      Author: Adrian
 */

#ifndef _I2C_H_
#define _I2C_H_

void i2c_init(void);

void	i2c_send_address(uint8_t addrs);

void	i2c_transfer(uint8_t addrs, uint8_t *pData, uint8_t len);


#endif /* INC_I2C_H_ */
