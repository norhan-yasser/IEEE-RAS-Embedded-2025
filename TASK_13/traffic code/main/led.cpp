#include "led.h"

void LED_Init(void) {
    DDRD |= (1 << RED_LED) | (1 << YELLOW_LED) | (1 << GREEN_LED);  // Set as outputs
}

void LED_On(uint8_t ledPin) {
    PORTD |= (1 << ledPin);
}

void LED_Off(uint8_t ledPin) {
    PORTD &= ~(1 << ledPin);
}
