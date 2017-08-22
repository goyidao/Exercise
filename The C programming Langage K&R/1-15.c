#include<stdio.h>
float convert(float fahar);
main()
{
	float fahar,celsius;
	int lower,higher,step;
	
	lower = 0;
	higher = 300;
	step = 20;
	
	for(fahar = lower;fahar <= higher;fahar = fahar + step)
	{
		celsius = convert(fahar);
		printf("%3.0f	%6.1f\n",fahar,celsius);
	}
	return 0;
 }

float convert(float fahar)
{
	float celsius;
	celsius = 5.0/9.0*(fahar - 32);
	return celsius;
}
