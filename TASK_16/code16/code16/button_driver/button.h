/*
 * button.h
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../DIO_driver/dio.h"


void BUTTON_INIT(uint8_t port , uint8_t pinnumber);

void BUTTON_READ(uint8_t port , uint8_t pinnumber, uint8_t *value);

#endif /* BUTTON_H_ */