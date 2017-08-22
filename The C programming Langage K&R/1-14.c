#include<stdio.h>
main()
{
	int num[10];
	int u_le[26];
	int l_le[26];
	int i,j;
	int c;
	/*initialization*/
	for(i = 0;i < 10;++i)
	{
		num[i] = 0;
	}
	for(i = 0;i < 26;++i)
	{
		u_le[i] = 0;
	}
	for(i = 0;i < 26;++i)
	{
		l_le[i] = 0;
	}
	/*process*/
	while((c = getchar()) != EOF)
	{
		if(c >= '0' && c <= '9')
		{
			++num[c - '0'];
		}
		else if(c >= 'A' && c <= 'Z')
		{
			++u_le[c -'A'];
		}
		else if(c >= 'a' && c <= 'z')
		{
			++l_le[c -'a'];
		}		
	}
	/*print*/
	for(i = 0;i < 10;++i)
	{
		printf("%c|",i + '0');
		for(j = 1;j <= num[i];++j)
		{
			printf("*");
		}
		printf("(%d)\n",num[i]);
	}
	for(i = 0;i < 26;++i)
	{
		printf("%c|",i + 'A');
		for(j = 1;j <= u_le[i];++j)
		{
			printf("*");
		}
		printf("(%d)\n",u_le[i]);
	}
	for(i = 0;i < 26;++i)
	{
		printf("%c|",i + 'a');
		for(j = 1;j <= l_le[i];++j)
		{
			printf("*");
		}
		printf("(%d)\n",l_le[i]);
	}
	
}
