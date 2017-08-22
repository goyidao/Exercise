#include<stdio.h>
#include<stdlib.h>
void MergeSort3(int SR[],int len);
void MergePass3(int SR[],int TR[],int k,int len);
void Merge3(int a[],int b[],int p,int m,int q);
int main()
{
	int i;
	int a[] = {5,4,3,2,1};
	MergeSort3(a,5);
	for(i = 0;i < 5;++i)
		printf("%d%c",a[i],i == 4 ? ' ':',');
	return 0;
}
void MergeSort3(int SR[],int len)
{
	int *TR = (int *)malloc(sizeof(int) * len);
	int k = 1;
	while(k < len)
	{
		MergePass3(SR,TR,k,len);
		k *= 2;
		MergePass3(TR,SR,k,len);
		k *= 2; 
	}
}
void MergePass3(int SR[],int TR[],int k,int len)//将相邻的k个一组的子序列两两归并 
{
	int i;
	int j;
	for(i = 0;i+2*k-1<=len-1;i += 2*k)
		Merge3(SR,TR,i,i+k-1,i+2*k-1);
	if(i+k-1 < len-1)//最后剩下一个长度为k的子序列以及一个不到k的子序列 
		Merge3(SR,TR,i,i+k-1,len-1);
	else
		for(j = i;j<len;++j)
			TR[j] = SR[j]; 
}
void Merge3(int SR[],int TR[],int p,int m,int q)
{
	int i,j,k;
	for(i = p,j = m+1,k = p;i <= m && j <= q;++k)
	{
		if(SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	while(i <= m)
		TR[k++] = SR[i++];
	while(j <= q)
		TR[k++] = SR[j++];
}
