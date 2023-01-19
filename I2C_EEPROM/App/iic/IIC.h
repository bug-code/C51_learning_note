#ifndef _IIC_H_
#define _IIC_H_
#include "public.h"
/*IIC��������ͷ�ļ�*/
sbit IIC_SCL = P2^1;
sbit IIC_SDA = P2^0;

void IIC_start(void); //IIC�����ź�
void IIC_stop(void);//IICֹͣ�ź�
void IIC_SendACK(unsigned char );//IICӦ���ź�

unsigned char IIC_GetACK(void);//IIC�ȴ�Ӧ���յ������źţ����޷����ź�
unsigned char IIC_get_byte(const unsigned char);//IIC��ȡ���ݣ�����Ӧ����Ӧ��
unsigned char IIC_send_byte(const unsigned char );//IIC�����ź�
 
#endif