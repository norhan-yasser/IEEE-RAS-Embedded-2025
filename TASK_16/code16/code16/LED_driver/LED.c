/*
 * LED.c
 *
 * Created: 10-Sep-25 12:58:27 AM
 *  Author: Yasser Khidr
 */ 

 #include "LED.h"
 
void LED_init(uint8_t port , uint8_t pinNumber){
	
	DIO_init(port,pinNumber,OUTPUT);
}

void LED_ON(uint8_t port , uint8_t pinNumber){
	
	DIO_write(port , pinNumber , HIGH);
	
}

void LED_OFF(uint8_t port , uint8_t pinNumber){
	
	DIO_write(port,pinNumber,LOW);
}

void LED_TOGGLE(uint8_t port , uint8_t pinNumber){
	
	DIO_toggle(port,pinNumber);
}