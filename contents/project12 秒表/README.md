# 制作一个简单的秒表
显然我们先要配置定时器
```
int computeTH0(uint us)
{
    //
    return (65536 - ((int)(us / (OP * 12)))) / 256;
}
int computeTL0(uint us)
{
    return (65536 - ((int)(us / (OP * 12)))) % 256;
}
void timerInit()
{
    TMOD = 0x01; //定时器0选择工作方式1
    //初始值设置公式
    /*
    设要设定的秒数为t(单位是μs)这里以50ms为例就是50000μs
    先计算计数值=t/(1/11.0592*12)
    所以初始值TH0+TL0=65536-t
    但是由于是两个八位的寄存器，所以还要做相应的处理
    */
    TH0 = computeTH0(50000);
    TL0 = computeTL0(50000);
}
```

在我们检测到按键的时候，打开总中断，定时器0中断，启动定时器

```
void startTimer()
{
    EA = 1;  //打开总中断
    ET0 = 1; //打开定时器0中断
    TR0 = 1; //启动定时器0
}
```
同理
```
void stopTimer()
{
    EA = 0;
    ET0 = 0;
    TR0 = 0;
}
```
__其他地方都没什么难的，直接说难的__
这里我用了一个数组来装着数码管的四位数以及对应的数字
```
unsigned char code numTable[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d,
                                 0x07, 0x7f, 0x6f};
uchar timeNum[4] = {0};
```
并且在主循环里分别取他们出来
```
while ...
..
        timeNum[0] = min / 10;
        timeNum[1] = min % 10;
        timeNum[2] = sec / 10;
        timeNum[3] = sec % 10;
```
主要用了这两个函数去显示
```
void choice(uint n)
{
    //选择P2 ^ 4~7
    int i, j = 1;
    P2 = 0xff;
    for (i = 0; i < n; i++)
        j *= 2;
    P2 = P2 & (j + 0x0f);//这里防止蜂鸣器狗叫，所以让后面变成1
}
void display()
{
    int i;

    for (i = 4; i < 8; i++)
    {
        choice(i);
        NUM = numTable[timeNum[i - 4]];
        delay(5);
    }
}
```

关于具体的可以去看具体的[main.c](main.c)
