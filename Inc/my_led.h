/*
 * my_led.h
 *
 *  Created on: Nov 28, 2024
 *      Author: root
 */

#ifndef MY_LED_H_
#define MY_LED_H_

#include <stdint.h>


#define RCC		      			(0x40023800)
#define AHB1ENR_OFFSET          (0x30)
#define RCC_AHB1ENR   			((RCC) + (AHB1ENR_OFFSET))


#define GPIOB_EN				1
#define GPIOC_EN				2


#define LED_GREEN   			13     //PB13
#define LED_RED 				5      //PC5

#define GPIOB 					(0x40020400)
#define GPIOC 					(0x40020800)

#define MODER_OFFSET			(0x00)
#define GPIOB_MODER			((GPIOB) + (MODER_OFFSET))
#define GPIOC_MODER			((GPIOC) + (MODER_OFFSET))


#define ODR_OFFSET			(0x14)
#define GPIOB_ODR			((GPIOB) + (ODR_OFFSET))
#define GPIOC_ODR			((GPIOC) + (ODR_OFFSET))


#define DELAY_COUNT_1MS 		 1250U
#define DELAY_COUNT_1S  		(1000U * DELAY_COUNT_1MS)
#define DELAY_COUNT_500MS  		(500U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_250MS 		(250U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_125MS 		(125U  * DELAY_COUNT_1MS)

void led_init(void);
void led_on(uint8_t led_no);
void led_off(uint8_t led_no);
void delay(uint32_t count);


typedef enum {
	LT_GREEN = 2,
	LT_RED
}led_type_e;


#endif /* MY_LED_H_ */
