#include "beep.h"
#include "sys.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "delay.h"
#include "stm32f10x_tim.h"
#include "remote.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK 精英STM32开发板
//蜂鸣器驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

//初始化PB8为输出口.并使能这个口的时钟		    
//蜂鸣器初始化

void BEEP_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能GPIOB端口时钟
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				 //BEEP-->PB.8 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);	 //根据参数初始化GPIOB.8
 
 GPIO_ResetBits(GPIOB,GPIO_Pin_8);//输出0，关闭蜂鸣器输出

}


void Sound(u16 frq)
{
	u32 time;
	if(frq != 1000)
	{
//		time = 500000/((u32)frq);
		time = 100000/((u32)frq);
     BEEP = 1;
		GPIO_SetBits(GPIOB, GPIO_Pin_8);
 
		delay_us(time);
		BEEP = 0;
		GPIO_ResetBits(GPIOB, GPIO_Pin_8);
		delay_us(time);
	}else
		delay_us(1000);
}

void Buzzer_On(void)
{
    GPIO_SetBits(GPIOB, GPIO_Pin_8);
}
 
void Buzzer_Off(void)
{
    GPIO_ResetBits(GPIOB, GPIO_Pin_8);
}

void play_music1(void)////11111
	
{
	 int key=Remote_Scan();
uc16 tone[] = {262,294,330,349,392,440,494,523,587,659,698,784,1000};
u8 music[]={3,5,8,6,5,13,
	          3,5,6,8,5,13,
	          8,10,9,8,9,8,6,8,5,13,
					  3,5,6,5,6,8,9,5,6,13,
					  3,2,1,2,13,
            2,2,3,5,5,8,2,3,5,13};
u8 time[] ={
	      2,2,2,2,6,4,4,
				2,2,2,2,6,4,4,
        6,2,4,4,2,2,2,2,6,4,
				6,2,4,2,2,4,2,2,6,4,
				2,2,4,6,4,
				4,2,2,4,4,4,2,2,6,4};

	u16 i,e;
	u32 yanshi = 2;
	for(i=0;i<sizeof(music)/sizeof(music[0]);i++){
				for(e=0;e<(((u16)(time[i]*tone[music[i]])))/yanshi;e++){
					Sound((u32)tone[music[i]]);
					key=Remote_Scan();
				if(key !=98) break;
				}
				
		}

}

void play_music2(void)////11111
	
{
int key=Remote_Scan();
uc16 tone[] = {247,262,294,330,349,392,440,494,523,587,659,698,784,1000,1047,1170};

u8 music[]=
            {5,5,6,8,7,6,5,6,13,13,
                5,5,6,8,7,6,5,3,13,13,
                2,2,3,5,3,5,6,3,2,1,
                6,6,5,6,5,3,6,5,13,13,

                5,5,6,8,7,6,5,6,13,13,
                5,5,6,8,7,6,5,3,13,13,
                2,2,3,5,3,5,6,3,2,1,
                6,6,5,6,5,3,6,1,

                13,8,9,10,10,9,8,10,9,8,6,
                13,6,8,9,9,8,6,9,8,6,5,
                13,2,3,5,5,3,5,5,6,8,7,6,
                6,10,9,9,8,6,5,6,8};
	u8 time[] =
                {2,4,2,2,2,2,2,8,4,4,
                2,4,2,2,2,2,2,8,4, 4,
                2,4,2,4,2,2,4,2,2,8,
                2,4,2,2,2,2,2,8,4 ,4,

                2,4,2,2,2,2,2,8,4, 4,
                2,4,2,2,2,2,2,8,4, 4,
                2,4,2,4,2,2,4,2,2,8,
                2,4,2,2,2,2,2,8,

                4, 2,2,2, 4, 2,2,2, 2,2,8,
                4, 2,2,2,4,2,2,2,2,2,8,
                4, 2,2,2,4,2,2,5,2,6,2,4,
                2,2 ,2,4,2,4,2,2,12};

	u16 i,e;
	u32 yanshi = 2;
			for(i=0;i<sizeof(music)/sizeof(music[0]);i++){
				for(e=0;e<(((u16)(time[i]*tone[music[i]])))/yanshi;e++){
					Sound((u32)tone[music[i]]);
					key=Remote_Scan();
				if(key !=194) break;
				}
		}
}


void play_music3(void)////11111
	
{
int key=Remote_Scan();
uc16 tone[]={247,262,294,330,349,392,440,494,523,587,659,698,784,880,988,1046,1000};

u8 music[]={
5,10,10,5,5,9,9,16,8,8,8,9,10,5,5,16,
6,8,8,6,5,10,10,16,9,8,8,6,9,16,
5,10,10,5,5,9,9,16,8,8,8,6,5,10,10,16,
6,11,11,6,5,10,10,16,9,8,8,6,8,16,
5,12,5,5,12,5,9,16,8,6,8,8,8,10,12,16,
8,6,8,8,8,13,12,10,9,8,6,8,8,10,9,16,
5,12,5,5,12,5,9,16,8,6,8,8,13,12,16,
8,8,8,13,12,10,9,8,6,8,8,9,8,16,
};

u8 time[]={
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,8,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,8,4,
4,4,2,2,4,4,4,4,4,4,2,2,4,4,8,4,
4,4,2,2,4,4,4,4,4,4,4,4,4,4,8,4,
4,4,2,2,4,4,4,4,4,4,4,4,4,8,4,
4,4,4,4,4,4,4,4,4,4,4,4,8,4,
};


	u16 i,e;
	u32 yanshi = 2;
	for(i=0;i<sizeof(music)/sizeof(music[0]);i++){
				for(e=0;e<(((u16)(time[i]*tone[music[i]])))/yanshi;e++){
					Sound((u32)tone[music[i]]);
					key=Remote_Scan();
				if(key !=34) break;
				}
		}
	}

void play_music4(void)////11111
	
{
 int key=Remote_Scan();
  uc16 tone[] = {262,294,330,349,392,440,494,523,
	587,659,698,784,880,988,1047,1175,1319,1397,1568,1760,1967,1000};

 u8 music[]={4,4,5,4,
                                                        7,6,21,
                                                        4,4,5,4,
                                                  8,7,21,
                                                        4,4,11,9,
                                                        7,6,5,21,
                                                        3,3,9,7,
                                                        8,7,21,
                                                        };
        
        u8 time[] = {2,2,4,4,        
                                                         4,4,4, 
                                                         2,2,4,4,
                                                         4,4,4,
                                                         2,2,4,4,
                                                         4,4,4,4,
                                                         2,2,4,4,
                                                         4,4,4,
               };        



	u16 i,e;
	u32 yanshi = 2;
	for(i=0;i<sizeof(music)/sizeof(music[0]);i++){
				for(e=0;e<(((u16)(time[i]*tone[music[i]])))/yanshi;e++){
					Sound((u32)tone[music[i]]);
					key=Remote_Scan();
				if(key !=168) break;
				}
		}
	}

	void play_music5(void)////11111
	
{
 int key=Remote_Scan();
uc16 tone[] = {262,294,330,349,392,440,494,523,587,659,698,784,880,988,1047,1175,1319,1397,1568,1760,1967,1000};
        //              0   1   2   3   4   5   6   7   8   9   10  11  12  13  14   15   16    17   18   19   20  21
        
        u8 music[]={11,11,11,10,9,9,8,8,7,8,
                                                        9,9,11,11,9,8,8,9,9,
                                                        7,7,7,7,7,9,9,9,8,8,8,7,8,
                                                        9,9,9,11,8,21,
                                                        11,11,11,11,10,9,8,7,8,
                                                        9,9,11,11,9,8,8,7,7,
                                                        7,7,7,7,7,9,9,9,8,8,8,7,8,
                                                        9,11,11,21,21,9,
                                                        8,21,21,4,5,4,
                                                        9,9,12,9,10,9,9,7,8,9,8,8,7,7,
                                                        7,7,9,7,8,7,7,5,6,7,6,6,
                                                        9,9,9,4,5,4,
                                                        9,9,9,9,11,9,9,7,8,9,8,8,7,7,
                                                        7,7,9,9,9,7,5,6,6,7,6,6,
                                                        5,7,8,8,7,7,8,8,9,8,
                                                        7,7,7,21,21                        
                                                        };        
        
        u8 time[] = {2,2,2,1,1,2,2,2,1,1,        
                                                         1,2,1,2,1,1,2,2,4,
                                                        1,1,1,1,2,1,1,2,2,1,1,1,1,
                                                        3,1,2,2,4,4,
                                                        1,2,1,2,1,1,6,1,1,
                                                        1,2,1,2,1,1,2,2,4,
                                                        1,1,1,1,2,1,1,2,2,1,1,1,1,
                                                        2,2,4,4,2,2,
                                                        4,4,2,2,2,2,
                                                        1,1,1,1,1,1,1,1,1,2,1,2,1,1,
                                                        1,1,1,1,1,1,1,1,2,1,1,4,
                                                        3,1,6,2,2,2,
                                                        1,1,1,1,1,1,1,1,2,1,1,2,1,1,
                                                        1,1,1,1,1,1,1,1,2,1,1,4,
                                                        2,1,1,2,2,2,1,1,2,2,
                                                        2,2,4,4,4,                        
               };        



	u16 i,e;
	u32 yanshi = 1;
	for(i=0;i<sizeof(music)/sizeof(music[0]);i++){
				for(e=0;e<(((u16)(time[i]*tone[music[i]])))/yanshi;e++){
					Sound((u32)tone[music[i]]);
					key=Remote_Scan();
				if(key !=226) break;
				}
		}
	}

	
void choose(int x)
{

int i;
	i = x;
	switch(i)
		{
		case 0:play_music1();break;
		case 1:play_music2();break;
		case 2:play_music3();break;
		case 3:play_music4();break;
		case 4:play_music5();break;
		
		}

}
	
//void Music_init(void)
//	
//{		
//	GPIO_InitTypeDef GPIO_InitStructure;
//	TIM_OCInitTypeDef TIM_OCInitStructure;
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
////	GPIO_InitTypeDef GPIO_InitStructure;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//	TIM_InternalClockConfig(TIM2);
////	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
//	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseInitStructure.TIM_Period = 99;	
//	TIM_TimeBaseInitStructure.TIM_Prescaler = 1439;
//	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 50;
//	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
////	TIM_OCInitTypeDef TIM_OCInitStructure;
//	TIM_OCStructInit(&TIM_OCInitStructure);
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStructure.TIM_Pulse = 50;		//CCR
//	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
//	TIM_Cmd(TIM2, ENABLE);
//}
//void Sound_SetHZ(uint16_t a)
//{
//	TIM_PrescalerConfig(TIM2,a,TIM_PSCReloadMode_Immediate);
//}
//void Play_Music(int a,int b,int c)
//{
//	Music_init();
//	Sound_SetHZ(a);delay_ms(b);Sound_SetHZ(20);delay_ms(c);
//}
//void B_Music(void){

//	int c;
//	for(i=0;i<=246;i++)
//	{
//        

//		c=5;j=tm[i]/25;
//		time=j*180;
//		if(i==49||i==67||i==178)
//		{
//			c=0;
//		}
//	
//		Play_Music(music[i],time,c);
//	}

//}
