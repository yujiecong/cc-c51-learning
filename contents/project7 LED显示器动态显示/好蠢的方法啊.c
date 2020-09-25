/**********************************************************
*ʵ����������ܶ�̬��ʾ
*ʵ��Ч������4λһ�������������4λ��ʾ4����5���룬
*��������3λ��ʾ3����5���룬��������2λ��ʾ2����5���룬
*��������1λ��ʾ1,�������̲���ѭ��
*ע�⣺ÿλ�����֮�����ʱС��5ms���ɿ���4λ�����ͬʱ����
***********************************************************/
#include<reg52.h>
#define duan P0
#define uchar unsigned char 
sbit wei1 = P2^4;//�����һλ�����
sbit wei2 = P2^5;//����ڶ�λ�����
sbit wei3 = P2^6;//�������λ�����
sbit wei4 = P2^7;//�������λ�����

uchar code sz[17]={0x3f , 0x06 , 0x5b ,0x4f , 0x66 , 0x6d ,0x7d ,
0x07 , 0x7f , 0x6f ,0x77 , 0x7c , 0x39 , 0x5e , 0x79 , 0x71 , 0x00};				

void delay(unsigned int xms)				
{
	unsigned int i,j;
	for(i=xms;i>0;i--)		      //i=xms����ʱԼxms����
		for(j=112;j>0;j--);
}

void main()
{
	   while(1)
	   {
	   		duan = sz[4];
			wei1 = 0;
			wei2 = 0;
			wei3 = 0;
			wei4 = 1;
			delay(5);
			duan = sz[3];
			wei1 = 0;
			wei2 = 0;
			wei3 = 1;
			wei4 = 0;
			delay(5);
			duan = sz[2];
			wei1 = 0;
			wei2 = 1;
			wei3 = 0;
			wei4 = 0;
			delay(5);
			duan = sz[1];
			wei1 = 1;
			wei2 = 0;
			wei3 = 0;
			wei4 = 0;
			delay(5);
	   }
}
