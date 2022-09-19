/*
 * menu_callbacks.c
 *
 *  Created on: 30 sty 2022
 *      Author: Adrian
 */

#include "platform_specific.h"
#include "gpio_f1.h"
#include "encoder.h"
#include "i2c.h"
#include "SSD1331.h"
#include "menu_callbacks.h"


/////////////////////configuration///////////////////////////////////////////
const uint8_t konfiguracja_on[3] = {0x02, 0xC0, 0x01};
const uint8_t konfiguracja_off[3] = {0x02, 0xc0, 0x00};
/////////////////////RADIO STATIONS///////////////////////////////////////////
const uint8_t rmf_fm[3] = {0x03, 0x16, 0x90};			//  Arrays frequency setting for a specific station
const uint8_t radio_krakow[3] = {0x03, 0x24, 0x90};
const uint8_t radio_zet[3] = {0x03, 0x2A, 0xD0};
const uint8_t radio_plus[3] = {0x03, 0x2F, 0xD0};
const uint8_t radio_program1[3] = {0x03, 0x06, 0x10};
const uint8_t radio_program3[3] = {0x03, 0x1F, 0x10};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const uint8_t glosnosc_6[3] = {0x05, 0x90, 0x81};
const uint8_t glosnosc_20[3] = {0x05, 0x90, 0x83};	// Arrays with volume setting
const uint8_t glosnosc_30[3] = {0x05, 0x90, 0x85};
const uint8_t glosnosc_50[3] = {0x05, 0x90, 0x87};
const uint8_t glosnosc_60[3] = {0x05, 0x90, 0x89};
const uint8_t glosnosc_73[3] = {0x05, 0x90, 0x8B};
const uint8_t glosnosc_86[3] = {0x05, 0x90, 0x8D};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rmf_fm_func(void)
{
i2c_transfer(0x22, rmf_fm, 3);
}

void radio_krakow_func(void)
{
i2c_transfer(0x22, radio_krakow, 3);
}

void radio_zet_func(void)
{
i2c_transfer(0x22, radio_zet, 3);
}

void radio_plus_func(void)
{
i2c_transfer(0x22, radio_plus, 3);
}

void radio_program1_func(void)
{
i2c_transfer(0x22, radio_program1, 3);
}

void radio_program3_func(void)
{
i2c_transfer(0x22, radio_program3, 3);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void glosnosc_6_func(void)
{
i2c_transfer(0x22, glosnosc_6, 3);
}

void glosnosc_20_func(void)
{
i2c_transfer(0x22, glosnosc_20, 3);
}

void glosnosc_30_func(void)
{
i2c_transfer(0x22, glosnosc_30, 3);
}

void glosnosc_50_func(void)
{
i2c_transfer(0x22, glosnosc_50, 3);
}

void glosnosc_60_func(void)
{
i2c_transfer(0x22, glosnosc_60, 3);
}

void glosnosc_73_func(void)
{
i2c_transfer(0x22, glosnosc_73, 3);
}

void glosnosc_86_func(void)
{
i2c_transfer(0x22, glosnosc_86, 3);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void wylacz_func(void)
{
i2c_transfer(0x22, konfiguracja_off, 3);
}

void wlacz_func(void)
{
i2c_transfer(0x22, konfiguracja_on, 3);
}
