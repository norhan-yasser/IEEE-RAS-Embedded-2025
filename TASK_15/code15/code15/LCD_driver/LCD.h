#ifndef LCD_H_
#define LCD_H_

#include "../utilities/types.h"   // make sure uint8_t, uint64_t are defined
#include "LCD_CFG.h"
#if   LCD_MODE == 4
#define FOUR_BITS   0x28   // 4-bit mode initialization
#elif LCD_MODE == 8
#define EIGHT_BITS  0x38   // 8-bit mode initialization (8-bit data, 2-line display, 5x7 font)
#endif

// LCD command macros
#define lcd_DisplayOn_CursorOff   0x0C   // display on, cursor off, no blink
#define lcd_DisplayOn_CursorOn    0x0E   // display on, cursor on
#define lcd_DisplayOff_CursorOff  0x08   // display off
#define lcd_Clear                 0x01   // clear display
#define lcd_EntryMode             0x06   // shift cursor left to right
#define lcd_Home                  0x02   // return cursor to first position
#define lcd_CGRAM                 0x40   // CGRAM base address
#define lcd_SetCursor             0x80   // DDRAM base address
#define lcd_FunctionReset         0x30   // reset LCD

// API functions
void LCD_Init(void);
void LCD_ClearScreen(void);
void LCD_SetPosition(uint8_t Row, uint8_t Col);
void LCD_SendData(uint8_t Data);
void LCD_SendCommand(uint8_t Command);
void LCD_SendString(const uint8_t *ptrString);
void LCD_SendNumber(uint64_t Number);

#endif /* LCD_H_ */
