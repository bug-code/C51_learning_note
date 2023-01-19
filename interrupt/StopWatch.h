#ifndef _STOPWATCH_H_
#define _STOPWATCH_H_
#include "Digit_utils.h"
/*缓存显示内容*/
int Second=0;
int Min=0;
int Hour=0;

int ShowBuffer[] = {0 , 0 , 0 , 0 ,0 , 0  };

void ClearBuffer(){
	int i;
	for(i=0 ; i<6;++i){
		ShowBuffer[i]=0;
	}
	Hour=0;
	Min=0;
	Second=0;

}

void Split_Time(){
	ShowBuffer[0] = Hour / 10;
	ShowBuffer[1] = Hour %10;
	ShowBuffer[2] = Min / 10;
	ShowBuffer[3] = Min % 10;
	ShowBuffer[4] = Second /10;
	ShowBuffer[5] = Second %10;
} 

void Show(){
	int i;
	Split_Time();
	for(i=0; i<6 ; i+=2){
		Choose_Digit(i+1);
		P0 = display[ShowBuffer[i]];		
		P0=0x00;

		Choose_Digit(i+2);
		P0= display[ShowBuffer[i+1]] | 0x80;//按位或是为了增加小数点
		P0=0x00;
	}	 
}

#endif