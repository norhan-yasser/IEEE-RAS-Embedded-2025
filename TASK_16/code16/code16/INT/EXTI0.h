#ifndef EXTI0_H_
#define EXTI0_H_

#include "../utilities/types.h"

/* Sense control options for INT0 */
#define EXTI_LOW_LEVEL     0
#define EXTI_ANY_CHANGE    1
#define EXTI_FALLING_EDGE  2
#define EXTI_RISING_EDGE   3

/* API */
void EXTI0_voidInit      (uint8_t SenseMode); /* configure sense (does NOT enable) */
void EXTI0_voidEnable    (void);              /* enable INT0 in GICR (and global) */
void EXTI0_voidDisable   (void);
void EXTI0_voidSetCallBack(void (*pf)(void)); /* set user ISR callback */

#endif /* EXTI0_H_ */
