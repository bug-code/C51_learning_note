#include "interrupt_utils.h"
#include "StopWatch.h"
sbit k1=P3^1;
sbit k3=P3^2;
sbit BEEP = P2^5 ;
static int _50ms=0;
void main(){
	
	Int0_Init(1);//�ⲿ�ж�0��ʼ��
	Timer0_Init(0x01 , 0x4c , 0x00);//��ʱ���ж�0��ʼ��
	while(1){
		Show();
	}	
}

void Int0_Routine(void) interrupt 0{//K3�ⲿ�жϣ���ֹ��������ʾ��ֵ
	while(1){
	  	Show();
	  	if(k1==0){//�ⲿ������0
			ClearBuffer();
			break;
		}	
	} 	
}
void Timer0_Routine(void) interrupt 1{ //��ʱ���ж�0��������
	++_50ms;
	if(_50ms==20){//�ж�һ��50ms,�ж�20��1s
		BEEP = !BEEP;//�ж�ͬʱ��������Ӧ
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