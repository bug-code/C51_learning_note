#include "interrupt_utils.h"
#include "StopWatch.h"
sbit k1=P3^1;
sbit k3=P3^2;
sbit BEEP = P2^5 ;
static int _50ms=0;
void main(){
	
	Int0_Init(1);//外部中断0初始化
	Timer0_Init(0x01 , 0x4c , 0x00);//定时器中断0初始化
	while(1){
		Show();
	}	
}

void Int0_Routine(void) interrupt 0{//K3外部中断，终止计数，显示数值
	while(1){
	  	Show();
	  	if(k1==0){//外部按键清0
			ClearBuffer();
			break;
		}	
	} 	
}
void Timer0_Routine(void) interrupt 1{ //定时器中断0，秒表计数
	++_50ms;
	if(_50ms==20){//中断一次50ms,中断20次1s
		BEEP = !BEEP;//中断同时蜂鸣器响应
		++Second;
		_50ms =0;
		if(Second==60){
			++Min;
			Second=0;
			if(Min==60){
				++Hour;
				Min=0;
			}
		}
	}
		
	 
}