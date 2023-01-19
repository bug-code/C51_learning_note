#ifndef _STEP_UTILS_H_
#define _STEP_UTILS_H_
#include "reg52.h"
#include "delay.h"
static unsigned char Speed=1;
/*步进电机引脚*/
sbit P10 = P1^0;
sbit P11 = P1^1;
sbit P12 = P1^2;
sbit P13 = P1^3;

/*按键引脚：
	默认不转
	K3功能：长按按前进
	K4功能:  长按后退
	K2功能：短按加速一级，长按减速
*/
sbit K3 = P3^2;	//外部中断0
sbit K4 = P3^3;	//外部中断1
sbit K2 = P3^0;	//按键检测
/*选择通电引脚*/
void Set_Step(unsigned char Step , unsigned char direct ){
	if(direct) Step = 7-Step;//*direct为0正转，1逆转
	switch(Step){
		case 0: P10=1,P11=0,P12=0,P13=0;break;//A
		case 1: P10=1,P11=1,P12=0,P13=0;break;//AB
		case 2: P10=0,P11=1,P12=0,P13=0;break;//B
		case 3: P10=0,P11=1,P12=1,P13=0;break;//BC
		case 4: P10=0,P11=0,P12=1,P13=0;break;//C
		case 5: P10=0,P11=0,P12=1,P13=1;break;//CD
		case 6: P10=0,P11=0,P12=0,P13=1;break;//D
		case 7: P10=1,P11=0,P12=0,P13=1;break;//DA
		default: break;
	}	
}

/*检测K2按键*/
void Speed_Update(){
	if(!K2){
		delay_1ms(100);//消抖并监测长按，长按阈值5ms
		if(!K2){//长按减速
			if(Speed<6) ++Speed;
		}else{
			if(Speed>1) --Speed;
		} 		
	}
}
#endif