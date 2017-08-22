#include<stdio.h>
#include<ctype.h>
//#include<stdlib.h>
double atof(char s[]);
main()
{
	char s[] = "-123.89e-2";
	double y;
	
	y = atof(s);
	printf("%f\n",y);
	return 0;
}
double atof(char s[])
{
	int sign;
	int pos;
	double y;
	int signd;
	double pow;
	double temp;
	
	for(pos = 0;isspace(s[pos]);++pos);
	if(s[pos] == '-')
		sign = -1;
	else
		sign = 1;
	if(s[pos] == '-' || s[pos] == '+')
		++pos;
	for(y = 0.0;s[pos] != '.' && s[pos] != '\0' && s[pos] != 'e' && s[pos] != 'E';++pos)
	{
		y = y * 10.0 + s[pos] - '0'; 
	}
	if(s[pos] == '.')
	{
		pos++;
		for(pow = 1.0;s[pos] != '\0' && s[pos] != 'e' && s[pos] != 'E';++pos)
		{
			y = y * 10.0 + s[pos] - '0';
			pow *= 10.0; 
		}
		y = y / pow;
		y *= sign;
	}
	if(s[pos] == 'e' || s[pos] == 'E')
	{
		pos++;
		if(s[pos] == '-')
			signd = -1;
		else
			signd = 1;
		if(s[pos] == '+' || s[pos] == '-')
			pos++;
		for(temp = 0.0;s[pos] != '\0';++pos)
			temp = temp * 10 + (s[pos] - '0');
		if(signd == -1)
			while(temp > 0)
			{
				y *= 0.1;
				temp--;
			}
		else
			while(temp > 0)
			{
				y *= 10;
				temp--;
			}
	}
	return y;
}
