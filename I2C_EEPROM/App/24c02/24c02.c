#include "24c02.h"
#include "IIC.h"
/*д��һ���ֽ���24C02
�������ӻ���ַSlaveAdd �� �ӻ�������д���ַDataAdd , ����dat
���أ�0д��ɹ���1д��ʧ��
*/
unsigned char At24C02_write_byte(const unsigned char SlaveAdd , 
								const unsigned char DataAdd 
							 , const unsigned char dat){
		unsigned char ack;
		IIC_start();
		ack=IIC_send_byte(SlaveAdd);//����д�������ȡ���ͷ���
		if(ack) return 1;
		ack  = IIC_send_byte(DataAdd);//����Ҫд�����������ݣ�����ȡ���ͷ���
		if(ack) return 1;
		ack = IIC_send_byte(dat);//��������
		if(ack) return 1;
		IIC_stop();//���������ֹ����
		return 0;
}
/*
	��24C02��ȡһ������,������ ��Ӧ�����
������ Ҫ��ȡ�豸�Ĵӻ���ַSlaveAdd, Ҫ��ȡ�����ݵ�ַ���������0Ӧ��/1��Ӧ��ack 
���أ���ȡ������
*/
unsigned char At24C02_read_byte(const unsigned char SlaveAdd , 
							  const unsigned char DataAdd ,
							  const unsigned char ack){
	unsigned char dat , feedback;
	IIC_start();
	feedback = IIC_send_byte(SlaveAdd);//����������ַ��д�������ȡ���ͷ���,�������Ӧ�����
	feedback = IIC_send_byte(DataAdd);//���Ͷ�ȡ���ݵĵ�ַ
	IIC_start();//����ʱ��ͼ��������������
   	feedback = IIC_send_byte(SlaveAdd|0x01);//�����ڼ��ַ�Ͷ�����
    dat = IIC_get_byte(ack);//��ȡ���ݣ�������Ӧ�����
	return dat;
}