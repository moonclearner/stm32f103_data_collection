#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "usart.h"


int main(void)
{	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);  //开启gpioC->led  gpioA->usart1
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	usart1_debug_init(115200);
	led_init();
	while(1)
	{
		RGB_led_BLN();
	}

}

