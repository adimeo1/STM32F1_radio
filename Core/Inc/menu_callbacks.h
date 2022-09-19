/*
 * menu_callbacks.h
 *
 *  Created on: 30 sty 2022
 *      Author: Adrian
 */

#ifndef _MENU_CALLBACKS_H_
#define _MENU_CALLBACKS_H_

//konfiuracja
extern const uint8_t konfiguracja_on[3];
extern const uint8_t konfiguracja_off[3];
///////////////////////////////////////////RADIO STATIONS
extern const uint8_t rmf_fm[3];			//  Arrays frequency setting for a specific station
extern const uint8_t radio_krakow[3];
extern const uint8_t radio_zet[3];
extern const uint8_t radio_plus[3];
extern const uint8_t radio_program1[3];
extern const uint8_t radio_program3[3];

///////////////////////////////////////////VOLUME LEVEL
extern const uint8_t glosnosc_6[3];
extern const  uint8_t glosnosc_20[3];	// Arrays with volume setting
extern const  uint8_t glosnosc_30[3];
extern const  uint8_t glosnosc_50[3];
extern const  uint8_t glosnosc_60[3];
extern const  uint8_t glosnosc_73[3];
extern const  uint8_t glosnosc_86[3];


void rmf_fm_func(void);
void radio_krakow_func(void);
void radio_zet_func(void);
void radio_plus_func(void);
void radio_program1_func(void);
void radio_program3_func(void);

void glosnosc_6_func(void);
void glosnosc_20_func(void);
void glosnosc_30_func(void);
void glosnosc_50_func(void);
void glosnosc_60_func(void);
void glosnosc_73_func(void);
void glosnosc_86_func(void);

void wylacz_func(void);
void wlacz_func(void);

#endif /* INC_MENU_CALLBACKS_H_ */
