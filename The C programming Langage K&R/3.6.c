#include<stdio.h>
#define MAXSIZE 10
void itoa(int i,char a[]);
void reverse(char a[],int n);
main()
{
	int i = -15;
	char a[MAXSIZE];
	itoa(i,a);
}
void itoa(int i,char a[])
{
	int pos = 0;
	int sign;
	
	if((sign = i) < 0)
		i = -i;
	do{
		a[pos++] = i % 10 + '0';
		i /= 10;
	}while(i);
	if(sign < 0)
		a[pos++] = '-';
	a[pos] = '\0';
	reverse(a,pos);
}
void reverse(char a[],int n)
{
	int i,temp;
	
	for(i = 0;i < n/2;++i)
	{
		temp = a[n - 1 - i];
		a[n - 1 - i] = a[i];
		a[i] = temp;
	}
	printf("%s\n",a);
}
