#ifndef _DIGIT_DISPLAY_H_
#define _DIGIT_DISPLAY_H_
#include "public.h"
//�����λѡ�˿�
sbit P22=P2^2;
sbit P23=P2^3;
sbit P24=P2^4;


//ѡ�������
void choose_digit_tube(const unsigned char);
//�������ʾ
void digit_tube_show(const unsigned char);
//ѡ������ܲ���ʾ
void choose_and_show(const unsigned char,const unsigned char, 
					const unsigned char ,  unsigned char []);


#endif