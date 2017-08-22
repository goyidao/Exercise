#include<ctype.h> // isdigit 
#include"calculator.h"
#include<stdio.h>//EOF

int getop(char s[])
{
	int c;
	int i = 0;
	
	while((c = getch()) == ' ' || c == '\t');
	if(isdigit(c))
	{
		s[i++] = c;
		while(isdigit(c = getch()))
		{
			s[i++] = c;
		}
		s[i] = '\0'; 
		ungetch(c);
		return NUMBER;
	}
	else//说明是操作符或者函'\n'
	{
		s[0] = c;
		s[1] = '\0';
		if(c == '\n' || c == '(' || c == ')' || c == EOF)
			return c;
		else
			return OPERATOR;
	} 
}
