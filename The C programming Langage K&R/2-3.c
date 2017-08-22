#include<stdio.h>
#define TEST1 "0xff"
#define TEST2 "0X80"
int htoi(char s[]);
main()
{
	char s[] = TEST2;
	int n = htoi(s);
	printf("%d",n);
}
int htoi(char s[])
{
	int i;
	int n = 0;
	if(s[0] == '0')
	{
		if(s[1] == 'x' || s[1] == 'X')
		{
			for(i = 2;s[i] != '\0';++i)
			{
				if(s[i] >= '0' && s[i] <= '9')
				{
					n = 16 * n + s[i] - '0';
				}
				else if(s[i] >= 'a' && s[i] <= 'z')
				{
					n = 16 * n + s[i] - 'a' +10;
				}
				else if(s[i] >= 'A' && s[i] <= 'Z')
				{
					n = 16 * n + s[i] - 'A' +10;
				}
			}
			return n;
		}
	}
}
