#include<ctype.h> // isdigit 
#include"calculator.h"
#include<stdio.h>//EOF
#include<string.h>

#define MAXLINESIZE 100

char line[MAXLINESIZE];
int pos = 0;

int getop(char s[]) //��line[]��ȡ���������߲������ŵ�s[]�� 
{
	int c;
	int i;
	
	i = 0;
	if(line[pos] == '\0') //�ж� line[]�Ƿ���� 
	{
		if(getline(line,MAXLINESIZE) == 0)
			return EOF;
		else
			pos = 0;
	}
	while((c = line[pos++]) == ' ' || c == '\t');
	if(isdigit(c) || c == '.' || c == '-')
	{
		s[i++] = c;
		if(c == '-')
		{
			if(!isdigit(c = line[pos]) && c != '.')//�Ǽ��� 
			{
				s[i] = '\0';
				return '-';
			}
		}
		while(isdigit(c = line[pos++]) || c == '.')
		{
			s[i++] = c;
		}
		s[i] = '\0'; 
		pos--;
		return NUMBER;
	}
	else//˵���ǲ��������ߺ��������߱��������߷Ƿ��ַ� 
	{
		s[0] = c;
		if(islower(c))
		{
			while(islower(c = line[pos++]))
				s[++i] = c; 
			pos--;
		}
		s[++i] = '\0'; 
		if(strlen(s) > 1)
			return NAME;
		else
			return s[0];
	} 
}
