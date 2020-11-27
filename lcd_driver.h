/*
 * lcd_driver.h
 *
 *  Created on: Nov 20, 2020
 *      Author: Vangard Vangard
 */

#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_
#include<stdio.h>
#include<stdlib.h>
#include<avr/io.h>
#include<avr/delay.h>
#include"macros.h"
#include"lcd_config.h"
void LCD_init(void);
void LCD_setMode(void);
void LCD_writeCommand(unsigned char hex);
void LCD_clearDisplay(void);
void LCD_displayOn(void);
void LCD_enable(void);
void LCD_disable(void);
#endif /* LCD_DRIVER_H_ */
