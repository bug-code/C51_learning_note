#include "24c02.h"
#include "IIC.h"
/*写入一个字节至24C02
参数：从机地址SlaveAdd ， 从机中数据写入地址DataAdd , 数据dat
返回：0写入成功，1写入失败
*/
unsigned char At24C02_write_byte(const unsigned char SlaveAdd , 
								const unsigned char DataAdd 
							 , const unsigned char dat){
		unsigned char ack;
		IIC_start();
		ack=IIC_send_byte(SlaveAdd);//发送写命令，并获取发送发聩
		if(ack) return 1;
		ack  = IIC_send_byte(DataAdd);//发送要写入器件的数据，并获取发送反馈
		if(ack) return 1;
		ack = IIC_send_byte(dat);//发送数据
		if(ack) return 1;
		IIC_stop();//发送完成终止传输
		return 0;
}
/*
	从24C02读取一个数据,不处理 非应答情况
参数： 要读取设备的从机地址SlaveAdd, 要读取的数据地址，接收完后，0应答/1非应答ack 
返回：读取的数据
*/
unsigned char At24C02_read_byte(const unsigned char SlaveAdd , 
							  const unsigned char DataAdd ,
							  const unsigned char ack){
	unsigned char dat , feedback;
	IIC_start();
	feedback = IIC_send_byte(SlaveAdd);//发送器件地址和写命令，并获取发送反馈,不处理非应答情况
	feedback = IIC_send_byte(DataAdd);//发送读取数据的地址
	IIC_start();//根据时序图，重启数据总线
   	feedback = IIC_send_byte(SlaveAdd|0x01);//发送期间地址和读命令
    dat = IIC_get_byte(ack);//获取数据，并发送应答情况
	return dat;
}