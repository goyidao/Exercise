#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d\n",c);
	printf("%.3f\n",(a+b+c)/3.0);
	return 0;
}
