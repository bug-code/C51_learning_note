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
#define LED P2 //����8��LED��

void delay(uint i){
	while(i--){
	}
}					   
void main(){
	while(1){
         /*��һ��LED��˸*/
		/*LED0 = 0;
		delay(50000);
		LED0=1;
	    delay(50000);*/

		/*ȫ����˸*/
		/*LED = 0xff;
		delay(50000);
		LED = 0x00;
		delay(50000);*/

		
		uint i;
		/*��ˮ��,����*/
		/*LED = 0xfe;
		for(i=0 ; i<7;++i){
			delay(10000);
			LED = _crol_(LED , 1);
			delay(10000);
		}*/
		
		/*��ˮ�ƣ�����*/
		/*LED = 0x7f;  //ѭ����������������ע�͸��м���
		for(i=0 ; i<7;++i){
			delay(10000);
			LED = _cror_(LED , 1);
			delay(10000);
		}*/
		 

		/*Ħ˹���룬SB .../_... 
		  ����������Ҫ�õ����̡߳�ǰ�����ͺ�����������˸��ÿ���Ƹ����߳̿��ƣ��м������Ƴ�����
		*/
		/*
		LED = 0xE7;
		delay(50000);
		LED = 0x00;
		delay(50000); */

	} 
}