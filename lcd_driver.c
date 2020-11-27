/*
 * lcd_driver.c
 *
 *  Created on: Nov 20, 2020
 *      Author: Vangard Vangard
 */
#include<stdio.h>
#include<stdlib.h>
#include<avr/io.h>
#include<avr/delay.h>
#include"macros.h"
#include "lcd_driver.h"
void LCD_setMode(void){
LCD_DATA_PORT=0x00;
#if LCD_DATA_MODE ==four
	setbit(LCD_DATA_PORT,LCD_DB5_PIN);
#endif
}
void LCD_clearDisplay(void){

	LCD_DATA_PORT =0X00;
	setbit(LCD_DATA_PORT,LCD_DB0_PIN);
	LCD_CONTROL_PORT &= ~(1<<LCD_RS_PIN);
	LCD_CONTROL_PORT &= ~(1<<LCD_RW_PIN);
}
void LCD_displayOn(void){

	LCD_DATA_PORT =0X00;
	setbit(LCD_DATA_PORT,LCD_DB3_PIN);
	setbit(LCD_DATA_PORT,LCD_DB2_PIN);
	setbit(LCD_DATA_PORT,LCD_DB1_PIN);
	LCD_CONTROL_PORT &= ~(1<<LCD_RS_PIN);
	LCD_CONTROL_PORT &= ~(1<<LCD_RW_PIN);
}
void LCD_enable(void){

	setbit(LCD_CONTROL_PORT,LCD_E_PIN);
}
void LCD_disable(void){

	clearbit(LCD_CONTROL_PORT,LCD_E_PIN);
}
void LCD_writeCommand(unsigned char hex){
	clearbit(LCD_CONTROL_PORT,LCD_RW_PIN);
	_delay_ms(1);
	LCD_enable();
	_delay_ms(1);
    LCD_DATA_PORT= hex;
	LCD_disable();

}
void LCD_init(void){
	LCD_DATA_DDR=0xFF;
	LCD_CONTROL_DDR=0xFF;
	_delay_ms(40);
	LCD_writeCommand(0x20);
	LCD_writeCommand(0x20);
	LCD_writeCommand(0x80);
	_delay_ms(1);
	LCD_writeCommand(0x00);
	LCD_writeCommand(0xF0);
	_delay_ms(1);
	LCD_writeCommand(0x00);
	LCD_writeCommand(0x10);
	_delay_ms(2);
}
void LCD_writeChar(char c){
	clearbit(LCD_CONTROL_PORT,LCD_RW_PIN);
	setbit(LCD_CONTROL_PORT,LCD_RS_PIN);
	LCD_writeCommand(c);
	_delay_ms(1);
	LCD_enable();
	_delay_ms(1);
	LCD_DATA_PORT=((c<<4)&0xF0);
	_delay_ms(1);
	LCD_disable();
}
