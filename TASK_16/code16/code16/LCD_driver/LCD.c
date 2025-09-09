/*
 * LCD.c
 * LCD Driver (supports 4-bit and 8-bit using DIO driver)
 */

#include "LCD.h"
#include "LCD_CFG.h"
#include "../DIO_driver/dio.h"
#include <util/delay.h>

// -----------------------------------------
// Helper: Pulse Enable pin
// -----------------------------------------
static void LCD_EnablePulse(void) {
    DIO_write(LCD_EN_PORT, LCD_EN_PIN, HIGH);
    _delay_us(1);
    DIO_write(LCD_EN_PORT, LCD_EN_PIN, LOW);
    _delay_ms(2);
}

// -----------------------------------------
// Write data/command to data bus
// -----------------------------------------
static void LCD_WriteBus(uint8_t data) {
#if LCD_MODE == 8
    DIO_write(LCD_D0_PORT, LCD_D0_PIN, (data >> 0) & 1);
    DIO_write(LCD_D1_PORT, LCD_D1_PIN, (data >> 1) & 1);
    DIO_write(LCD_D2_PORT, LCD_D2_PIN, (data >> 2) & 1);
    DIO_write(LCD_D3_PORT, LCD_D3_PIN, (data >> 3) & 1);
    DIO_write(LCD_D4_PORT, LCD_D4_PIN, (data >> 4) & 1);
    DIO_write(LCD_D5_PORT, LCD_D5_PIN, (data >> 5) & 1);
    DIO_write(LCD_D6_PORT, LCD_D6_PIN, (data >> 6) & 1);
    DIO_write(LCD_D7_PORT, LCD_D7_PIN, (data >> 7) & 1);
    LCD_EnablePulse();

#elif LCD_MODE == 4
    // High nibble
    DIO_write(LCD_D4_PORT, LCD_D4_PIN, (data >> 4) & 1);
    DIO_write(LCD_D5_PORT, LCD_D5_PIN, (data >> 5) & 1);
    DIO_write(LCD_D6_PORT, LCD_D6_PIN, (data >> 6) & 1);
    DIO_write(LCD_D7_PORT, LCD_D7_PIN, (data >> 7) & 1);
    LCD_EnablePulse();

    // Low nibble
    DIO_write(LCD_D4_PORT, LCD_D4_PIN, (data >> 0) & 1);
    DIO_write(LCD_D5_PORT, LCD_D5_PIN, (data >> 1) & 1);
    DIO_write(LCD_D6_PORT, LCD_D6_PIN, (data >> 2) & 1);
    DIO_write(LCD_D7_PORT, LCD_D7_PIN, (data >> 3) & 1);
    LCD_EnablePulse();
#endif
}

// -----------------------------------------
// Send Command
// -----------------------------------------
void LCD_SendCommand(uint8_t Command) {
    DIO_write(LCD_RS_PORT, LCD_RS_PIN, LOW);   // RS = 0
    DIO_write(LCD_RW_PORT, LCD_RW_PIN, LOW);   // RW = 0
    LCD_WriteBus(Command);
}

// -----------------------------------------
// Send Data (character)
// -----------------------------------------
void LCD_SendData(uint8_t Data) {
    DIO_write(LCD_RS_PORT, LCD_RS_PIN, HIGH);  // RS = 1
    DIO_write(LCD_RW_PORT, LCD_RW_PIN, LOW);   // RW = 0
    LCD_WriteBus(Data);
}

// -----------------------------------------
// Initialize LCD
// -----------------------------------------
void LCD_Init(void) {
    // Init control pins
    DIO_init(LCD_RS_PORT, LCD_RS_PIN, OUTPUT);
    DIO_init(LCD_RW_PORT, LCD_RW_PIN, OUTPUT);
    DIO_init(LCD_EN_PORT, LCD_EN_PIN, OUTPUT);

#if LCD_MODE == 8
    // Init data pins
    DIO_init(LCD_D0_PORT, LCD_D0_PIN, OUTPUT);
    DIO_init(LCD_D1_PORT, LCD_D1_PIN, OUTPUT);
    DIO_init(LCD_D2_PORT, LCD_D2_PIN, OUTPUT);
    DIO_init(LCD_D3_PORT, LCD_D3_PIN, OUTPUT);
#endif
    DIO_init(LCD_D4_PORT, LCD_D4_PIN, OUTPUT);
    DIO_init(LCD_D5_PORT, LCD_D5_PIN, OUTPUT);
    DIO_init(LCD_D6_PORT, LCD_D6_PIN, OUTPUT);
    DIO_init(LCD_D7_PORT, LCD_D7_PIN, OUTPUT);

    _delay_ms(20); // LCD power-on delay

#if LCD_MODE == 8
    LCD_SendCommand(EIGHT_BITS);  // 8-bit, 2 lines
    _delay_ms(1);
#elif LCD_MODE == 4
    // Special init sequence for 4-bit mode
    LCD_SendCommand(0x33);
    LCD_SendCommand(0x32);
    LCD_SendCommand(FOUR_BITS);   // 4-bit, 2 lines
    _delay_ms(1);
#endif

    LCD_SendCommand(lcd_DisplayOn_CursorOff);
    _delay_ms(1);
    LCD_SendCommand(lcd_Clear);
    _delay_ms(2);
    LCD_SendCommand(lcd_EntryMode);
    _delay_ms(1);
}

// -----------------------------------------
// Clear screen
// -----------------------------------------
void LCD_ClearScreen(void) {
    LCD_SendCommand(lcd_Clear);
    _delay_ms(2);
}

// -----------------------------------------
// Set cursor
// -----------------------------------------
void LCD_SetPosition(uint8_t Row, uint8_t Col) {
    uint8_t address;
    if (Row == 0) address = 0x00 + Col;
    else          address = 0x40 + Col;
    LCD_SendCommand(lcd_SetCursor | address);
}

// -----------------------------------------
// Send string
// -----------------------------------------
void LCD_SendString(const uint8_t *ptrString) {
    while (*ptrString) {
        LCD_SendData(*ptrString++);
    }
}

// -----------------------------------------
// Send number
// -----------------------------------------
void LCD_SendNumber(uint64_t Number) {
    char buffer[20];
    uint8_t i = 0;

    if (Number == 0) {
        LCD_SendData('0');
        return;
    }

    while (Number > 0) {
        buffer[i++] = (Number % 10) + '0';
        Number /= 10;
    }

    while (i > 0) {
        LCD_SendData(buffer[--i]);
    }
}
