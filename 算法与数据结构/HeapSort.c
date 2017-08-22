#include<stdio.h>
void HeapSort(int a[],int len);
void HeapAdjust(int a[],int s,int m);
void swap(int a[],int i,int j);
int main()
{
	int i;
	
	int a[5] = {5,4,3,2,1};
	HeapSort(a,5);
	for(i = 0;i < 5;++i)
		printf("%d%c",a[i],i == 4 ? '\n' : ',');
	return 0;
}
void HeapSort(int a[],int len)
{
	int i;
	for(i = len/2 - 1;i >= 0;--i)//½¨¶Ñ
		HeapAdjust(a,i,len);
	for(i = len - 1;i > 0;--i)//µ÷Õû¶Ñ
	{
		swap(a,0,i);
		HeapAdjust(a,0,i);
	}
}
void HeapAdjust(int a[],int s,int m)
{
	int j;
	int temp;
	
	temp = a[s];
	for(j = s*2+1;j <= m-1;j = j*2+1)
	{
		if(j < m-1 && a[j] < a[j+1])
			++j;
		if(temp > a[j])
			break;
		a[s] = a[j];
		s = j;
	}
	a[s] = temp;
}
void swap(int a[],int i,int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
