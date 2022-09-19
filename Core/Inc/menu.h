/*
 * menu.h
 *
 *  Created on: 28 sty 2022
 *      Author: Adrian
 */

#ifndef _MENU_H_
#define _MENU_H_

#define LCD_ROWS 6
#define LCD_COLS 100

typedef struct menu_struct menu_t;

struct menu_struct {

	const char * name;
	menu_t * next;
	menu_t * prev;
	menu_t * child;
	menu_t * parent;
	void (*menu_function)(void);

};


menu_t menu1;
	menu_t sub_menu1_1;
	menu_t sub_menu1_2;
	menu_t sub_menu1_3;
	menu_t sub_menu1_4;
	menu_t sub_menu1_5;
	menu_t sub_menu1_6;

menu_t menu2;
	menu_t sub_menu2_1;
	menu_t sub_menu2_2;
	menu_t sub_menu2_3;
	menu_t sub_menu2_4;
	menu_t sub_menu2_5;
	menu_t sub_menu2_6;
	menu_t sub_menu2_7;
menu_t menu3;
menu_t menu4;


void menu_refresh(void);
void menu_next(void);
void menu_prev(void);
void menu_enter(void);
void menu_back(void);

#endif /* INC_MENU_H_ */
