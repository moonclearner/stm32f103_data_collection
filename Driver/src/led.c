#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

void led_init(void)
{
		 GPIO_InitTypeDef GPIO_InitStructure;

	
	   //PC7--对应开发板红色指示灯;PC8--对应开发板绿色指示灯；PC10--对应开发板黄色指示灯
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;    //推挽输出
    GPIO_Init(GPIOC, &GPIO_InitStructure);
	
		//PA12---对应开发板蓝色指示灯
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}



void led_horse_race_lamp(void)
{
		LED_RED_ON;
		delay50;
		LED_RED_OFF;
		LED_GREEN_ON;
		delay50;
		LED_GREEN_OFF;
		LED_YELLOW_ON;
		delay50;	
		LED_YELLOW_OFF;
		LED_BLUE_ON;	
		delay50;
		LED_BLUE_OFF;
}


void RGB_led_BLN(void)
{
		LED_RED_ON;
		delay50;
		LED_RED_OFF;
		LED_GREEN_ON;
		delay50;
		LED_GREEN_OFF;
		LED_BLUE_ON;	
		delay50;
		LED_BLUE_OFF;
}

