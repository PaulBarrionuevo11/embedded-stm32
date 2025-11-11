/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Paul Barrionuevo
 * @brief          : Interact with the console on the STM32F44RE
 *					
 *					adjust syscalls.c file by adding the printf in the  *
 *
 ******************************************************************************
 */

#include <stdio.h>
#include <stdint.h>

/* global variables */
uint32_t int1 = 0;
uint32_t int2 = 0;
uint32_t result;


int main(void)
{
	printf("Hello STM32! \n");

	printf("Enter two numbers. Leave a space between them ");
	scanf("%d %d", &int1, &int2);


	result = int1 & int2;

	printf("AND result is = %d\n",result);

	for(;;);
}
