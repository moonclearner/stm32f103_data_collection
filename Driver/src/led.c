#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

void led_init(void)
{
		 GPIO_InitTypeDef GPIO_InitStructure;

	
	   //PC7--��Ӧ�������ɫָʾ��;PC8--��Ӧ��������ɫָʾ�ƣ�PC10--��Ӧ�������ɫָʾ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;    //�������
    GPIO_Init(GPIOC, &GPIO_InitStructure);
	
		//PA12---��Ӧ��������ɫָʾ��
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

