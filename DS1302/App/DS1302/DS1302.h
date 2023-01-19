#ifndef _DS1302_H_
#define _DS1302_H_
#include "public.h"
sbit SCLK = P3^6;
sbit IO = P3^4;
sbit CE = P3^5;

void DS1302_init(void);
void DS1302_Write_byte( unsigned char );
void DS1302_Write(unsigned char  ,  unsigned char );
unsigned char DS1302_Read_byte(void);
unsigned char DS1302_Read( unsigned char  );
#endif