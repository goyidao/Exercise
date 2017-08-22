#include<stdio.h>
void escape(char s[],char t[]);
main()
{
	char t[] = "12\t34\n567\n";
	char s[11];
	printf("%s\n",t);
	escape(s,t);
}
void escape(char s[],char t[])
{
	int i,j;
	for(i = 0,j = 0;t[i] != '\0';++i)
	{
		switch(t[i]){
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}
	s[j] = '\0';
	printf("%s",s);
}
