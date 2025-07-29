/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Paul Barrionuevo
 * @brief          : Turn on the built in LED on the STM32F446RE
 *
 * 					use the appropriate registers referred in the user manual
 *
 * 					@register to access clock control (RCC_AHB1ENR)
 * 					Address offset: 0x30
 * 					Clock main Address: 0x40023800
 * 					Address: 0x40023830
 * 					@register to access GPIOA pin Mode
 * 					Address offset: 0x00
 * 					GPIO main Address: 0x40020000
 * 					Address: 0x40020000
 * 					@register to access GPIOA output data
 * 					Address offset: 0x14
 * 					GPIO main Address: 0x40020000
 * 					Address: 0x40020014
 *
 *
 ******************************************************************************
 */

#include <stdint.h>

int main(void)
{
    // Pointers to registers (STM32F4 addresses)
    uint32_t *ptClock = (uint32_t*)0x40023830;    // RCC_AHB1ENR
    uint32_t *ptPinMode = (uint32_t*)0x40020000;  // GPIOA_MODER
    uint32_t *ptDataOut = (uint32_t*)0x40020014;  // GPIOA_ODR

    // 1. Enable the clock for GPIOA (bit 0 in RCC_AHB1ENR)
    *ptClock |= (1 << 0);  // Set bit 0
    //volatile uint32_t dummy = *ptClock;  // Read to ensure write completes

    // 2. Configure PA5 as output
    // a. Clear bits 11:10 for PA5
    *ptPinMode &= ~(3 << 10);
    // b. Set PA5 as output 
    *ptPinMode |= (1 << 10);   // Set bit 10

    // 3. Set PA5 high
    *ptDataOut |= (1 << 5);    // Set bit 5 for PA5

    while (1);
}

