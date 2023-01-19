#include "reg52.h"
 
typedef unsigned int uint;
typedef unsigned char uchar;
sbit Button1=P3^1;//K1
sbit Button2=P3^0;//K2
sbit Button3=P3^2;//k3
sbit Button4=P3^3;//K4

sbit LED1 = P2^0;//LED1
sbit LED2 = P2^1;//LED2
sbit LED3 = P2^2;//LED3
sbit LED4 = P2^3;//LED4

void delay(uint i){
	while(i--){}
}

void main(){
	/*¼ì²â°´¼ü*/
	while(1){
		delay(10000);
		if(!Button1) LED1=!LED1;
		if(!Button2) LED2=!LED2;
		if(!Button3) LED3=!LED3;
		if(!Button4) LED4=!LED4;
		delay(10000);
	}
}