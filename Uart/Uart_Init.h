#ifndef __UART_INIT_H__
#define __UART_INIT_H__
#include "interrupt_utils.h"
unsigned char data_buffer[10];//存储接收的数据
unsigned char Send_buffer[10];//要发送的数据
unsigned char Num=0;
unsigned char Send_Num=0;
/*设置串口寄存器参数
		1.设置串口寄存器
		2.设置波特率参数
*/
void Set_Uart( unsigned char *Uart_Reg_mode ,  unsigned char *Baud_mode){
	SCON = *Uart_Reg_mode;
	PCON |= *Baud_mode;
}
/*串口初始化函数*/
void Uart_Init(unsigned char T1_Mode , unsigned char Uart_Reg_mode , 
				 unsigned char Baud_mode ,  unsigned char Init_Val ){
	  
	  Set_Uart(&Uart_Reg_mode,  &Baud_mode);
	  Timer1_Init(&T1_Mode ,&Init_Val , &Init_Val );
	  ES=1;	//打开串口中断允许位
	  ET1=0;//关闭定时器中断1的允许位	  
}
/*串口发送一个字符*/
void Uart_Send_byte(unsigned char dat){
	SBUF = dat;
	while(!TI);//发出中断，TI硬件置1，跳出循环
	TI=0;//重置，取消本次中断	
	
}
/*串口发送一串字符*/
void Uart_Send_String(){
	unsigned char i;
	for(i=0 ; i!=Send_Num;++i){
		Uart_Send_byte(Send_buffer[i]);
	}
	Send_Num=0;
}
/*串口接受数据(不超过10位)*/
void UART_Routine( ) interrupt 4{  
  	RI=0;		//将接收中断标志清0 
	if(Num>9){	 //超出缓存大小，覆盖从头开始存储
		Num=0;
	}	
	data_buffer[Num++] = SBUF;	
	
	/*由于单片机暂无合适的显示设备，将接收到的数据返回给电脑*/
	Uart_Send_byte(data_buffer[Num-1]);
}
#endif