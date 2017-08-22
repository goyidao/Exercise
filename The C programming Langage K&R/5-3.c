#include<stdio.h>
void strcat(char *s,char *t);
main()
{
	char s[100] = "012345";
	char t[] = "0123456789";
	strcat(s,t);
	printf("%s\n",s);
}
void strcat(char *s,char *t)
{
	while(*s++);
	s--;
	while(*s++ = *t++);
}
