#ifndef _24C02_H_
#define _24C02_H_

#include "public.h"

/*д��һ���ֽ���24C02
��������ַadd �� ����dat
���أ�0д��ɹ���1д��ʧ��
*/
unsigned char At24C02_write_byte(const unsigned char, 
								const unsigned char
							 , const unsigned char);
/*
	��24C02��ȡһ������
������ Ҫ��ȡ�豸�ĵ�ַ
���أ���ȡ������
*/
unsigned char At24C02_read_byte(const unsigned char, 
							  const unsigned char,
							  const unsigned char);
#endif 