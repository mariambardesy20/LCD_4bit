/*
 * main.c
 *
 *  Created on: Nov 20, 2020
 *      Author: Vangard Vangard
 */
#include<stdio.h>
#include<stdlib.h>
#include"lcd_driver.h"
int main(){
LCD_init();
LCD_writeChar('h');
LCD_writeChar('e');
LCD_writeChar('l');
LCD_writeChar('l');
LCD_writeChar('o');

	return 0;
}
