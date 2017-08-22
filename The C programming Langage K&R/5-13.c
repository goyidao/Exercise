#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
void tail(int n);
int getline(char *line,int lim);//·µ»Ølen²»°üº¬'\0' 
int main(int argc,char *argv[])
{
	int n;
	if(argc == 2)
		n = atoi((*++argv)++);
	else
		n = 3;
	tail(n);
	return 0;
}
void tail(int n)
{
	char *lineptr[100];
	char *p;
	int linenum = 0;
	char line[100];
	int len;
	int i;
	while((len = getline(line,100)) > 0)
	{
		if(linenum < 100)
		{
			if(linenum < n)
			{
				p = (char *)malloc(len+1);
				strcpy(p,line);
				lineptr[linenum++] = p;
			}
			else
			{
				free(lineptr[0]);
				for(i = 1;i < n;++i)
				{
					lineptr[i-1] = lineptr[i];
				}
				p = (char *)malloc(len+1);
				strcpy(p,line);
				lineptr[n-1] = p;
				linenum++;
			}
		}
		else
			printf("error:buf full.\n");
	}
	for(i = 0;i < (linenum < n ? linenum : n);++i)
		printf("%s\n",lineptr[i]);
}
int getline(char *line,int lim)
{
	int c,i;
	for(i = 0;i < lim - 1 && (c=getchar()) != EOF && c != '\n';++i)
		*(line+i) = c;
	line[i] = '\0';
	return i;
}
