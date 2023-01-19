#include "digit_display.h"

unsigned char display[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				  0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};

//选择数码管
void choose_digit_tube(const unsigned char i){
	if(i>0&&i<9){
		switch(i){
			case 1: P24=1;P23=1;P22=1;break;
			case 2: P24=1;P23=1;P22=0;break;
			case 3: P24=1;P23=0;P22=1;break;
			case 4: P24=1;P23=0;P22=0;break;
			case 5: P24=0;P23=1;P22=1;break;
			case 6: P24=0;P23=1;P22=0;break;
			case 7: P24=0;P23=0;P22=1;break;
			case 8: P24=0;P23=0;P22=0;break;
		}	
	}
}

//数码管显示
void digit_tube_show(const unsigned char dat){

	P0=dat;
	delay_10us(100);
	P0=0x00; //消影
}

//选择数码管并显示
void choose_and_show(const unsigned char beg,const unsigned char end,
					 const unsigned char step ,  unsigned char arr_dat[]){
	unsigned char i;
	unsigned char j;
	for(i=beg , j=0 ; i<end ; i+=step){
		choose_digit_tube(i);
		digit_tube_show(display[arr_dat[j++]]);
	}					 
}

