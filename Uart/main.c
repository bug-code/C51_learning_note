#include "Uart_Init.h"
#include "Scan_Button.h"
/*
	1.由于暂时无合适的显示设备，所以将单片机接收到的信息返回给电脑显示。
	2.可以通过矩阵键盘输入信息，按独立按键k3进行发送
*/
void main(){
   Int0_Init(0);//外部中断0初始化
   Uart_Init(0x20,0x50,0x80,0xFA);//串口中断初始化
   while(1){
	  char cha;
	  cha=Scan_Button();
	  if(cha)
	  	Send_buffer[Send_Num++] = cha;
   }
}
void Int0_Rountine() interrupt 0{ //按键矩阵输入完毕，按独立按键K3中断发送
	Uart_Send_String();
}
