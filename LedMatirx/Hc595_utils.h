#ifndef _HC595_UTILS_H
#define _HC595_UTILS_H
#include "reg52.h"
#include "delay.h"

sbit SHCP = P3^6; //移位寄存器时钟
sbit STCP = P3^5; //存储寄存器时钟
sbit SER = P3^4; //串行数据输入

/*写入数据到HC595芯片*/
void Write_2_Hc595(uchar dat){
	uint i;
	for(i=0;i<8;++i){
		/*获取高位*/
		SER = dat>>7;
		/*获得除高位后的数据*/
		dat<<=1;
		/*产生SHCP电压上升沿*/
		SHCP=0;
		delay_10us(1);//时延10us
		SHCP=1;//电压上升沿，写入移位寄存器
		
		
	}
	/*写入存储寄存器*/
	STCP=0;
	delay_10us(1);
	STCP=1;//STCP上升沿，写入存储寄存器
}

/*显示8*8点阵的一张图像*/
void show_pic(uchar *pic){//传入一张图像的数组
	uint j=100;
	while(j--){//循环若干次，留足视觉暂存
		uint i;
		for(i=0 ; i<8;++i){//一张图有8个数据，
			P0=~(0x80>>i);
			/*写入数据到HC595*/
			Write_2_Hc595(pic[i]);
			
			/*位清零，消残影*/
			delay_10us(1);
			Write_2_Hc595(0x00);
				
		}
	}


}
 



#endif