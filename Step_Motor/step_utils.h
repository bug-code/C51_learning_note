#ifndef _STEP_UTILS_H_
#define _STEP_UTILS_H_
#include "reg52.h"
#include "delay.h"
static unsigned char Speed=1;
/*�����������*/
sbit P10 = P1^0;
sbit P11 = P1^1;
sbit P12 = P1^2;
sbit P13 = P1^3;

/*�������ţ�
	Ĭ�ϲ�ת
	K3���ܣ�������ǰ��
	K4����:  ��������
	K2���ܣ��̰�����һ������������
*/
sbit K3 = P3^2;	//�ⲿ�ж�0
sbit K4 = P3^3;	//�ⲿ�ж�1
sbit K2 = P3^0;	//�������
/*ѡ��ͨ������*/
void Set_Step(unsigned char Step , unsigned char direct ){
	if(direct) Step = 7-Step;//*directΪ0��ת��1��ת
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

/*���K2����*/
void Speed_Update(){
	if(!K2){
		delay_1ms(100);//��������ⳤ����������ֵ5ms
		if(!K2){//��������
			if(Speed<6) ++Speed;
		}else{
			if(Speed>1) --Speed;
		} 		
	}
}
#endif