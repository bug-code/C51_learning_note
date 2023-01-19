#include "DS1302.h"

/*DS1302≥ı ºªØ*/
void DS1302_init(void){
	CE=0;
	SCLK=0;
}

void DS1302_Write_byte( unsigned char dat){
	unsigned char i;
	CE=0;
	SCLK=0;
	delay_10us(1);
	CE=1;

	for(i=0;i<8;++i){
		IO = dat&(0x01<<i);
		SCLK =1;
		delay_10us(1);
		SCLK=0;
	}
	CE=0;
}
void DS1302_Write( unsigned char Add ,  unsigned char dat){
	DS1302_Write_byte(Add);
	DS1302_Write_byte(dat);

}
unsigned char DS1302_Read_byte(void){
	unsigned char i;
	unsigned char retVal=0;
	unsigned char tmp_IO;
	CE=0;
	SCLK=1;
	delay_10us(1);
	CE=1;

	for(i=0;i<8;++i){
		tmp_IO = IO;
		retVal |= (tmp_IO<<i);
		SCLK=0;
		delay_10us(1);
		SCLK=1;
	}
	delay_10us(1);
	CE=0;
	SCLK=0;
	return retVal;

}
unsigned char DS1302_Read( unsigned char Add ){
	unsigned char dat;
	DS1302_Write_byte(Add);
	delay_10us(1);
	dat = DS1302_Read_byte();
	return dat;
}