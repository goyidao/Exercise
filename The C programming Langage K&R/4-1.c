#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
char t[] = "llo";
int getline(char line[],int lim);
int strindex_right(char s[],char t[]);
int strindex_right_new(char s[],char t[]);
int main()
{
	char line[MAXSIZE];
	int found = 0;
	int pos;
	while(getline(line,MAXSIZE) > 0)
	{
		if((pos = strindex_right(line,t)) != -1)
		{
			printf("%d\n",pos);
			printf("%s",line);
			++found;
		}
	}
	return found;
}
int strindex_right_new(char s[],char t[])
{
	int i,j,k;
	int sl,tl;
	
	sl = strlen(s);
	tl = strlen(t);
	for(i = sl - tl;i >= 0;--i)
	{
		for(j = i,k = 0;t[k] != '\0' && s[j] == t[k];++j,++k);
		if(k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
int strindex_right(char s[],char t[])
{
	int i,j,k;
	reverse(s);
	reverse(t);
	for(i = 0;s[i] != '\0';++i)
	{
		for(j = i,k = 0;t[k] != '\0' && t[k] == s[j];++j,++k);
		if(k > 0 && t[k] == '\0')
		{
			reverse(s);
			return (strlen(s) - j);
		}
	}
	return -1;
}
int reverse(char s[])
{
	int temp,i,n;
	for(n = 0;s[n] != '\0';++n);
	for(i = 0;i < n/2;++i)
	{
		temp = s[n - 1 -i];
		s[n - 1 -i] = s[i];
		s[i] = temp;
	}
}
int getline(char line[],int lim)
{
	int c,i=0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
	{
		line[i++] = c;
	}
	if(c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}
