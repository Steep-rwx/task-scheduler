/*
 * led.h
 *
 *  Created on: Sep 13, 2026
 *      Author: steep
 */

#ifndef LED_H_
#define LED_H_

#define LED_BLUE 13

#define DELAY_COUNT_1MS 		 1250U
#define DELAY_COUNT_1S  		(1000U * DELAY_COUNT_1MS)
#define DELAY_COUNT_500MS  		(500U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_250MS 		(250U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_125MS 		(125U  * DELAY_COUNT_1MS)


#define RCC_AHB1ENR_ADDR 	0x40023830
#define GPIOC_MODER_ADDR	0x40020800
#define GPIOC_ODR_ADDR		0x40020814

#define LED_BLUE 			13

void delay(uint32_t count);
void initialize_led(void);
void led_on(uint8_t led_number);
void led_off(uint8_t led_number);

#endif /* LED_H_ */
