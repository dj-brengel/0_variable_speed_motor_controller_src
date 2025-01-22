#include<gpio.h>









/*****Initialize pins PA9 and PC7*****/

void pa9_input_pd(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //enable clock access to gpioa

	GPIOA->MODER &=~ (1U<<18); //set as input pin
	GPIOA->MODER &=~ (1U<<19);

	GPIOA->PUPDR |= (1U<<19); //set as pull-down pin
	GPIOA->PUPDR &=~ (1U<<18);
}


void pc7_input_pd(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; //enable clock access to gpioc

	GPIOA->MODER &=~ (1U<<14); //set as input pin
	GPIOA->MODER &=~ (1U<<15);

	GPIOA->PUPDR |= (1U<<15); //set as pull-down pin
	GPIOA->PUPDR &=~ (1U<<14);
}



