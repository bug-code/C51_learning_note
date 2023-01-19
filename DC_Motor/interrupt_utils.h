#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_
#include "reg52.h"
/*�жϳ�ʼ��*/

/*�ⲿ�ж�0*/
void Int0_Init(const unsigned char *mode){//�ⲿ�ж�0�Ĵ�����ʽ��0�͵�ƽ������1�½��ش���
	EA=1;//���ж�����λ
	EX0=1;//�ⲿ�ж�0����λ
	IT0=*mode;	
}
/*�ⲿ�ж�1*/
void Int1_Init(const unsigned char *mode){//�ⲿ�ж�1�Ĵ�����ʽ��0�͵�ƽ������1�½��ش���
	EA=1;//���ж�����λ
	EX1=1;//�ⲿ�ж�0����λ
	IT1=*mode;	
}

void Timer0_Init(const unsigned char *mode ,const unsigned char *HighVal , const unsigned char *LowVal ){
	EA=1;//���ж�������λ
	ET0=1;//��T0�ж�����λ
	TR0=1;//��ʱ/�������ж�0��ʼ����
	TMOD |= *mode;//����T0����ģʽ
	TH0 = *HighVal; //�߰�λ�Ĵ�����ֵ
	TL0 = *LowVal;  //�ڰ�λ�Ĵ�����ֵ
} 

void Timer1_Init(const unsigned char *mode ,const unsigned char *HighVal , const unsigned char *LowVal ){
	EA=1;//���ж�������λ
	ET1=1;//��T0�ж�����λ
	TR1=1;//��ʱ/�������ж�0��ʼ����
	TMOD |= *mode;//����T0����ģʽ
	TH1 = *HighVal; //�߰�λ�Ĵ�����ֵ
	TL1 = *LowVal;  //�ڰ�λ�Ĵ�����ֵ
} 
#endif