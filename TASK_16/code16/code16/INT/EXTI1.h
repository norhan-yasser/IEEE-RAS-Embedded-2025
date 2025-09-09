#ifndef EXTI1_H_
#define EXTI1_H_

#include "../utilities/types.h"

/* Sense control options (same as EXTI0) */
#define EXTI_LOW_LEVEL     0
#define EXTI_ANY_CHANGE    1
#define EXTI_FALLING_EDGE  2
#define EXTI_RISING_EDGE   3

void EXTI1_voidInit      (uint8_t SenseMode);
void EXTI1_voidEnable    (void);
void EXTI1_voidDisable   (void);
void EXTI1_voidSetCallBack(void (*pf)(void));

#endif /* EXTI1_H_ */
