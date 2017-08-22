#include<stdio.h>
#include<limits.h>
main()
{
	printf("signed char max:%d\tmin:%d\tunsigned char max:%u\n",SCHAR_MAX,SCHAR_MIN,UCHAR_MAX);
	printf("signed short max:%d\tmin:%d\tunsigned short max:%u\n",SHRT_MAX,SHRT_MIN,USHRT_MAX);
	printf("signed int max:%d\tmin:%d\tunsigned int max:%u\n",INT_MAX,INT_MIN,UINT_MAX);
	printf("signed long max:%ld\tmin:%ld\tunsigned long max:%ul\n",LONG_MAX,LONG_MIN,ULONG_MAX);
}
