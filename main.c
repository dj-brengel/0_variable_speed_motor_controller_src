#include "stm32f4xx.h"
#include<gpio.h>
#include<exti.h>
#include<isr.h>
#include<stdio.h>
#include<usart.h>
#include<ring_buffer.h>


ring_buffer tx_buffer;  		//creates buffer struct
uint8_t tx_buffer_data[32];		//creates data array for buffer struct





int main(void)
{
	usart2_rxtx_init();

	rb_init(&tx_buffer,tx_buffer_data,32);

	pa9_input_pd_init();
	pc7_input_pd_init();

	pc13_input_init();
	pa5_output_init();

	pa8_output_init();
	pb10_output_init();

	pa9_exti_init();
	pc7_exti_init();
	pc13_exti_init();








}













