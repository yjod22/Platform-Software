/*
*******************************************************************************
*                                                                             *
*							 Copyright (c)									  *
*                         All rights reserved.                                *
*                                                                             *
*******************************************************************************
*
*  Filename:     EhalUsart.c
*
*******************************************************************************                                                                            *
*  Description:
*
*  (For a detailed description look at the object description in the UML model)
*
*******************************************************************************
* History
*******************************************************************************
* Version:     2016b03
* Author/Date: Junseok Oh / 2023-11-03
* Change:      Enable Usart driver
*******************************************************************************
*/

#include "EhalUsart_CFG.h"
#include "EhalUsart_IN.h"
#include "EhalUsart_OUT.h"

/*
 * DEFINITION OF LOCAL MACROS/DEFINES
 * */

/*
 * DEFINITION OF LOCAL TYPES
 * */

/*
 * DEFINITION OF LOCAL VARIABLES
 * */
uint8_t EhalUsart_Temperature_Description_str[22] = "Current temperature: ";
uint8_t EhalUsart_Can_Description_str[30] = "Counter of received CAN msg: ";
uint8_t EhalUsart_Eol_str[2] = "\r\n";

/*
 * DEFINITION OF LOCAL CONSTANTS
 * */

/*
 * DECLARATION OF LOCAL FUNCTIONS
 * */

// Function to convert an integer to a string
void intToString(int value, uint8_t *str);

// Function to convert a float to a string
void floatToString(float value, uint8_t *str, int precision);

/*
 * DEFINITION OF GLOBAL VARIABLES
 * */

/*
 * IMPLEMENTATION OF GLOBAL FUNCTIONS
 * */

void EhalUsart_Init(void)
{
	EhalUsart_OUT_InitRcc();
	EhalUsart_OUT_InitGpio();
	EhalUsart_OUT_InitUsart();
}

void EhalUsart_SendTemperature(void)
{
	for(int i=0; i<sizeof(EhalUsart_Temperature_Description_str); i++)
	{
		EhalUsart_OUT_SendData(EhalUsart_Temperature_Description_str[i]);
	}

	float EhalUsart_Temperature_f;
	EhalUsart_IN_Temperature(&EhalUsart_Temperature_f);
	uint8_t EhalUsart_Temperature_str[5];
	floatToString(EhalUsart_Temperature_f, EhalUsart_Temperature_str, 2);
	for(int i=0; i<sizeof(EhalUsart_Temperature_str); i++)
	{
		EhalUsart_OUT_SendData(EhalUsart_Temperature_str[i]);
	}

	for(int i=0; i<sizeof(EhalUsart_Eol_str); i++)
	{
		EhalUsart_OUT_SendData(EhalUsart_Eol_str[i]);
	}
}

void EhalUsart_SendCan(void)
{
	Rte_CanRx_tst canRx;
	while (EhalUsart_IN_Can(&canRx) == TRUE)
	{
		for(int i=0; i<sizeof(EhalUsart_Can_Description_str); i++)
		{
			EhalUsart_OUT_SendData(EhalUsart_Can_Description_str[i]);
		}

		uint8_t EhalUsart_Can_MsgCounter_str[10];
		intToString(canRx.msgCounter, EhalUsart_Can_MsgCounter_str);
		for(int i=0; EhalUsart_Can_MsgCounter_str[i] != '\0'; i++)
		{
			EhalUsart_OUT_SendData(EhalUsart_Can_MsgCounter_str[i]);
		}

		for(int i=0; i<sizeof(EhalUsart_Eol_str); i++)
		{
			EhalUsart_OUT_SendData(EhalUsart_Eol_str[i]);
		}
	}
}

/*
 * IMPLEMENTATION OF LOCAL FUNCTIONS
 * */

// Function to convert an integer to a string
void intToString(int value, uint8_t *str) {
    int i = 0;
    int isNegative = 0;

    if (value < 0) {
        isNegative = 1;
        value = -value;
    }

    do {
        str[i++] = '0' + (value % 10);
        value /= 10;
    } while (value > 0);

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    // Reverse the string
    int len = i;
    for (int j = 0; j < len / 2; j++) {
        char temp = str[j];
        str[j] = str[len - j - 1];
        str[len - j - 1] = temp;
    }
}

// Function to convert a float to a string
void floatToString(float value, uint8_t *str, int precision) {
    int intPart = (int)value;
    float decimalPart = value - intPart;

    // Convert the integer part to a string
    intToString(intPart, str);

    // Add the decimal point
    int len = strlen(str);
    str[len] = '.';

    // Calculate the position for the first decimal digit
    char *decimalStr = str + len + 1;

    // Convert the decimal part to a string with the specified precision
    for (int i = 0; i < precision; i++) {
        decimalPart *= 10;
        int digit = (int)decimalPart;
        decimalPart -= digit;
        *decimalStr++ = '0' + digit;
    }

    *decimalStr = '\0'; // Null-terminate the string
}
