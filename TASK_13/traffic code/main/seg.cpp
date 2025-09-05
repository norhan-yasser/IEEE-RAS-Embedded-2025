#include "seg.h"

static const uint8_t seg_digits[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
};

void SEG_Init(void) {
    DDRB = 0xFF; // PORTB as output for segments
    DDRC |= (1 << DIGIT1) | (1 << DIGIT2); // PC0, PC1 as outputs
}

void SEG_DisplayNumber(uint8_t number, uint16_t duration_ms) {
    uint8_t tens = number / 10;
    uint8_t ones = number % 10;
    
    for (uint16_t i = 0; i < duration_ms / 5; i++) {
        // Display tens digit
        PORTC = (1 << DIGIT1);
        PORTB = seg_digits[tens];
        _delay_ms(2);

        // Display ones digit
        PORTC = (1 << DIGIT2);
        PORTB = seg_digits[ones];
        _delay_ms(2);
    }
}

