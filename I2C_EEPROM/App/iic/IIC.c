#include "IIC.h"

//IIC�����ź�
void IIC_start(void){
	
	IIC_SDA	= 1;
	IIC_SCL = 1;//SDA��������ִ����䣬��������С���0.25us
	IIC_SDA = 0; //����SDA�½��أ���ʼ�ź�
	IIC_SCL=0; //�͵�ƽ�ڼ������������
}
//IICֹͣ�ź� 
void IIC_stop(void){
	IIC_SDA = 0;
	IIC_SCL = 1;//SDA��������ִ����䣬��������С���0.25us
	IIC_SDA = 1;//����SDA�����أ���ֹ�ź�
}
//IIC����Ӧ���źţ�ackΪ1��Ӧ��ackΪ0Ӧ��
void IIC_SendACK(const unsigned char ack){
	IIC_SDA = ack;//�ض���ƽ����
	IIC_SCL = 1;//���ߵ�ƽ��ʹSDA��ƽ���屣���ȶ�
	IIC_SCL = 0;//����ACK�ź��Ѳ��������͵�ƽʹ�����ܴ�������
}
/*
	�������������ݺ󣬽��մӻ�������ACK�ź�,����ʱ��Ĭ�Ϸ�Ӧ����ֹ����
	����ֵack: 0Ӧ���źţ�1��Ӧ���ź�
*/
unsigned char IIC_GetACK(void){

	unsigned char cnt=0;
	unsigned char ack;
	/*Ĭ�ϸߵ�ƽ(©����·+��������)��
	�����ͷ�����,��Ϊ�豸�Ǵ����ģ�
	һ��Ϊ�͵�ƽȫΪ�͵�ƽ*/

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
	/*�����ͷź��ɴӻ��ӹܣ��ӻ�����Ӧ��*/
	return ack;

}

/*
IIC��ȡ���ݣ����ؽ��յ�����byte
���ݲ���ack��ȷ�����ͷ�Ӧ��ack=1����Ӧ��ack=0.
�����豸������©����·+�������裬��ĳ���豸SDAΪ0ʱ������SDA�϶�Ϊ0.
��˽����豸��SDA��Ϊ1�������豸�ͷ�SDA���ߣ�����������SDA�������ߣ���Ϊ����Ҫ�������ݡ�
*/
unsigned char IIC_get_byte(const unsigned char ack){
	 unsigned char i , byte=0x00;
	 IIC_SDA = 1;	 //����ʱ��ͼ����������ʱ�� �����豸��SDA��1,�ͷ����߿���Ȩ 
	 for(i=0 ; i<8 ; ++i){
	 	IIC_SCL =1;	  // ����SCL��ƽ��ʹ���յ�������Ч
		if(IIC_SDA) byte |= (0x80>>i); // �����������Ƶ�SDA,�Ӹߵ��ͽ�������
		IIC_SCL=0; //���͵�ƽ׼����һλ���ݽ���
	 }
	 IIC_SendACK(ack);

	 return byte;
}
/*	�ؼ���SCL�͵�ƽʱ��SDA������仯��SCL�ߵ�ƽʱ��SDA�뱣���ȶ�
	IIC�����źš�˭�����ź�˭��Ϊ������˭�Ϳ���ʱ����SCL��������SDA.
	�������ź�ǰ�������Ѿ�������SCLΪ�͵�ƽ(����IIC_start)��
	����ֵ��0���ͳɹ���1����ʧ��
*/
unsigned char IIC_send_byte(const unsigned char dat){
	unsigned char i , ack;
	for(i=0 ; i<8 ; ++i){
		IIC_SDA = dat&(0x80>>i);//���ݴӸ�λ����λ���δ���
		IIC_SCL = 1;//��ȡ�����ݣ�����SCL������SDA�ȶ�
		IIC_SCL =0; // ����SCL��׼��������һ������	
	}

	ack = IIC_GetACK();//���������ݣ���ȡ�����豸���ص�ACK
	return ack;
}