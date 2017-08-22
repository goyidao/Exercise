#include<stdio.h>
int itoa(int i,char a[],int pos);
int main()
{
	int i = 12222;
	char a[30];
	itoa(i,a,0);
	printf("%s\n",a);
	return 0;
}
int itoa(int i,char a[],int pos)//从pos开始存数 
{
	if(i /10 != 0)
	{
		pos = itoa(i/10,a,pos);
		a[pos++] = i % 10 + '0';
	}
	else
	{
		a[pos++] = i % 10 + '0';
		a[pos] = '\0';
	}
	return pos;
}
