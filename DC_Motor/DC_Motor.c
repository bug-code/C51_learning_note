#include "reg52.h"
#include "interrupt_utils.h"
sbit P10=P1^0;
sbit K3 = P3^2;
void main(){	
	Int0_Init(0);
	P10=0;
	while(1){
	}
}
void Int0_Routine(void) interrupt 0{
	 while(!K3){
	 	P10=1;
	 }
	 P10=0;
}