#include "stm32f4xx.h"
#include<gpio.h>
#include<exti.h>
#include<isr.h>
#include<stdio.h>
#include<usart.h>
#include<ring_buffer.h>


ring_buffer tx_buffer;  		//creates buffer struct
uint8_t tx_buffer_data[16];		//creates data array for buffer struct





int main(void)
{
	rb_init(&tx_buffer,tx_buffer_data,16);

	pa9_input_pd_init();
	pc7_input_pd_init();

	pc13_input_init();
	pa5_output_init();

	pa8_output_init();
	pb10_output_init();

	pa9_exti_init();
	pc7_exti_init();
	pc13_exti_init();

	usart2_rxtx_init();

	usart_write('M');
	usart_write('o');
	usart_write('t');
	usart_write('o');
	usart_write('r');




}













