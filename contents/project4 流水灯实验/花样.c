/**********************BST-M51实验开发板例程************************
*  平台：BST-M51 + Keil U4 + STC89C52
*  名称：流水灯模块实验
*  公司：深圳市亚博软件开发有限公司       
*  日期：2015-6
*  晶振:11.0592MHZ
*  说明：免费开源，不提供源代码分析.
******************************************************************/
/*---------------------------------------------------------------*/
#include<reg52.h> //包含头文件，一般情况不需要改动，
                  //头文件包含特殊功能寄存器的定义

/*------------------------------------------------
                  花样表格
------------------------------------------------*/
unsigned char code seg[]={0x7f,0xbf,0xdf,0xef,
						  0xf7,0xfb,0xfd,0xfe,
						  0xff,0xff,0x00,0x00,
						  0x55,0x55,0xaa,0xaa
						  };//rom允许情况可以无限添加

void Delay(unsigned int t); //函数声明
/*------------------------------------------------
                    主函数
------------------------------------------------*/
main()
{
 unsigned char i;                //定义一个无符号字符型
								 //局部变量 i 取值范围 0~255
	P1=0xFF;//P1口置1
 while(1)
      {
	  P1=0xFE;                   //第1个LED亮
      for(i=0;i<8;i++)
	     {
		 Delay(20000);
	     P1 <<=1;
		 }

      P1=0x7F;                   //第8个LED亮
      for(i=0;i<8;i++)
	     {
		 Delay(20000);
	     P1 >>=1;
		 }

      P1=0xFE;                  //第1个LED亮
      for(i=0;i<8;i++)
	     {
		 Delay(20000);
	     P1 <<=1;
		 P1 |=0x01;
		 }

	  P1=0x7F;                  //第8个LED亮
      for(i=0;i<8;i++)
	     {
		 Delay(20000);
	     P1 >>=1;
		 P1 |=0x80;
		 }
      //下面通过查表方法获得花样参数
      for(i=0;i<16;i++)//查表可以简单的显示各种花样 实用性更强
	     {
		 Delay(20000);
         P1=seg[i];
		 }
      }

}

/*------------------------------------------------
 延时函数，含有输入参数 unsigned int t，无返回值
 unsigned int 是定义无符号整形变量，其值的范围是
 0~65535
------------------------------------------------*/
void Delay(unsigned int t)
{
 while(--t);
}
