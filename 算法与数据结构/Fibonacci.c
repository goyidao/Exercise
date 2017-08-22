#include<stdio.h>
void Fib(int a[],int i);
int main()
{
	int i;
	int a[40];
	Fib(a,39);
	for(i = 0;i < 40;++i)
		printf("%d\t",a[i]);
	return 0;
}
void Fib(int a[],int i)
{
	if(i == 0)
		a[i] = 0;
	else if(i == 1)
		a[i] = 1;
	else
	{
		Fib(a,i-1);
		Fib(a,i-2);
		a[i] = a[i-1]+a[i-2];
	}
}
