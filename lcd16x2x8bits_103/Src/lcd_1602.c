#include "lcd_1602.h"

static void delay_us(uint32_t delay){
	delay*=32;
	while(delay--);
}

 void lcd_send_8bit(uint8_t data){
	
	if(data & 0x01) D0(1); else D0(0);
	if(data & 0x02) D1(1); else D1(0);
	if(data & 0x04) D2(1); else D2(0);
	if(data & 0x08) D3(1); else D3(0);
	if(data & 0x10) D4(1); else D4(0);
	if(data & 0x20) D5(1); else D5(0);
	if(data & 0x40) D6(1); else D6(0);
	if(data & 0x80) D7(1); else D7(0);
}

 void lcd_send(int8_t rs,uint8_t data){
	RS(rs);
	lcd_send_8bit(data);
	EN(1);delay_us(100);EN(0);
	
}

void lcd_cmd(uint8_t command){
	lcd_send(1,command);
}

void lcd_data(char c){
	lcd_send(1,(uint8_t)c);
}

void lcd_init(void){
	
	lcd_send(0,0x33);
  lcd_send(0,0x32);
  lcd_send(0,0x38);
  lcd_send(0,0x0C);
  lcd_send(0,0x06);
  lcd_send(0,0x01);
	HAL_Delay(10);
}

void lcd_clr(void){
    lcd_send(0,0x01);
    HAL_Delay(3);
}


void lcd_gotoxy(char x, char y){
	
					if(x==0)  lcd_send(0,0x80+y);
			else if (x == 1) lcd_send(0,0xc0+y);
	
}

void lcd_puts(char *text){
    while(*text){
        lcd_data(*text);
        text++;
    }
}
