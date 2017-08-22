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
			if(!isdigit(c = getch()) && c != '.')//�Ǽ��� 
			{
				ungetch(c);
				s[i] = '\0';
				return '-';
			}
			else//�Ǹ��� 
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
	else//˵���ǲ��������ߺ��������߱��������߷Ƿ��ַ� 
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
