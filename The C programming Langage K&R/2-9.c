#include<stdio.h>
void d_to_b(unsigned int x);
int bitcount(unsigned int x);
main()
{
	unsigned int x = 15;
	printf("%d\n",bitcount(x));
	return 0;
}
int bitcount(unsigned int x)
{
	int count;
	for(count = 0;x > 0;x &= x - 1)
		count++;
	return count;
}
void d_to_b(unsigned int x)
{
	int binary[100];
	int i = 0;
	while(x != 0)
	{
		binary[i++] = x & 1;
		x >>= 1; 
	}
	for(--i;i >= 0;--i)
		printf("%d",binary[i]);
}
