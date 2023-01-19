#include "func_test.h"
#include "public.h"
#include "digit_display.h"
#include "Individual_keys.h"
#include "24c02.h"
/*
	功能：初始数码管右三位显示0；最大能写入的数据是255
	1.按K1键将数据写入到EEPROM内保存；
	2. 按K2键读取EEPROM内保存数据；
	3. 按K3键显示数据加1 
	4. 按K4键显示数据 清零；
*/
#define SlaveAdd 0xA0
#define DataAdd0 0
#define DataAdd1 1

sbit  BEEP=P2^5;


void func_test1(void){
	unsigned char  initVal=0;
	unsigned char loop=10;
	unsigned char key, writeDone;
	unsigned char  display_arr[3];
	while(1){
		key = key_scan(0); //独立按键扫描
		if(key==0) continue;
		if(key==1){
			writeDone=At24C02_write_byte(SlaveAdd , DataAdd1 ,initVal);//写入数据，默认写入成功			
			if(!writeDone){//写入成功，蜂鸣提示
				while(loop--){
					delay_10us(100);
					BEEP = !BEEP;
					delay_10us(100);
				}

			}

		}
		else if(key==2){
			initVal = At24C02_read_byte(SlaveAdd,DataAdd1,1);//读取数据，默认成功
		}
		else if(key==3) ++initVal;
		else if(key==4) initVal=0;

		display_arr[2] = initVal%100%10;
		display_arr[1] = initVal/10%10;
		display_arr[0] = initVal/100;

		choose_and_show(6,9,1, display_arr);
		

	}
}