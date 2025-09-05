#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "seg.h"
extern "C" {
  #include "led.h"
  #include "seg.h"
}
#include "traffic.h"


int main(void) {
    LED_Init();
    SEG_Init();

    while (1) {
        // RED phase
        LED_On(RED_LED);
        for (int i = RED_TIME; i > 0; i--) {
            SEG_DisplayNumber(i, 62.5);
        }
        LED_Off(RED_LED);

        // YELLOW phase
        LED_On(YELLOW_LED);
        for (int i = YELLOW_TIME; i > 0; i--) {
            SEG_DisplayNumber(i, 62.5);
        }
        LED_Off(YELLOW_LED);

        // GREEN phase
        LED_On(GREEN_LED);
        for (int i = GREEN_TIME; i > 0; i--) {
            SEG_DisplayNumber(i, 62.5);
        }
        LED_Off(GREEN_LED);
    }
}
