#include<stdio.h>
int buf = -2;
int getword(char *word,int lim);
int getch();
void ungetch(int c);
int main()
{
	char word[100];
	int c;
	while((c = getword(word,100)) != EOF)
	{
		printf("%s\n",word);
	}
	return 0;
}
int getword(char *word,int lim)//lim也包含'\0'的空间 
{
	int c;
	char *w = word;
	while(isspace(c = getch()));
	if(c == EOF)
	{
		*w = '\0';
		return c;
	}
	else
	{
		if(isalpha(c) || c == '#' || c =='_')
		{
			*w = c;
			for(w++;--lim >= 0;w++)
			{
				if(!isalnum(*w = getch()) && *w != '_')
				{
					ungetch(*w);
					break;
				}
			}
			*w = '\0';
			return word[0];
		}
		else if(c == '\"' || c == '\'')
		{	
			*w = c;
			for(w++;--lim > 0;w++)
			{
				if((*w = getch()) == '\\')
				{
					*(++w) = getch();
					if(*w == EOF)
					{
						*w = '\0';
						return word[0];
					}
				}
				else if(*w == c)
				{
					*(++w) = '\0';
					return word[0];
				}
				else if(*w == EOF)
				{
					*w = '\0';
					return word[0];
				}		
			}
		}
		else if(c == '/')
		{
			int d;
			if((d = getch()) == '*')
			{
				while((d = getch()) != '*');
				if((d = getch()) == '/')
				{
					*w = '\0';
					return -1;
				}
			}
		}
	}
	return c;
}
int getch()
{
	int temp;
	if(buf == -2)
		return getchar();
	else
	{
		temp = buf;
		buf = -2;
		return temp;
	}
}
void ungetch(int c)
{
	if(buf == -2)
		buf = c;
	else
		printf("error:can not ungetch.\n");
}
