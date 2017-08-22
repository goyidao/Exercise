#include<stdio.h>
#include<ctype.h> 
double atof(char s[]);
main()
{
	char s[] = "-3.1415123457";
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
	double pow;
	
	for(pos = 0;isspace(s[pos]);++pos);
	if(s[pos] == '-')
		sign = -1;
	else
		sign = 1;
	if(s[pos] == '-' || s[pos] == '+')
		++pos;
	for(y = 0.0;s[pos] != '.' && s[pos] != '\0';++pos)
	{
		y = y * 10.0 + s[pos] - '0'; 
	}
	if(s[pos] == '.')
	{
		pos++;
		for(pow = 1.0;s[pos] != '\0';++pos)
		{
			y = y * 10.0 + s[pos] - '0';
			pow *= 10.0; 
		}
		y = y / pow;
	}
	return y * sign;
}
