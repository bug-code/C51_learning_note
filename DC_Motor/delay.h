#ifndef _DELAY_H__
#define _DELAY_H__
typedef unsigned int uint;
typedef unsigned char uchar;

/*10us=1,时延为10us*/
void delay_10us(uint _10us){
	while(_10us--){}
}

/*1ms=1,时延为1ms*/
void delay_1ms(uint _1ms){
	 _1ms*=110;
	 while(_1ms--){
	 }
}

#endif