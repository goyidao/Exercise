#include<stdio.h>
int any(char s1[],char s2[]);
main()
{
	char s1[] = "0123456";
	char s2[] = "1";
	int pos;
	pos = any(s1,s2);
	printf("%d\n",pos);
}
int any(char s1[],char s2[])
{
	int i,j;
	for(i = 0;s2[i] != '\0';++i)
	{
		for(j = 0;s1[j] != '\0' && s1[j] != s2[i];++j);
		if(s1[j] != '\0')
			return j;
	}
	if(s2[i] == '\0')
		return -1;
}
