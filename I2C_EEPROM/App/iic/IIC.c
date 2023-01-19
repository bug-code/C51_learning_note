#include "IIC.h"

//IIC启动信号
void IIC_start(void){
	
	IIC_SDA	= 1;
	IIC_SCL = 1;//SDA间隔了这个执行语句，大于其最小间隔0.25us
	IIC_SDA = 0; //产生SDA下降沿，起始信号
	IIC_SCL=0; //低电平期间才允许传输数据
}
//IIC停止信号 
void IIC_stop(void){
	IIC_SDA = 0;
	IIC_SCL = 1;//SDA间隔了这个执行语句，大于其最小间隔0.25us
	IIC_SDA = 1;//产生SDA上升沿，终止信号
}
//IIC发送应答信号，ack为1非应答，ack为0应答
void IIC_SendACK(const unsigned char ack){
	IIC_SDA = ack;//特定电平脉冲
	IIC_SCL = 1;//拉高电平，使SDA电平脉冲保持稳定
	IIC_SCL = 0;//以上ACK信号已产生，拉低电平使后续能传输数据
}
/*
	主机发送完数据后，接收从机发出的ACK信号,超过时间默认非应答，终止传输
	返回值ack: 0应答信号，1非应答信号
*/
unsigned char IIC_GetACK(void){

	unsigned char cnt=0;
	unsigned char ack;
	/*默认高电平(漏极开路+上拉电阻)，
	主机释放总线,因为设备是串联的，
	一个为低电平全为低电平*/

	IIC_SDA=1;
	IIC_SCL=1;
	while(IIC_SDA){
	   ++cnt;
	   if(cnt>100){
	   	  IIC_stop();
		  break;
	   } 
	}
	ack = IIC_SDA;
	IIC_SCL=0;
	/*总线释放后由从机接管，从机发送应答*/
	return ack;

}

/*
IIC获取数据，返回接收的数据byte
根据参数ack，确定发送非应答ack=1，或应答ack=0.
由于设备串联，漏极开路+上拉电阻，当某个设备SDA为0时，整个SDA上都为0.
因此接收设备将SDA置为1，接收设备释放SDA总线，让主机控制SDA数据总线，因为主机要发送数据。
*/
unsigned char IIC_get_byte(const unsigned char ack){
	 unsigned char i , byte=0x00;
	 IIC_SDA = 1;	 //根据时序图，接收数据时， 接收设备将SDA置1,释放总线控制权 
	 for(i=0 ; i<8 ; ++i){
	 	IIC_SCL =1;	  // 拉高SCL电平，使接收的数据有效
		if(IIC_SDA) byte |= (0x80>>i); // 根据主机控制的SDA,从高到低接收数据
		IIC_SCL=0; //拉低电平准备下一位数据接收
	 }
	 IIC_SendACK(ack);

	 return byte;
}
/*	关键：SCL低电平时，SDA才允许变化；SCL高电平时，SDA须保持稳定
	IIC发送信号。谁发送信号谁就为主机，谁就控制时钟线SCL、数据线SDA.
	当发送信号前，主机已经控制了SCL为低电平(函数IIC_start)。
	返回值：0发送成功，1发送失败
*/
unsigned char IIC_send_byte(const unsigned char dat){
	unsigned char i , ack;
	for(i=0 ; i<8 ; ++i){
		IIC_SDA = dat&(0x80>>i);//数据从高位到低位依次传输
		IIC_SCL = 1;//获取了数据，拉高SCL，保持SDA稳定
		IIC_SCL =0; // 拉低SCL，准备传输下一个数据	
	}

	ack = IIC_GetACK();//发送完数据，获取接收设备返回的ACK
	return ack;
}