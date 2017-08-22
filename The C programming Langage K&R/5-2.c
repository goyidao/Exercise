#include<stdio.h>
#include<ctype.h>
int getch();
void ungetch(int c);
int getfloat(double *pn);
int buf = -9;//空的时候缓冲区为-9
int main()
{
	double a;
	int c;
	while((c = getfloat(&a)) > 0)
	{
		printf("%f\n",a);
	}
	return 0;
}
int getfloat(double *pn)
{
	int c,sign,temp;
	while(isspace(c = getch()));
	if(!isdigit(c) && c != '-' && c != '+')
	{
		ungetch(c);
		return 0;
	}
	if(c == '-')
		sign = -1;
	else
		sign = 1;
	if(c == '-' || c == '+')
		c = getch();
	for(*pn = 0;isdigit(c);c = getch())//获取整数部分 
		*pn = *pn * 10.0 + c - '0';
	if(c == '.')
	{
		temp = 1;
		c = getch();
		for(;isdigit(c);c = getch())
		{
			*pn = *pn * 10 + c - '0';
			temp *= 10;
		}
		*pn /= temp;
	}
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
	return c;
}
int getch()
{
	int temp;
	if(buf == -9)
		return getchar();
	else
	{
		temp = buf;
		buf = -9;
		return temp;
	}
}
void ungetch(int c)
{
	if(buf == -9)
		buf = c;
	else
		printf("error:can not ungetch.\n");
}
