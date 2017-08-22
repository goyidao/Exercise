#include<stdio.h>
int binsearch(int x,int v[],int n);
main()
{
	int x = 3;
	int v[] = {0,1,2,3,4,5,6,7};
	int n = 8;
	printf("%d\n",binsearch(x,v,n));
}
int binsearch(int x,int v[],int n)
{
	int low,high,middle;
	low = 0;
	high = n - 1;
	middle = (low + high)/2;
	while(low < high && x != v[middle])
	{
		if(x < v[middle])
			high = middle - 1;
		else
			low = middle + 1;
		middle = (low + high)/2;
	}
	if(v[middle] == x)
		return middle;
	else
		return -1;
}
