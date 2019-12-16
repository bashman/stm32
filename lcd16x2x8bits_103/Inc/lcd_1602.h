#ifndef __LCD_1602_H
#define __LCD_1602_H

#include "main.h"

#define RS(x)		x?HAL_GPIO_WritePin(GPIOB, RS_Pin, GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB,RS_Pin,GPIO_PIN_RESET)
#define EN(x)		x?HAL_GPIO_WritePin(GPIOB, EN_Pin, GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB,EN_Pin,GPIO_PIN_RESET)

#define D0(x)		x?HAL_GPIO_WritePin(GPIOA,D0_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOA,D0_Pin,GPIO_PIN_RESET)
#define D1(x)		x?HAL_GPIO_WritePin(GPIOA,D1_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOA,D1_Pin,GPIO_PIN_RESET)
#define D2(x)		x?HAL_GPIO_WritePin(GPIOA,D2_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOA,D2_Pin,GPIO_PIN_RESET)
#define D3(x)		x?HAL_GPIO_WritePin(GPIOA,D3_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOA,D3_Pin,GPIO_PIN_RESET)
#define D4(x)		x?HAL_GPIO_WritePin(GPIOA,D4_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOA,D4_Pin,GPIO_PIN_RESET)
#define D5(x)		x?HAL_GPIO_WritePin(GPIOA,D5_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOA,D5_Pin,GPIO_PIN_RESET)
#define D6(x)		x?HAL_GPIO_WritePin(GPIOA,D6_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOA,D6_Pin,GPIO_PIN_RESET)
#define D7(x)		x?HAL_GPIO_WritePin(GPIOA,D7_Pin,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOA,D7_Pin,GPIO_PIN_RESET)


 void lcd_send_8bit(uint8_t data);
 void lcd_send(int8_t rs,uint8_t data);
void lcd_cmd(uint8_t command);
void lcd_data(char c);
void lcd_init(void);
void lcd_clr(void);
void lcd_gotoxy(char x, char y);
void lcd_puts(char *text);

#endif
