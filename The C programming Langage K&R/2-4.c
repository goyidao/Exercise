#include<stdio.h>
void squeeze(char s1[],char s2[]);
main()
{
	char s1[] = "abc1234567";
	char s2[] = "abc";
	squeeze(s1,s2);
	printf("%s\n",s1);
	return 0;
}
void squeeze(char s1[],char s2[])
{
	int i,j;
	int temp;
	i = 0;
	while(s1[i] != '\0')
	{
		for(j = 0;s2[j] != '\0' && s2[j] != s1[i];++j);
		if(s2[j] != '\0')
		{
			for(temp = i;s1[temp] != '\0';++temp)
			{
				s1[temp] = s1[temp + 1];
			}
		}
		else
			++i;
	}
}
