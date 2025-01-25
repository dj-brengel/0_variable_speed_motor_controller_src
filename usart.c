#include<usart.h>
#include<gpio.h>


void usart2_rxtx_init(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	USART2->CR1 |= USART_CR1_RE;
	USART2->CR1 |= USART_CR1_TE;
	USART2->CR1 |= USART_CR1_UE;
	pa2_usart2_tx();
	pa3_usart2_rx();
	usart_set_bd(USART2, APB1_CLK, BAUDRATE_115200);
}











static uint16_t compute_div(uint32_t PeriphClock, uint32_t Baudrate)
{

	return (PeriphClock+(Baudrate/2U)/Baudrate);
}



void usart_set_bd(USART_TypeDef* USARTx, uint32_t PeriphClock, uint32_t Baudrate)
{
	USARTx->BRR = compute_div(PeriphClock, Baudrate);
}





