#include<stdio.h>
unsigned int rightrot(unsigned int x,int n);
main()
{
	unsigned int x = 0x00000001;
	int n = 31;
	printf("%u\n",rightrot(x,n));
}
unsigned int rightrot(unsigned int x,int n)
{
	int i;
	int wordlength();
	for(i = 1;i <= n;++i)
	{
		x = (x >> 1) | ((x & 1) << (wordlength() - 1));
	}
	return x;
}
int wordlength()
{
	int i;
	unsigned int temp = ~0;
	for(i = 0;temp > 0;++i)
	{
		temp = temp >> 1;
	}
	return i;
}
