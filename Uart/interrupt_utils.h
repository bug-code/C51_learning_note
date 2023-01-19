#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_
#include "reg52.h"
/*中断初始化*/

/*外部中断0*/
void Int0_Init(const unsigned char *mode){//外部中断0的触发方式，0低电平触发，1下降沿触发
	EA=1;//总中断允许位
	EX0=1;//外部中断0允许位
	IT0=*mode;	
}
/*外部中断1*/
void Int1_Init(const unsigned char *mode){//外部中断1的触发方式，0低电平触发，1下降沿触发
	EA=1;//总中断允许位
	EX1=1;//外部中断0允许位
	IT1=*mode;	
}

void Timer0_Init(const unsigned char *mode ,const unsigned char *HighVal , const unsigned char *LowVal ){
	EA=1;//打开中断总允许位
	ET0=1;//打开T0中断允许位
	TR0=1;//定时/计数器中断0开始工作
	TMOD |= *mode;//设置T0工作模式
	TH0 = *HighVal; //高八位寄存器初值
	TL0 = *LowVal;  //第八位寄存器初值
} 

void Timer1_Init(const unsigned char *mode ,const unsigned char *HighVal , const unsigned char *LowVal ){
	EA=1;//打开中断总允许位
	ET1=1;//打开T0中断允许位
	TR1=1;//定时/计数器中断0开始工作
	TMOD |= *mode;//设置T0工作模式
	TH1 = *HighVal; //高八位寄存器初值
	TL1 = *LowVal;  //第八位寄存器初值
} 
#endif