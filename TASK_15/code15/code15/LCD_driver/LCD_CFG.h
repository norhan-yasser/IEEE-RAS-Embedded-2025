#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_MODE  8   // choose 4 or 8

// Control pins
#define LCD_RS_PORT  PORT_A
#define LCD_RS_PIN   0

#define LCD_RW_PORT  PORT_A
#define LCD_RW_PIN   1

#define LCD_EN_PORT  PORT_A
#define LCD_EN_PIN   2

// Data pins (adjust to your wiring)
#if LCD_MODE == 8
#define LCD_D0_PORT  PORT_B
#define LCD_D0_PIN   0
#define LCD_D1_PORT  PORT_B
#define LCD_D1_PIN   1
#define LCD_D2_PORT  PORT_B
#define LCD_D2_PIN   2
#define LCD_D3_PORT  PORT_B
#define LCD_D3_PIN   3
#endif

#define LCD_D4_PORT  PORT_B
#define LCD_D4_PIN   4
#define LCD_D5_PORT  PORT_B
#define LCD_D5_PIN   5
#define LCD_D6_PORT  PORT_B
#define LCD_D6_PIN   6
#define LCD_D7_PORT  PORT_B
#define LCD_D7_PIN   7

#define LCD_ROWS 2
#define LCD_COLM 16

#endif /* LCD_CFG_H_ */
