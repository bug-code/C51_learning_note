#ifndef _24C02_H_
#define _24C02_H_

#include "public.h"

/*写入一个字节至24C02
参数：地址add ， 数据dat
返回：0写入成功，1写入失败
*/
unsigned char At24C02_write_byte(const unsigned char, 
								const unsigned char
							 , const unsigned char);
/*
	从24C02读取一个数据
参数： 要读取设备的地址
返回：读取的数据
*/
unsigned char At24C02_read_byte(const unsigned char, 
							  const unsigned char,
							  const unsigned char);
#endif 