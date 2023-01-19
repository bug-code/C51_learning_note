#include "Scan_Button.h"
#include " display_utils.h"
sbit back_Button = P3^1;
void delay(uint i){
	while(i--){}
}
void main(){
	uint buffer[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	int index=0;
	while(1){		
		uint line;
		uint col;
		int tmp;
		delay(10000);
		/*检测是否回退显示*/
		if(!back_Button){			
			if(index<=0){
				index=0;
			}else{
				--index;	
			}
			buffer[index]=0x00;
		}
		delay(10000);
		
		/*获取矩阵按键位置*/
		line = get_line();
		col = get_col();
		if(line<4 && col<4){
			buffer[index]= Table16[line][col];
		} 
		
		for(tmp=index;tmp>=0 ;--tmp){
			delay(50000);
			choose_display(tmp);
			P0=buffer[tmp];
			delay(50000);
		}
		++index;		
	}
}
