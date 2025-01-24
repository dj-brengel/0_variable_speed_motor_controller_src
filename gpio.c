#include<gpio.h>









/*****Initialize pins PA9 and PC7*****/

void pa9_input_pd_init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //enable clock access to gpioa

	GPIOA->MODER &=~ (1U<<18); //set as input pin
	GPIOA->MODER &=~ (1U<<19);

	GPIOA->PUPDR |= (1U<<19); //set as pull-down pin
	GPIOA->PUPDR &=~ (1U<<18);
}


void pc7_input_pd_init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; //enable clock access to gpioc

	GPIOC->MODER &=~ (1U<<14); //set as input pin
	GPIOC->MODER &=~ (1U<<15);

	GPIOC->PUPDR |= (1U<<15); //set as pull-down pin
	GPIOC->PUPDR &=~ (1U<<14);
}




/*****Initialize pins PA8 and PB10*****/

void pa8_output_init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //enable clock to gpioa

	GPIOA->MODER |= GPIO_MODER_MODER8_0; //set as output pin
	GPIOA->MODER &=~ GPIO_MODER_MODER8_1;
}



void pb10_output_init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; //enable clock to gpiob

	GPIOB->MODER |= GPIO_MODER_MODER10_0; //set as output pin
	GPIOB->MODER &=~ GPIO_MODER_MODER10_1;
}
