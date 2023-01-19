#ifndef __SCAN_BUTTON_H__
#define __SCAN_BUTTON_H__
/*扫描矩阵按键*/
#include "reg52.h"
#include "delay.h"
typedef unsigned int uint;
typedef unsigned char uchar;

sbit line0 = P1^7;
sbit line1 = P1^6;
sbit line2 = P1^5;
sbit line3 = P1^4;
sbit col0 = P1^3;
sbit col1 = P1^2;
sbit col2 = P1^1;
sbit col3 = P1^0;

char  Table16[4][4] = {{'a','b','c','d'},
						{'e','f','g','h'},
						{'i','j','k','l'},
						{'m','n','o','p'}
						} ;
/*确定行*/
uint get_line(void){
	uint retVal=4;
	col0=0;
	col1=0;
	col2=0;
	col3=0;
	if(!line0) retVal=0;
	if(!line1) retVal=1;
	if(!line2) retVal=2;
	if(!line3) retVal=3;
	col0=1;
	col1=1;
	col2=1;
	col3=1;
	return retVal;
}
/*确定列*/
uint get_col(void){
	uint retVal=4;
	line0=0;
	line1=0;
	line2=0;
	line3=0;
	if(!col0) retVal=0;
	if(!col1) retVal=1;
	if(!col2) retVal=2;
	if(!col3) retVal=3;
	line0=1;
	line1=1;
	line2=1;
	line3=1;
	return retVal;
}
/*监测按键，并返回按键值*/
char Scan_Button(){
	uint row;
	uint col;
	delay_10us(6000);
	row = get_line();
	col = get_col();
	delay_10us(6000);
	if(row!=4&&col!=4)
		return Table16[row][col];
	return 0;
}	
#endif