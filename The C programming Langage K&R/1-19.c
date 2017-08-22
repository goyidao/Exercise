#include<stdio.h>
#define MAXSIZE 20
void reverse(char s[]);
int getline(char s[],int lim);
main()
{
	char line[MAXSIZE];
	int len;
	while((len = getline(line,MAXSIZE)) != 0)
	{
		reverse(line);
		printf("%s\n",line);
	}
}
void reverse(char s[])
{
	int i,n;
	char temp;
	for(i = 0;s[i] != '\0';++i);
	n = i;
	for(--i;i >= n/2;--i)
	{
		temp = s[n - 1 - i];
		s[n - 1 - i] = s[i];
		s[i] = temp;
	}
}
int getline(char s[],int lim)
{
	char c;
	int i;
	for(i = 0;i < lim -1 && (c = getchar()) != EOF && c != '\n';++i)
		s[i] = c;
	s[i] = '\0';
	return i;
}
