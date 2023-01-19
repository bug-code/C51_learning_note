#include "reg52.h"
#include "delay.h"
#include "interrupt_utils.h"
#include "step_utils.h"


void main(){
	unsigned char display[] = {0x00,0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				  0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	Int0_Init(0);
	Int1_Init(0);
	while(1){
		Speed_Update();
		P0 = display[Speed+1]; //显示速度
	}
}
void Int0_Routine(void) interrupt 0{
	while(!K3){
		/*正转*/
		unsigned char i;
		for(i=0 ; i<8;++i){
			Set_Step(i,0);
			delay_1ms(Speed);
		}
	}

}
void Int1_Routine(void) interrupt 2{
	while(!K4){
			/*逆转*/
			unsigned char i;
			for(i=0 ; i<8;++i){
				Set_Step(i,1);
				delay_1ms(Speed);
			}	
	}

}