/*
 * LED.h
 *
 * Created: 10-Sep-25 12:58:11 AM
 *  Author: Yasser Khidr
 */ 


#ifndef LED_H_
#define LED_H_


#include "../DIO_driver/dio.h"


void LED_init(uint8_t port , uint8_t pinNumber);
void LED_ON(uint8_t port , uint8_t pinNumber);
void LED_OFF(uint8_t port , uint8_t pinNumber);
void LED_TOGGLE(uint8_t port , uint8_t pinNumber);



#endif /* LED_H_ */