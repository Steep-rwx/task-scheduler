/*
 * led.c
 *
 *  Created on: Sep 13, 2026
 *      Author: steep
 */

#include <stdint.h>
#include "led.h"

void delay(uint32_t count)
{
	for (uint32_t i = 0; i < count; i++);
}

void initialize_led(void)
{
	uint32_t *p_rcc_ahb1enr_addr = (uint32_t*) RCC_AHB1ENR_ADDR;
	uint32_t *p_gpioc_moder_addr = (uint32_t*) GPIOC_MODER_ADDR;

	*p_rcc_ahb1enr_addr |= (1 << 2);

	*p_gpioc_moder_addr |= (1 << (2 * LED_BLUE));

	led_off(LED_BLUE);

}

void led_on(uint8_t led_number)
{
	uint32_t *p_gpioc_odr_addr = (uint32_t*) GPIOC_ODR_ADDR;

	*p_gpioc_odr_addr &= ~(1 << led_number);
}

void led_off(uint8_t led_number)
{
	uint32_t *p_gpioc_odr_addr = (uint32_t*) GPIOC_ODR_ADDR;

	*p_gpioc_odr_addr |= (1 << led_number);
}
