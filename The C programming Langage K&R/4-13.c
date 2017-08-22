#include<stdio.h>
void reverse(char s[],int pos);//把a[0]---a[pos]的数组反向 
int getline(char line[],int lim);
int main()
{
	char s[100];
	int len;
	while((len = getline(s,100)) > 0)
	{
		reverse(s,4);
		printf("%s",s);
	}
	return 0;
}
void reverse(char s[],int pos)
{
	if(pos > 0)
	{
		int i;
		int last = s[pos];
		reverse(s,pos-1);
		for(i = pos-1;i>=0;--i)
		{
			s[i+1] = s[i];
		}
		s[0] = last;
	}
}
int getline(char line[],int lim)
{
	int i,c;
	for(i = 0;i < lim-1 && (c = getchar()) != EOF && c != '\n';++i)
		line[i] = c;
	if(c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}
