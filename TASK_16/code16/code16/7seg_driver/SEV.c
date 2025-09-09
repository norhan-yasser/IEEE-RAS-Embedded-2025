#include "SEV.h"
#include "../DIO_driver/dio.h"
#include <util/delay.h>

/* segment bit order: a b c d e f g mapped to PC0..PC6 */
/* segment patterns for common-cathode (1 lights segment) */
static const uint8_t sev_map[10] = {
	/* gfedcba (bit0->a) */
	0b00111111, // 0 -> a b c d e f
	0b00000110, // 1 -> b c
	0b01011011, // 2 -> a b d e g
	0b01001111, // 3 -> a b c d g
	0b01100110, // 4 -> f g b c
	0b01101101, // 5 -> a f g c d
	0b01111101, // 6 -> a f e d c g
	0b00000111, // 7 -> a b c
	0b01111111, // 8 -> all
	0b01101111  // 9 -> a b c d f g
};

void Sev_Init(void) {
	/* assume PORTC pins 0..6 are used for segments a..g */
	for (uint8_t i = 0; i <= 6; ++i) {
		DIO_init(PORT_C, i, OUTPUT);
	}
	/* clear segments */
	for (uint8_t i = 0; i <= 6; ++i) DIO_write(PORT_C, i, LOW);
}

void Sev_DisplayNumber(uint8_t num) {
	if (num > 9) num = 0;
	uint8_t pattern = sev_map[num];
	for (uint8_t bit = 0; bit <= 6; ++bit) {
		DIO_write(PORT_C, bit, (pattern >> bit) & 1);
	}
}
