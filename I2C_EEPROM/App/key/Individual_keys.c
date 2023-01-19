#include "individual_keys.h"

unsigned char key_scan(const unsigned char mode){
	static unsigned char key=1;
	if(mode) key=1;
	if (key&&(!KEY1 || !KEY2 || !KEY3  || !KEY4 )){
		delay_1ms(10);//Ê±ÑÓÏû¶¶
		key=0;
		if(!KEY1){
			return KEY1_PRESS;
		}else if(!KEY2){
			return KEY2_PRESS;
		}else if(!KEY3){
			return KEY3_PRESS;
		}else if(!KEY4){
			return KEY4_PRESS;
		}
	}else if(KEY1&&KEY2&&KEY3&&KEY4){
		key=1;
	}

	return KEY_UNPRESS;	
}