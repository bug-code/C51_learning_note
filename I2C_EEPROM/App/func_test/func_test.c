#include "func_test.h"
#include "public.h"
#include "digit_display.h"
#include "Individual_keys.h"
#include "24c02.h"
/*
	���ܣ���ʼ���������λ��ʾ0�������д���������255
	1.��K1��������д�뵽EEPROM�ڱ��棻
	2. ��K2����ȡEEPROM�ڱ������ݣ�
	3. ��K3����ʾ���ݼ�1 
	4. ��K4����ʾ���� ���㣻
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
		key = key_scan(0); //��������ɨ��
		if(key==0) continue;
		if(key==1){
			writeDone=At24C02_write_byte(SlaveAdd , DataAdd1 ,initVal);//д�����ݣ�Ĭ��д��ɹ�			
			if(!writeDone){//д��ɹ���������ʾ
				while(loop--){
					delay_10us(100);
					BEEP = !BEEP;
					delay_10us(100);
				}

			}

		}
		else if(key==2){
			initVal = At24C02_read_byte(SlaveAdd,DataAdd1,1);//��ȡ���ݣ�Ĭ�ϳɹ�
		}
		else if(key==3) ++initVal;
		else if(key==4) initVal=0;

		display_arr[2] = initVal%100%10;
		display_arr[1] = initVal/10%10;
		display_arr[0] = initVal/100;

		choose_and_show(6,9,1, display_arr);
		

	}
}