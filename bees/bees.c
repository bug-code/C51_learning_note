#include "reg52.h"
typedef unsigned int uint  ;
typedef unsigned char uchar	;
sbit BEEP = P2^5 ;

void delay(uint i){
	 while(i--){
	 }
}

void main(){
	uint i=100;//��������Ƶ��
	while(1){
		while(i--){
			/*//�������죬��LED6��˸
			delay(1000);
			BEEP = !BEEP;
			delay(1000);
			 */

			 /*������ռ�ȣ��Ӷ���������,��ռ�ȣ��ߵ�ƽռһ�����ڵı���*/
			 BEEP=1;
			 delay(100);
			 BEEP=0;
			 delay(10);
		}
		BEEP=1;	 //�رյ�����LED
		i=0;//�رշ�����	
	}
}