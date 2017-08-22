#include<stdio.h>
void itoa(int n,char s[],int width);
main()
{
	char s[100];
	itoa(-100,s,5);
	printf("%s\n",s);
	return 0;
}
void itoa(int n,char s[],int width)
{
	void reverse(char s[],int n);
	int sign;
	int y;
	int pos;

	pos = 0;
	sign = n;
	do{
			y = n % 10;
			s[pos++] = (y < 0 ? -y : y) + '0';
			--width;
			n /= 10;
	}while(n != 0);
	if(sign < 0)
	{
		s[pos++] = '-';
		--width;
	}
	while(width > 0)
	{
		s[pos++] = ' ';
		--width;
	}
	s[pos] = '\0';
	reverse(s,pos);
}
void reverse(char s[],int n)
{
	int temp,i;
	for(i = 0;i < n/2;++i)
	{
		temp = s[n - 1 - i];
		s[n - 1 - i] = s[i];
		s[i] = temp;
	}
}
