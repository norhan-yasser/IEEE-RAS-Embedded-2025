#ifndef LED_H_
#define LED_H_

#include <avr/io.h>

#define RED_LED     PD0
#define YELLOW_LED  PD1
#define GREEN_LED   PD2

void LED_Init(void);
void LED_On(uint8_t ledPin);
void LED_Off(uint8_t ledPin);

#endif
