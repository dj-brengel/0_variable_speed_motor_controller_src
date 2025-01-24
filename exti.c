#include<exti.h>






void pa9_exti_init(void)
{
	__disable_irq();
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	SYSCFG->EXTICR[2] &=~ SYSCFG_EXTICR3_EXTI9;
	EXTI->IMR |= EXTI_IMR_MR9;
	EXTI->RTSR |= EXTI_FTSR_TR9;
	NVIC_EnableIRQ(EXTI9_5_IRQn);
	__enable_irq();
}



void pc7_exti_init(void)
{
	__disable_irq();
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI7_PC;
	EXTI->IMR |= EXTI_IMR_MR7;
	EXTI->RTSR |= EXTI_FTSR_TR7;
	NVIC_EnableIRQ(EXTI9_5_IRQn);
	__enable_irq();
}


/*****Steps for enabling interrupt for a GPIO pin*****/

/*
 * 1. disable global interrupt
 * 2. enable clock access to the gpio peripheral
 * 3. enable clock access to the system configuration controller (RCC->APB2ENR)
 * 4. select pin as source input for exti line (SYSCFG->EXTICR3)
 * 5. unmask exti line
 * 6. configure exti sensitivity (falling/rising edge)
 * 7. enable exti line in NVIC
 * 8. enable global interrupt
 */



































