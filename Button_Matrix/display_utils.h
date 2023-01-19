#ifndef __DISPLAY_UTILS_H__
#define __DISPLAY_UTILS_H__

#include "reg52.h"
sbit P22=P2^2;
sbit P23=P2^3;
sbit P24=P2^4;

void choose_display(uint i){
	switch(i){
		case 0: P24=1;P23=1;P22=1;break;
		case 1: P24=1;P23=1;P22=0;break;
 		case 2: P24=1;P23=0;P22=1;break;
		case 3: P24=1;P23=0;P22=0;break;
		case 4: P24=0;P23=1;P22=1;break;
		case 5: P24=0;P23=1;P22=0;break;
		case 6: P24=0;P23=0;P22=1;break;
		case 7: P24=0;P23=0;P22=0;break;
	}
}



#endif