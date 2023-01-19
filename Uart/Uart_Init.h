#ifndef __UART_INIT_H__
#define __UART_INIT_H__
#include "interrupt_utils.h"
unsigned char data_buffer[10];//�洢���յ�����
unsigned char Send_buffer[10];//Ҫ���͵�����
unsigned char Num=0;
unsigned char Send_Num=0;
/*���ô��ڼĴ�������
		1.���ô��ڼĴ���
		2.���ò����ʲ���
*/
void Set_Uart( unsigned char *Uart_Reg_mode ,  unsigned char *Baud_mode){
	SCON = *Uart_Reg_mode;
	PCON |= *Baud_mode;
}
/*���ڳ�ʼ������*/
void Uart_Init(unsigned char T1_Mode , unsigned char Uart_Reg_mode , 
				 unsigned char Baud_mode ,  unsigned char Init_Val ){
	  
	  Set_Uart(&Uart_Reg_mode,  &Baud_mode);
	  Timer1_Init(&T1_Mode ,&Init_Val , &Init_Val );
	  ES=1;	//�򿪴����ж�����λ
	  ET1=0;//�رն�ʱ���ж�1������λ	  
}
/*���ڷ���һ���ַ�*/
void Uart_Send_byte(unsigned char dat){
	SBUF = dat;
	while(!TI);//�����жϣ�TIӲ����1������ѭ��
	TI=0;//���ã�ȡ�������ж�	
	
}
/*���ڷ���һ���ַ�*/
void Uart_Send_String(){
	unsigned char i;
	for(i=0 ; i!=Send_Num;++i){
		Uart_Send_byte(Send_buffer[i]);
	}
	Send_Num=0;
}
/*���ڽ�������(������10λ)*/
void UART_Routine( ) interrupt 4{  
  	RI=0;		//�������жϱ�־��0 
	if(Num>9){	 //���������С�����Ǵ�ͷ��ʼ�洢
		Num=0;
	}	
	data_buffer[Num++] = SBUF;	
	
	/*���ڵ�Ƭ�����޺��ʵ���ʾ�豸�������յ������ݷ��ظ�����*/
	Uart_Send_byte(data_buffer[Num-1]);
}
#endif