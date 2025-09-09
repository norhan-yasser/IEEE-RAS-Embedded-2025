#include "utilities/types.h"
#include "utilities/bit_manipulation.h"

#include "DIO_driver/dio.h"
#include "LCD_driver/LCD.h"
#include "KPD_driver/KPD.h"

#include <util/delay.h>

int main(void)
{
	/* Initialization */
	LCD_Init();
	KPD_Init();

	uint8_t key;
	int32_t operand1 = 0, operand2 = 0, result = 0;
	uint8_t operation = 0;
	uint8_t enteringSecondOperand = 0;

	LCD_SendString((uint8_t*)"Calculator ^__^");
	_delay_ms(1000);
	LCD_ClearScreen();

	while (1)
	{
		key = KPD_u8GetPressed();

		if (key != NOTPRESSED)
		{
			/* === Digits === */
			if (key >= '0' && key <= '9')
			{
				LCD_SendData(key);

				if (!enteringSecondOperand)
				{
					operand1 = operand1 * 10 + (key - '0');
				}
				else
				{
					operand2 = operand2 * 10 + (key - '0');
				}
			}

			/* === Operators === */
			else if (key == '+' || key == '-' || key == '*' || key == '/')
			{
				if (operation == 0) // prevent double operator press
				{
					LCD_SendData(key);
					operation = key;
					enteringSecondOperand = 1;
				}
			}

			/* === Equal (=) === */
			else if (key == '=')
			{
				LCD_SendData('=');

				switch (operation)
				{
					case '+': result = operand1 + operand2; break;
					case '-': result = operand1 - operand2; break;
					case '*': result = operand1 * operand2; break;
					case '/':
					if (operand2 != 0) result = operand1 / operand2;
					else {
						LCD_ClearScreen();
						LCD_SendString((uint8_t*)"Error: Div 0");
						_delay_ms(2000);
						LCD_ClearScreen();
						operand1 = operand2 = result = 0;
						operation = 0;
						enteringSecondOperand = 0;
						continue;
					}
					break;
				}

				LCD_SendNumber(result);

				/* reset for next calculation */
				operand1 = result;
				operand2 = 0;
				operation = 0;
				enteringSecondOperand = 0;
			}

			/* === Clear (C) === */
			else if (key == 'C')
			{
				LCD_ClearScreen();
				operand1 = operand2 = result = 0;
				operation = 0;
				enteringSecondOperand = 0;
			}
		}
	}
}
