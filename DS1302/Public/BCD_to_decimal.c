#include "BCD_to_decimal.h"
unsigned char bcd_to_decimal(unsigned char bcd ){
	return bcd/16*10+bcd%16;
}
unsigned char decimal_to_bcd(unsigned char dec){
	return dec/10*16+dec%10; 
}