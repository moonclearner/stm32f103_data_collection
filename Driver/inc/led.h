#ifndef LED_H_H
#define LED_H_H   //避免重复预申明

#define  LED_RED_OFF       GPIO_ResetBits(GPIOC,GPIO_Pin_7)
#define  LED_GREEN_OFF     GPIO_ResetBits(GPIOC,GPIO_Pin_8)
#define  LED_YELLOW_OFF    GPIO_ResetBits(GPIOC,GPIO_Pin_10)
#define  LED_BLUE_OFF      GPIO_ResetBits(GPIOA,GPIO_Pin_12)

#define  LED_RED_ON        GPIO_SetBits(GPIOC,GPIO_Pin_7)
#define  LED_GREEN_ON      GPIO_SetBits(GPIOC,GPIO_Pin_8)
#define  LED_YELLOW_ON     GPIO_SetBits(GPIOC,GPIO_Pin_10)
#define  LED_BLUE_ON       GPIO_SetBits(GPIOA,GPIO_Pin_12)

#define  LED_R    0X01
#define  LED_G    0X02
#define  LED_Y    0X04
#define  LED_B    0X08

#define  LED_OFF  0
#define  LED_ON   (!LED_OFF)

extern volatile unsigned char  red_value;    //volatile为了避免编译器对变量的优化
extern volatile unsigned char  yellow_value;
extern volatile unsigned char  blue_value;
extern volatile unsigned char  green_value;

extern void led_init(void);   //extern 用于声明该函数或者变量在外部文件中
extern void led_horse_race_lamp(void);
extern void RGB_led_BLN(void);

#endif
