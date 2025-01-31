#include<usart.h>
#include<gpio.h>
#include<ring_buffer.h>


void usart2_rxtx_init(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	RCC->APB1RSTR |= RCC_APB1RSTR_USART2RST;
	RCC->APB1RSTR &=~ RCC_APB1RSTR_USART2RST;
	USART2->CR1 |= USART_CR1_RE;
	USART2->CR1 |= USART_CR1_TE;
	USART2->CR1 |= USART_CR1_UE;
	USART2->CR1 &=~ USART_CR1_TXEIE;
	NVIC_EnableIRQ(USART2_IRQn);
	pa2_usart2_tx();
	pa3_usart2_rx();
	usart_set_bd(USART2, APB1_CLK, 115200);
}







static uint16_t compute_div(uint32_t PeriphClock, uint32_t Baudrate)
{

	return ((PeriphClock+(Baudrate/2U))/Baudrate);
}



void usart_set_bd(USART_TypeDef* USARTx, uint32_t PeriphClock, uint32_t Baudrate)
{
	USARTx->BRR = compute_div(PeriphClock, Baudrate);
}




void usart_write(int ch)
{
	const bool tx_ongoing = !rb_empty(&tx_buffer);
	rb_put(&tx_buffer, ch);
	if(!tx_ongoing)
	{
		USART2->DR = ring_buffer_peek(&tx_buffer);
		USART2->CR1 |= USART_CR1_TXEIE;
	}

}


