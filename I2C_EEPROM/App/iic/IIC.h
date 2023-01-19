#ifndef _IIC_H_
#define _IIC_H_
#include "public.h"
/*IIC总线驱动头文件*/
sbit IIC_SCL = P2^1;
sbit IIC_SDA = P2^0;

void IIC_start(void); //IIC启动信号
void IIC_stop(void);//IIC停止信号
void IIC_SendACK(unsigned char );//IIC应答信号

unsigned char IIC_GetACK(void);//IIC等待应答，收到反馈信号，或无反馈信号
unsigned char IIC_get_byte(const unsigned char);//IIC获取数据，返回应答或非应答
unsigned char IIC_send_byte(const unsigned char );//IIC发送信号
 
#endif