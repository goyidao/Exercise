#include<stdio.h>
#include"calculator.h"

int buffer = -1;//´æÒ»¸ö×Ö·û 

int getch()
{
	int temp;
	if(buffer == -1)
		return getchar();
	else
	{
		temp = buffer;
		buffer = -1;
		return temp;
	}
}
void ungetch(int c)
{
	if(buffer != -1)
		printf("error:buffer full,can not ungetch%c\n",c);
	else
		buffer = c;
}
