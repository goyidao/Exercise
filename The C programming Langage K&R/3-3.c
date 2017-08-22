#include<stdio.h>
#define MAXSIZE 100
void expand(char s1[],char s2[]);
main()
{
	char s1[] = "a-c";
	char s2[MAXSIZE];
	expand(s1,s2);
	printf("%s\n%s",s1,s2);
}
void expand(char s1[],char s2[])
{
	int last;
	int i,j;
	char c;
	
	i = j = 0;
	while((c = s1[i++]) != '\0')
	{
		if(s1[i] == '-' && s1[i+1] >=c)
		{
			i++;
			while(c < s1[i])
				s2[j++] = c++;
		}
		else
			s2[j++] = c;	
	}
	s2[j] = '\0';
} 
