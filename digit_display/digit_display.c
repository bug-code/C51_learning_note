#include "reg52.h"
typedef unsigned int uint;
sbit P22=P2^2;
sbit P23=P2^3;
sbit P24=P2^4;

uint display[] = {0x00,0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				  0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void delay(uint i){
	while(i--){
	}
}

void main(){
	/*数码管显示*/
	while(1){
		uint i;
		for( i=1 ; i<9 ; ++i){
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
			/*控制时延即可控制是流水灯式显示还是全部显示*/
			delay(100);
			P0 = display[i];
			delay(100);
			P0=display[0];
		}
	}
}