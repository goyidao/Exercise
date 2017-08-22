#include<stdio.h>
void printn(int n);
int main()
{
	int n;
	
	n = 123;
	printn(n);
	return 0;
}
void printn(int n)
{
	if(n / 10)
		printn(n / 10);
	putchar(n % 10 + '0');
}
