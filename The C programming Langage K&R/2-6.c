#include<stdio.h>
unsigned int setbits(unsigned int x,int p,int n,unsigned int y);
main()
{
	unsigned int x = 0x00000030;
	int p = 4;
	int n = 4;
	unsigned int y = 0x00000004;
	printf("%u\n",setbits(x,p,n,y));
}
unsigned int setbits(unsigned int x,int p,int n,unsigned int y)
{
	return ((~(~0 << n) & y) << p) | (~(~(~0 << n) << p) & x);
}
