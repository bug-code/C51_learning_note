#include "Uart_Init.h"
#include "Scan_Button.h"
/*
	1.������ʱ�޺��ʵ���ʾ�豸�����Խ���Ƭ�����յ�����Ϣ���ظ�������ʾ��
	2.����ͨ���������������Ϣ������������k3���з���
*/
void main(){
   Int0_Init(0);//�ⲿ�ж�0��ʼ��
   Uart_Init(0x20,0x50,0x80,0xFA);//�����жϳ�ʼ��
   while(1){
	  char cha;
	  cha=Scan_Button();
	  if(cha)
	  	Send_buffer[Send_Num++] = cha;
   }
}
void Int0_Rountine() interrupt 0{ //��������������ϣ�����������K3�жϷ���
	Uart_Send_String();
}
