#ifndef SEG_H_
#define SEG_H_

#include <avr/io.h>
#include <util/delay.h>

#define DIGIT1 PC0
#define DIGIT2 PC1

void SEG_Init(void);
void SEG_DisplayNumber(uint8_t number, uint16_t duration_ms);

#endif
