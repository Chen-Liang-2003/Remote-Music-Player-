#ifndef __BEEP_H
#define __BEEP_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK��ӢSTM32������
//��������������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
//�������˿ڶ���
#define BEEP PBout(8)	// BEEP,�������ӿ�		   

void BEEP_Init(void);	//��ʼ��
void Sound(u16 frq);//���ų�ʼ��
void Buzzer_On(void);
void Buzzer_Off(void);
void play_music1(void);
void play_music2(void);
void play_music3(void);
void play_music4(void);
void play_music5(void);
void choose(int x);
//void Music_init(void);
//void Play_Music(int a,int b,int c);
//void Sound_SetHZ(uint16_t a);
//void B_Music(void);
		 				    
#endif

