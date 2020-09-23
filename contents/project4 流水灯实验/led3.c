
#include<reg52.h>

void delay(unsigned int xms);

void main()
{
	int i=0;
	while(1)
	{
		P1 = 0xfe;//1111 1110
		for(i=0;i<8;i++)
		{
			delay(1000);
			P1 <<= 1;//P1 = P1<<1;
			P1 = P1 | 0x01;//	补掉一位被左移消灭掉的1
		}
	}

}

void delay(unsigned int xms)
	unsigned int i,j;
	for(i=xms;i>0;i--)	
		for(j=112;j>0;j--);
}
