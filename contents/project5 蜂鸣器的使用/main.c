/**********************************************
*ʵ������ ������ʵ��
*ʵ��Ч����������¼��ȥ�� �����������εε�����
**********************************************/
#include<reg52.h>

#define on 0
#define off 1
sbit fm = P2^3;

void delay(unsigned int xms)				
{
	unsigned int i,j;
	for(i=xms;i>0;i--)		      //i=xms����
		for(j=112;j>0;j--);
}

void main()
{
	while(1)
	{
		fm = on;//P2^3 = 0;��������
		delay(100);
		fm = off;
		delay(100);
	}
}
