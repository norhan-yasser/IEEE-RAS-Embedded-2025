#ifndef EXTI0_REGISTER_H_
#define EXTI0_REGISTER_H_

#include "../utilities/types.h"

/* ATmega32 I/O register addresses (I/O space) */
#define MCUCR   *((volatile uint8_t*)0x55)
#define MCUCSR  *((volatile uint8_t*)0x54)
#define GICR    *((volatile uint8_t*)0x5B)
#define GIFR    *((volatile uint8_t*)0x5A)
#define SREG    *((volatile uint8_t*)0x5F)

/* bit positions (optional if using EXTI_BITS.h) */
#include "../utilities/EXTI_BITS.h"

#endif /* EXTI0_REGISTER_H_ */
