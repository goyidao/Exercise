#include<ctype.h> // isdigit 
#include"calculator.h"
#include<stdio.h>//EOF

int getop(char s[])
{
	int c;
	int i = 0;
	
	while((c = getch()) == ' ' || c == '\t');
	if(isdigit(c) || c == '.' || c == '-')
	{
		s[i++] = c;
		if(c == '-')
		{
			if(!isdigit(c = getch()) && c != '.')//是减号 
			{
				ungetch(c);
				s[i] = '\0';
				return '-';
			}
			else//是负数 
				ungetch(c);
		}
		while(isdigit(c = getch()) || c == '.')
		{
			s[i++] = c;
		}
		s[i] = '\0'; 
		if(c != EOF)
			ungetch(c);
		return NUMBER;
	}
	else//说明是操作符或者函数名或者变量名或者非法字符 
	{
		s[0] = c;
		if(islower(c))
		{
			while(islower(c = getch()))
				s[++i] = c; 
			ungetch(c);
		}
		s[++i] = '\0'; 
		if(i > 1)
			return NAME;
		else
			return s[0];
	} 
}
