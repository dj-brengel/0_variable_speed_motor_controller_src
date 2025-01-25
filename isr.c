#include<isr.h>








void EXTI9_5_IRQHandler(void)
{
	if(EXTI->PR & EXTI_PR_PR9)
	{
		EXTI->PR |= EXTI_PR_PR9;
		exti_pa9_callback();

	}
	if(EXTI->PR & EXTI_PR_PR7)
	{
		EXTI->PR |= (EXTI_PR_PR7);
		exti_pc7_callback();
	}

}


void exti_pc7_callback(void)
{
	GPIOA->BSRR |= GPIO_BSRR_BR_8;
	GPIOB->BSRR |= GPIO_BSRR_BS_10;
}

void exti_pa9_callback(void)
{
	GPIOB->BSRR |= GPIO_BSRR_BR_10;
	GPIOA->BSRR |= GPIO_BSRR_BS_8;

}






void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & EXTI_PR_PR13)
	{
		exti_pc13_callback();
	}
}

void exti_pc13_callback(void)
{
	GPIOA->BSRR |= GPIO_BSRR_BS5;
	printf("Motor initialized...");
}





void USART_IRQHandler(void)
{
	if(USART2->SR & USART_SR_TXE)
	{
		usart_callback();
	}
}

void usart_callback(void)
{

}
