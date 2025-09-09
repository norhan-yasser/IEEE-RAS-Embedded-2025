#ifndef EXTI1_REGISTER_H_
#define EXTI1_REGISTER_H_

#include "../utilities/types.h"

#define MCUCR   *((volatile uint8_t*)0x55)
#define MCUCSR  *((volatile uint8_t*)0x54)
#define GICR    *((volatile uint8_t*)0x5B)
#define GIFR    *((volatile uint8_t*)0x5A)
#define SREG    *((volatile uint8_t*)0x5F)

#include "../utilities/EXTI_BITS.h"

#endif /* EXTI1_REGISTER_H_ */
