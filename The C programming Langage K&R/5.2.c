#include<stdio.h>
#include<ctype.h>
int getch();
void ungetch(int c);
int getint(int *pn);
int buf = -9;//空的时候缓冲区为-9
int main()
{
	int n;
	int c;
	while((c = getint(&n)) > 0)
	{
		printf("%d\n",n);
	}
	return 0;
}
int getint(int *pn)
{
	int c,sign;
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
	for(*pn = 0;isdigit(c);c = getch())
		*pn = *pn * 10 + c - '0';
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
