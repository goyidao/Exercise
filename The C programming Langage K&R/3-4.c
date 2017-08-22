#include<stdio.h>
void reverse(char s[],int n);
void itoa(int i,char s[]);
main()
{
	char s[100];
	itoa(-10,s);
	printf("%s",s);
	return 0;
}
void itoa(int i,char s[])
{
	int sign;
	int y;
	int pos;
	
	pos = 0;
	sign = i;
	do{
		y = i % 10;
		s[pos++] = (y > 0 ? y : -y) + '0';
		i /= 10; 
	}while(i != 0);
	if(sign < 0)
		s[pos++] = '-';
	s[pos] = '\0';
	reverse(s,pos);
}
	void reverse(char s[],int n)
	{
		int i,c;
		for(i = 0;i < n/2;++i)
		{
			c = s[n - 1 - i];
			s[n - 1 -i] = s[i];
			s[i] = c;
		}
	}
