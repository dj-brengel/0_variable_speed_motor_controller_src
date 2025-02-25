#include<isr.h>
#include<ring_buffer.h>
#include<usart.h>






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



/***********************************************************************************************/


int init = 0;



void EXTI15_10_IRQHandler(void)
{
	if(init == 0) {
		exti_pc13_callback_initialize();
		EXTI->PR |= EXTI_PR_PR13;
		init = 1;
	}
	else {
		exti_pc13_callback_shutdown();
		EXTI->PR |= EXTI_PR_PR13;
		init = 0;
	}
}



//void EXTI15_10_IRQHandler(void)
//{
//	if(EXTI->PR & EXTI_PR_PR13)
//	{
//		exti_pc13_callback();
//		EXTI->PR |= EXTI_PR_PR13;
//	}
//}



void exti_pc13_callback_shutdown(void)
{
	GPIOA->BSRR |= GPIO_BSRR_BR5;
	usart_print("Motor shut down\n\r");
}


void exti_pc13_callback_initialize(void)
{
	GPIOA->BSRR |= GPIO_BSRR_BS5;
	usart_print("Motor initialized\n\r");

}


/*************************************************************************************************/




void USART2_IRQHandler(void)
{
	if(USART2->SR & USART_SR_TXE)
	{
		usart_callback();
	}
}

void usart_callback(void)
{
	rb_get(&tx_buffer);
	if(!(rb_empty(&tx_buffer)))
	{
		USART2->DR = ring_buffer_peek(&tx_buffer);
	}
	else
	{
	USART2->CR1 &=~ USART_CR1_TXEIE;

	}
}


















