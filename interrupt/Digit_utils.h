#ifndef _DIGIT_UTILS_H
#define _DIGIT_UTILS_H
#include "reg52.h"
typedef unsigned int uint;
sbit P22=P2^2;
sbit P23=P2^3;
sbit P24=P2^4;

uint display[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				  0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};

void Choose_Digit(int i){
	switch(i){
				case 1: P24=1;P23=1;P22=1;break;
				case 2: P24=1;P23=1;P22=0;break;
 				case 3: P24=1;P23=0;P22=1;break;
				case 4: P24=1;P23=0;P22=0;break;
				case 5: P24=0;P23=1;P22=1;break;
				case 6: P24=0;P23=1;P22=0;break;
				case 7: P24=0;P23=0;P22=1;break;
				case 8: P24=0;P23=0;P22=0;break;
			}
}




#endif