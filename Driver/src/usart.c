#include "usart.h"




void usart1_debug_init(uint32_t baudrate)
{
	GPIO_InitTypeDef GPIO_init_struct;
	NVIC_InitTypeDef  NVIC_initstruct;
	USART_InitTypeDef  USART_initstruct;
	
	//时钟初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);  
	//gpio 使能
	//GPIO_InitTypeDef* GPIO_init_struct;  //不能这样定义

	
	//PA9
	GPIO_init_struct.GPIO_Pin=GPIO_Pin_9;    
	GPIO_init_struct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_init_struct.GPIO_Mode=GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_Init(GPIOA,&GPIO_init_struct);
	
	//PA10
	GPIO_init_struct.GPIO_Pin = GPIO_Pin_10;
  GPIO_init_struct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
  GPIO_Init(GPIOA, &GPIO_init_struct);//初始化GPIOA.10  
	

	
	//Usart1 NVIC 配置
// 	NVIC_InitTypeDef  NVIC_initstruct;        //变量不能放在执行函数后面，要放在最上面
	
  NVIC_initstruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_initstruct.NVIC_IRQChannelPreemptionPriority=3;//抢占优先级
	NVIC_initstruct.NVIC_IRQChannelSubPriority =3;		//子优先级
	NVIC_initstruct.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_initstruct);	//根据指定的参数初始化VIC寄存器				
	
	  
	//USART1_debug 初始化设置
	
	
	USART_initstruct.USART_BaudRate = baudrate;//串口波特率
	USART_initstruct.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_initstruct.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_initstruct.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_initstruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_initstruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
  USART_Init(USART1, &USART_initstruct); //初始化串口1
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启串口接受中断
  USART_Cmd(USART1, ENABLE);                    //使能串口1 
	
}

void USART1_IRQHandler(void)
{
	u8 Res;
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		Res =USART_ReceiveData(USART1);	//读取接收到的数据
		USART_SendData(USART1,Res);
	}
}
