#ifndef _INDIVIDUAL_KEYS_H_
#define _INDIVIDUAL_KEYS_H_
#include "public.h"
//��������������ƽ�
sbit KEY1=P3^1;
sbit KEY2=P3^0;
sbit KEY3=P3^2;
sbit KEY4=P3^3;

//ʹ�ú궨������������µļ�ֵ
#define KEY1_PRESS	1
#define KEY2_PRESS	2
#define KEY3_PRESS	3
#define KEY4_PRESS	4
#define KEY_UNPRESS	0

unsigned char key_scan(const unsigned char );
#endif