/*
 * menu.c
 *
 *  Created on: 28 sty 2022
 *      Author: Adrian
 */
#include <string.h>
#include "platform_specific.h"
#include "gpio_f1.h"
#include "encoder.h"
#include "i2c.h"
#include "SSD1331.h"
#include "menu.h"
#include "menu_callbacks.h"


// definition of menu's components: (*name, *next, *prev, *child, *parent, (*menu_function))
menu_t menu1 = { "STACJE", &menu2, &menu4, &sub_menu1_1, NULL, NULL };
	menu_t sub_menu1_1 = { "RMFFM", &sub_menu1_2, &sub_menu1_6, NULL, &menu1, rmf_fm_func };
	menu_t sub_menu1_2 = { "RADIO KRAKOW", &sub_menu1_3, &sub_menu1_1, NULL, &menu1, radio_krakow_func };
	menu_t sub_menu1_3 = { "RADIO ZET", &sub_menu1_4, &sub_menu1_2, NULL, &menu1, radio_zet_func };
	menu_t sub_menu1_4 = { "RADIO PLUS", &sub_menu1_5, &sub_menu1_3, NULL, &menu1, radio_plus_func };
	menu_t sub_menu1_5 = { "RADIOPROGRA1", &sub_menu1_6, &sub_menu1_4, NULL, &menu1, radio_program1_func };
	menu_t sub_menu1_6 = { "RADIOPROPGRA3", NULL, &sub_menu1_5, NULL, &menu1, radio_program3_func};


menu_t menu2 = { "GLOSNOSC", &menu3, &menu1, &sub_menu2_1, NULL, NULL };
	menu_t sub_menu2_1 = { "glos 6", &sub_menu2_2, &sub_menu2_7, NULL, &menu2, glosnosc_6_func };
	menu_t sub_menu2_2 = { "glos 20", &sub_menu2_3, &sub_menu2_1, NULL, &menu2, glosnosc_20_func };
	menu_t sub_menu2_3 = { "glos 30", &sub_menu2_4, &sub_menu2_2, NULL, &menu2, glosnosc_30_func };
	menu_t sub_menu2_4 = { "glos 50", &sub_menu2_5, &sub_menu2_3, NULL, &menu2, glosnosc_50_func };
	menu_t sub_menu2_5 = { "glos 60", &sub_menu2_6, &sub_menu2_4, NULL, &menu2, glosnosc_60_func };
	menu_t sub_menu2_6 = { "glos 73", &sub_menu2_7, &sub_menu2_5, NULL, &menu2, glosnosc_73_func };
	menu_t sub_menu2_7 = { "glos 86", NULL, &sub_menu2_6, NULL, &menu2, glosnosc_86_func};

menu_t menu3 = { "WYLACZ", &menu4, &menu2, NULL, NULL, wylacz_func };
menu_t menu4 = { "WLACZ", NULL, &menu3, NULL, NULL, wlacz_func };


	menu_t *currentPointer = &menu1;

	uint8_t menu_index;
	uint8_t lcd_row_pos;
	uint8_t lcd_row_pos_level_1, lcd_row_pos_level_2;

	void menu_refresh(void) {

		menu_t *temp;
		uint8_t i;

		if (currentPointer->parent) temp = (currentPointer->parent)->child;
		else temp = &menu1;

		for (i = 0; i != menu_index - lcd_row_pos; i++) {
			temp = temp->next;
		}


		ssd1331_clear_screen(BLACK);

		for (i = 0; i < LCD_ROWS; i++) {


			if (temp == currentPointer) ssd1331_display_string(0, i*10,  "->", FONT_1206, RED);
			else ssd1331_display_string(0, i*10,  "  ", FONT_1206, RED);


			ssd1331_display_string(15, i*10,  temp->name, FONT_1206, GREEN);

			temp = temp->next;
			if (!temp) break;

		}

		// lcd_refresh();
	}

	uint8_t menu_get_index(menu_t *q) {

		menu_t *temp;
		uint8_t i = 0;

		if (q->parent) temp = (q->parent)->child;
		else temp = &menu1;

		while (temp != q) {
			temp = temp->next;
			i++;
		}

		return i;
	}

	uint8_t menu_get_level(menu_t *q) {

		menu_t *temp = q;
		uint8_t i = 0;

		if (!q->parent) return 0;

		while (temp->parent != NULL) {
			temp = temp->parent;
			i++;
		}

		return i;
	}

	void menu_next(void) {

		if (currentPointer->next)
		{

			currentPointer = (*currentPointer).next;
			menu_index++;
			if (++lcd_row_pos > LCD_ROWS - 1) lcd_row_pos = LCD_ROWS - 1;
		}
		else
		{
			menu_index = 0;
			lcd_row_pos = 0;

			if (currentPointer->parent) currentPointer = (currentPointer->parent)->child;
			else currentPointer = &menu1;
		}

		menu_refresh();

	}

	void menu_prev(void) {

		currentPointer = currentPointer->prev;

		if (menu_index)
		{
			menu_index--;
			if (lcd_row_pos > 0) lcd_row_pos--;
		}
		else
		{
			menu_index = menu_get_index(currentPointer);

			if (menu_index >= LCD_ROWS - 1) lcd_row_pos = LCD_ROWS - 1;
			else lcd_row_pos = menu_index;
		}

		menu_refresh();
	}

	void menu_enter(void) {

		if (currentPointer->menu_function) currentPointer->menu_function() ;

		if (currentPointer->child)
		{

			switch (menu_get_level(currentPointer)) {
				case 0:
					lcd_row_pos_level_1 = lcd_row_pos;
					break;

				case 1:
					lcd_row_pos_level_2 = lcd_row_pos;
					break;

			}

			// switch...case can be replaced by:
			// lcd_row_pos_level[ menu_get_level(currentPointer) ] = lcd_row_pos;

			menu_index = 0;
			lcd_row_pos = 0;

			currentPointer = currentPointer->child;

			menu_refresh();
		}
	}

	void menu_back(void) {

		if (currentPointer->parent) {

			switch (menu_get_level(currentPointer)) {
				case 1:
					lcd_row_pos = lcd_row_pos_level_1;
					break;

				case 2:
					lcd_row_pos = lcd_row_pos_level_2;
					break;

				}

			currentPointer = currentPointer->parent;
			menu_index = menu_get_index(currentPointer);

			menu_refresh();

		}
	}
