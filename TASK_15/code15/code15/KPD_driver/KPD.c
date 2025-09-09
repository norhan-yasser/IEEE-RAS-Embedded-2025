#include "KPD.h"
#include "KPD_CFG.h"
#include "../DIO_driver/dio.h"
#include <util/delay.h>

const uint8_t KPD_u8Buttons[4][4] = {
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'C','0','=','+'}
};

void KPD_Init(void) {
	// Rows as outputs, initially HIGH
	DIO_init(KPD_PORT, KPD_R0, OUTPUT); DIO_write(KPD_PORT, KPD_R0, HIGH);
	DIO_init(KPD_PORT, KPD_R1, OUTPUT); DIO_write(KPD_PORT, KPD_R1, HIGH);
	DIO_init(KPD_PORT, KPD_R2, OUTPUT); DIO_write(KPD_PORT, KPD_R2, HIGH);
	DIO_init(KPD_PORT, KPD_R3, OUTPUT); DIO_write(KPD_PORT, KPD_R3, HIGH);

	// Columns as inputs with pull-ups enabled
	DIO_init(KPD_PORT, KPD_C0, INPUT); DIO_write(KPD_PORT, KPD_C0, HIGH);
	DIO_init(KPD_PORT, KPD_C1, INPUT); DIO_write(KPD_PORT, KPD_C1, HIGH);
	DIO_init(KPD_PORT, KPD_C2, INPUT); DIO_write(KPD_PORT, KPD_C2, HIGH);
	DIO_init(KPD_PORT, KPD_C3, INPUT); DIO_write(KPD_PORT, KPD_C3, HIGH);
}

uint8_t KPD_u8GetPressed(void) {
	for (uint8_t row = 0; row < 4; row++) {
		// Activate current row (drive LOW)
		DIO_write(KPD_PORT, KPD_ROW_INIT + row, LOW);

		for (uint8_t col = 0; col < 4; col++) {
			uint8_t val;
			DIO_read(KPD_PORT, KPD_COL_INIT + col, &val);

			if (val == LOW) {  // button pressed
				_delay_ms(20); // debounce

				// Wait until released
				do {
					DIO_read(KPD_PORT, KPD_COL_INIT + col, &val);
				} while (val == LOW);

				// Restore row before returning
				DIO_write(KPD_PORT, KPD_ROW_INIT + row, HIGH);
				return KPD_u8Buttons[row][col];
			}
		}

		// Deactivate row (drive HIGH again)
		DIO_write(KPD_PORT, KPD_ROW_INIT + row, HIGH);
	}
	return NOTPRESSED;
}
