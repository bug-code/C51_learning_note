#include "reg52.h"
#include "intrins.h"
typedef unsigned int uint;
typedef unsigned char uchar;
sbit LED0 = P2^0;
sbit LED1 = P2^1;
sbit LED2 = P2^2;
sbit LED3 = P2^3;
sbit LED4 = P2^4;
sbit LED5 = P2^5;
sbit LED6 = P2^6;
sbit LED7 = P2^7;
#define LED P2 //包含8个LED灯

void delay(uint i){
	while(i--){
	}
}					   
void main(){
	while(1){
         /*第一个LED闪烁*/
		/*LED0 = 0;
		delay(50000);
		LED0=1;
	    delay(50000);*/

		/*全部闪烁*/
		/*LED = 0xff;
		delay(50000);
		LED = 0x00;
		delay(50000);*/

		
		uint i;
		/*流水灯,右流*/
		/*LED = 0xfe;
		for(i=0 ; i<7;++i){
			delay(10000);
			LED = _crol_(LED , 1);
			delay(10000);
		}*/
		
		/*流水灯，左流*/
		/*LED = 0x7f;  //循环流保存左右流并注释该行即可
		for(i=0 ; i<7;++i){
			delay(10000);
			LED = _cror_(LED , 1);
			delay(10000);
		}*/
		 

		/*摩斯密码，SB .../_... 
		  不完美，需要用到多线程。前三个和后三个各自闪烁，每个灯各自线程控制，中间俩个灯常亮。
		*/
		/*
		LED = 0xE7;
		delay(50000);
		LED = 0x00;
		delay(50000); */

	} 
}