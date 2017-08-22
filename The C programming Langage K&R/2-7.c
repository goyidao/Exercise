#include<stdio.h>
unsigned int revert(unsigned int x,int p,int n);
main()
{
	unsigned int x = 0x00000004;
	int p = 3;
	int n = 4;
	printf("%u",revert(x,p,n));
	return 0;
}
unsigned int revert(unsigned int x,int p,int n)
{
	return (~(~0 << n) << (p + 1 -n)) ^ x;
}
