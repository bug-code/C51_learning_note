#include "Scan_Button.h"
#include " display_utils.h"

void delay(uint i){
	while(i--){}
}
void main(){
	uint buffer[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	int index=0;	
	while(1){		
		uint line=4;
		uint col=4;
		uint i;
		/*获取矩阵按键位置*/
		delay(6000);
		line = get_line();
		col = get_col();
		delay(6000);
		if(line<4 && col<4){
			if(index>7) index=0;
			buffer[index++]= Table16[line][col];
		}	
		for(i=0 ; i<8 ; ++i){
			choose_display(i);
			delay(100);
			P0=buffer[i];
			delay(100);
			P0=0x00;
		} 	
	}
}