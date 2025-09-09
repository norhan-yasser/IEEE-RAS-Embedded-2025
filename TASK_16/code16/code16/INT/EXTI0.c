#include "EXTI0.h"
#include "EXTI0_REGISTER.h"
#include "../utilities/EXTI_BITS.h"
#include "../utilities/bit_manipulation.h"
#include <avr/interrupt.h>

/* Internal callback pointer */
static void (*EXTI0_PfCallback)(void) = 0;

/* Init sense control only (doesn't set GICR) */
void EXTI0_voidInit(uint8_t SenseMode)
{
	/* clear ISC01, ISC00 */
	MCUCR &= ~( (1<<ISC00) | (1<<ISC01) );
	switch(SenseMode)
	{
		case EXTI_LOW_LEVEL:    /* 00 */ break;
		case EXTI_ANY_CHANGE:   MCUCR |=  (1<<ISC00); break; /* 01 */
		case EXTI_FALLING_EDGE: MCUCR |=  (1<<ISC01); break; /* 10 */
		case EXTI_RISING_EDGE:  MCUCR |=  (1<<ISC01)|(1<<ISC00); break; /* 11 */
		default: MCUCR |= (1<<ISC01); break; /* default falling */
	}
	/* clear any pending flag */
	GIFR |= (1<<INTF0);
}

void EXTI0_voidEnable(void)
{
	GICR |= (1<<INT0);
	sei(); /* enable global interrupts */
}

void EXTI0_voidDisable(void)
{
	GICR &= ~(1<<INT0);
}

void EXTI0_voidSetCallBack(void (*pf)(void))
{
	EXTI0_PfCallback = pf;
}

ISR(INT0_vect)
{
	if (EXTI0_PfCallback) EXTI0_PfCallback();
}
