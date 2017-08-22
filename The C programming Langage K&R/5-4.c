#include<stdio.h>
int strend(char *s,char *t);
int main()
{
	char s[] = "1234";
	char t[] = "234";
	int res = strend(s,t);
	printf("%d",res);
}
int strend(char *s,char *t)
{
	char *sb = s;
	char *tb = t;
	while(*s)
		s++;
	while(*t)
		t++;
	for(;*t==*s;--t,--s)
	{
		if(t==tb || s==sb)
			break;
	}
	if(*t==*s && t==tb && *t != '\0')
		return 1;
	else
		return 0;
}
