#include "stm32f4xx.h"
#include<gpio.h>
#include<exti.h>
#include<isr.h>
#include<stdio.h>
#include<usart.h>
















int main(void)
{
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
}













