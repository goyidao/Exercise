#include<stdio.h>
#define MAXSIZE 100
int getline(char s[],int lim);
main()
{
	char s[MAXSIZE];
	int len;
	while((len = getline(s,MAXSIZE)) > 0)
	{
		printf("%s",s);
	}
}
int getline(char s[],int lim)
{
	int i;
	int c;
	for(i = 0;i < lim-1;++i)
	{
		if((c = getchar()) != EOF)
		{
			if(c != '\n')
			{
				s[i] = c;
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	if(c == '\n')
	{
		s[i++] = '\n';
	}
	s[i] = '\0';
	return i;
}
