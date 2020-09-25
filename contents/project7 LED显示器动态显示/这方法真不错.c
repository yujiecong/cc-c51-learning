#include <REG52.H>
#include <stdlib.h>
// P2  4567是数码管
// sfr P2    = 0xA0;1010 0000
#define NUM P0
typedef unsigned int uint;
void choice(uint n);
void choice(uint n)
{
    //选择P2 ^ 4~7
    int i, j = 1;
    for (i = 0; i < n; i++)
        j *= 2;
    P2 = P2 ^ (j);
}
void delay(unsigned int xms)
{
    unsigned int i, j;
    for (i = xms; i > 0; i--) //i=xms即延时约xms毫秒
        for (j = 112; j > 0; j--)
            ;
}
void main()
{
    //
    int i;
    P2 = 0x08;

    while (1)
    {
        for (i = 4; i < 8; i++)
        {
            choice(i);
            NUM = 0x06;
            delay(500);
        }
        /* code */
    }
}
