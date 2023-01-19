#include "reg52.h"
typedef unsigned int uint  ;
typedef unsigned char uchar	;
sbit BEEP = P2^5 ;

void delay(uint i){
	 while(i--){
	 }
}

void main(){
	uint i=100;//调整脉冲频率
	while(1){
		while(i--){
			/*//蜂鸣器响，和LED6闪烁
			delay(1000);
			BEEP = !BEEP;
			delay(1000);
			 */

			 /*调整空占比，从而调整音量,空占比：高电平占一个周期的比例*/
			 BEEP=1;
			 delay(100);
			 BEEP=0;
			 delay(10);
		}
		BEEP=1;	 //关闭第六个LED
		i=0;//关闭蜂鸣器	
	}
}