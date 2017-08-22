#include<stdio.h>
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
	for(count = 0;x > 0;x >>= 1)
		if(x & 1)
			++count; 
	return count; 
}
