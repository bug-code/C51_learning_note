#ifndef _HC595_UTILS_H
#define _HC595_UTILS_H
#include "reg52.h"
#include "delay.h"

sbit SHCP = P3^6; //��λ�Ĵ���ʱ��
sbit STCP = P3^5; //�洢�Ĵ���ʱ��
sbit SER = P3^4; //������������

/*д�����ݵ�HC595оƬ*/
void Write_2_Hc595(uchar dat){
	uint i;
	for(i=0;i<8;++i){
		/*��ȡ��λ*/
		SER = dat>>7;
		/*��ó���λ�������*/
		dat<<=1;
		/*����SHCP��ѹ������*/
		SHCP=0;
		delay_10us(1);//ʱ��10us
		SHCP=1;//��ѹ�����أ�д����λ�Ĵ���
		
		
	}
	/*д��洢�Ĵ���*/
	STCP=0;
	delay_10us(1);
	STCP=1;//STCP�����أ�д��洢�Ĵ���
}

/*��ʾ8*8�����һ��ͼ��*/
void show_pic(uchar *pic){//����һ��ͼ�������
	uint j=100;
	while(j--){//ѭ�����ɴΣ������Ӿ��ݴ�
		uint i;
		for(i=0 ; i<8;++i){//һ��ͼ��8�����ݣ�
			P0=~(0x80>>i);
			/*д�����ݵ�HC595*/
			Write_2_Hc595(pic[i]);
			
			/*λ���㣬����Ӱ*/
			delay_10us(1);
			Write_2_Hc595(0x00);
				
		}
	}


}
 



#endif