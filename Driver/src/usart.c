#include "usart.h"




void usart1_debug_init(uint32_t baudrate)
{
	GPIO_InitTypeDef GPIO_init_struct;
	NVIC_InitTypeDef  NVIC_initstruct;
	USART_InitTypeDef  USART_initstruct;
	
	//ʱ�ӳ�ʼ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);  
	//gpio ʹ��
	//GPIO_InitTypeDef* GPIO_init_struct;  //������������

	
	//PA9
	GPIO_init_struct.GPIO_Pin=GPIO_Pin_9;    
	GPIO_init_struct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_init_struct.GPIO_Mode=GPIO_Mode_AF_PP;  //�����������
	GPIO_Init(GPIOA,&GPIO_init_struct);
	
	//PA10
	GPIO_init_struct.GPIO_Pin = GPIO_Pin_10;
  GPIO_init_struct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
  GPIO_Init(GPIOA, &GPIO_init_struct);//��ʼ��GPIOA.10  
	

	
	//Usart1 NVIC ����
// 	NVIC_InitTypeDef  NVIC_initstruct;        //�������ܷ���ִ�к������棬Ҫ����������
	
  NVIC_initstruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_initstruct.NVIC_IRQChannelPreemptionPriority=3;//��ռ���ȼ�
	NVIC_initstruct.NVIC_IRQChannelSubPriority =3;		//�����ȼ�
	NVIC_initstruct.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_initstruct);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���				
	
	  
	//USART1_debug ��ʼ������
	
	
	USART_initstruct.USART_BaudRate = baudrate;//���ڲ�����
	USART_initstruct.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_initstruct.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_initstruct.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_initstruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_initstruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
  USART_Init(USART1, &USART_initstruct); //��ʼ������1
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//�������ڽ����ж�
  USART_Cmd(USART1, ENABLE);                    //ʹ�ܴ���1 
	
}

void USART1_IRQHandler(void)
{
	u8 Res;
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		Res =USART_ReceiveData(USART1);	//��ȡ���յ�������
		USART_SendData(USART1,Res);
	}
}
