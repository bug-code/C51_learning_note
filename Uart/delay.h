#ifndef _DELAY_H__
#define _DELAY_H__
/*10us=1,时延为10us*/
void delay_10us(unsigned int _10us){
	while(_10us--){}
}
/*1ms=1,时延为1ms*/
void delay_1ms(unsigned int _1ms){
	 _1ms*=110;
	 while(_1ms--){
	 }
}
#endif