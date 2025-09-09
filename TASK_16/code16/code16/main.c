/* main.c
 * - INT0 toggles LED
 * - INT1 resets counter (1..9)
 * - Counter displayed on 7-seg and LCD
 */

#define F_CPU 8000000UL
#include <util/delay.h>
#include "utilities/types.h"
#include "DIO_driver/dio.h"
#include "LED_driver/LED.h"
#include "LCD_driver/LCD.h"
#include "7seg_driver/SEV.h"
#include "INT/EXTI0.h"
#include "INT/EXTI1.h"
#include <avr/interrupt.h>

/* shared counter */
volatile uint8_t g_counter = 1; /* counts 1..9 */

void EXTI0_callback(void) {
    /* toggle LED connected to PORTB, pin 0 */
    LED_TOGGLE(PORT_A, 4);
}

void EXTI1_callback(void) {
    /* reset counter to 1 */
    g_counter = 1;
    /* update displays immediately (safe-ish from ISR - but minimal work) */
    /* best practice: set a flag and update in main loop, but small update ok: */
    Sev_DisplayNumber(g_counter);
    LCD_ClearScreen();
    LCD_SendNumber(g_counter);
}

int main(void)
{
    /* init drivers */
    LED_init(PORT_A, 4);      // LED on PA4
    Sev_Init();               // 7-seg on PC0..PC6
    LCD_Init();               // your LCD config determines pins
    
    /* display startup */
    LCD_SendString((uint8_t*)"EXTI Demo");
    _delay_ms(1000);
    LCD_ClearScreen();

    /* EXTI setup */
    EXTI0_voidInit(EXTI_FALLING_EDGE); /* INT0 (PD2) falling edge toggles LED */
    EXTI0_voidSetCallBack(EXTI0_callback);
    EXTI0_voidEnable();

    EXTI1_voidInit(EXTI_FALLING_EDGE); /* INT1 (PD3) falling edge resets counter */
    EXTI1_voidSetCallBack(EXTI1_callback);
    EXTI1_voidEnable();

    /* ensure initial display */
    Sev_DisplayNumber(g_counter);
    LCD_SendNumber(g_counter);

    while (1)
    {
        /* increment 1..9 with delay; no timers used */
        _delay_ms(700);
        /* increment counter atomically */
        cli();
        if (g_counter >= 9) g_counter = 1;
        else g_counter++;
        sei();

        /* update displays */
        Sev_DisplayNumber(g_counter);
        LCD_ClearScreen();
        LCD_SendString((uint8_t*)"Count: ");
        LCD_SendNumber(g_counter);
    }
}
