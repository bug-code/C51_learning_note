#ifndef _DIGIT_DISPLAY_H_
#define _DIGIT_DISPLAY_H_
#include "public.h"
//数码管位选端口
sbit P22=P2^2;
sbit P23=P2^3;
sbit P24=P2^4;


//选择数码管
void choose_digit_tube(const unsigned char);
//数码管显示
void digit_tube_show(const unsigned char);
//选择数码管并显示
void choose_and_show(const unsigned char,const unsigned char, 
					const unsigned char ,  unsigned char []);


#endif