/*
 * my_led.c
 *
 *  Created on: Nov 28, 2024
 *      Author: root
 */


#include<stdint.h>
#include "my_led.h"



void delay(uint32_t count)
{
  for(uint32_t i = 0 ; i < count ; i++);
}

void led_init(void)
{
	//RCC Bus clock
	uint32_t *pRccAhb1enr = (uint32_t*)RCC_AHB1ENR;

	*pRccAhb1enr |= ( 1 << GPIOB_EN); //GPIO B clock enable
	*pRccAhb1enr |= ( 1 << GPIOC_EN); //GPIO C clock enable




	//GPIOB moder register
	uint32_t *pGpiobModeReg = (uint32_t*)GPIOB_MODER;
	//configure LED_GREEN
	*pGpiobModeReg |= ( 1 << (2 * LED_GREEN));


	//GPIOC moder register
	uint32_t *pGpiocModeReg = (uint32_t*)GPIOC_MODER;
	//configure LED_RED
	*pGpiocModeReg |= ( 1 << (2 * LED_RED));



    led_off(LT_GREEN);
    led_off(LT_RED);
}




void led_on(led_type_e led)
{
	if(led == LT_GREEN){

	  uint32_t *pGpiobDataReg = (uint32_t*)GPIOB_ODR;
	  *pGpiobDataReg |= ( 1 << LED_GREEN);

	}
	else if (led == LT_RED){

	  uint32_t *pGpiocDataReg = (uint32_t*)GPIOC_ODR;
	  *pGpiocDataReg |= ( 1 << LED_RED);

	}

}



void led_off(led_type_e led)
{

  	if(led == LT_GREEN){

  	  uint32_t *pGpiobDataReg = (uint32_t*)GPIOB_ODR;
  	  *pGpiobDataReg &= ~( 1 << LED_GREEN);

  	}
  	else if (led == LT_RED){

  	  uint32_t *pGpiocDataReg = (uint32_t*)GPIOC_ODR;
  	  *pGpiocDataReg &= ~( 1 << LED_RED);

  	}

}
