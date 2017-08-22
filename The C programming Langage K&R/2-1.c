#include<stdio.h>
main()
{
	printf("signed char min:%d\tmax:%d\n",
		(char)(((unsigned char)~0>>1) + 1),(char)((unsigned char)~0>>1));
	printf("signed short min:%d\tmax:%d\n",
		(short)(((unsigned short)~0>>1) + 1),(short)((unsigned short)~0>>1));
	printf("signed int min:%d\tmax:%d\n",
		(int)(((unsigned int)~0>>1) + 1),(int)((unsigned int)~0>>1));
	printf("signed long min:%ld\tmax:%ld\n",
		(long)((~(0UL) >> 1) + 1),(long)(~(0UL) >> 1));
		
	printf("unsigned char max:%u\n",(unsigned char)~0);
	printf("unsigned short max:%u\n",(unsigned short)~0);
	printf("unsigned int max:%u\n",(unsigned int)~0);
	printf("unsigned long max:%lu\n",(unsigned long)~0);
}
