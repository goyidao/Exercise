#include<stdio.h>
#include<stdlib.h>
void MergeSort2(int a[],int len);
void MergePass2(int a[],int k,int len);//排完之后k个一组有序，即k/2----->k
void Merge(int a[],int p,int q,int m);
int main()
{
	int i;
	int a[5] = {5,4,3,2,1};
	
	MergeSort2(a,5);
	for(i = 0;i < 5;++i)
		printf("%d%c",a[i],i == 4 ? '\n':',');
	return 0;
}
void MergeSort2(int a[],int len)
{
	int k = 2; 
	while(k/2 <= len)
	{
		MergePass2(a,k,len);
		k *= 2;
	}
	if(k<len)
		Merge(a,0,k-1,len);
}
void MergePass2(int a[],int k,int len)
{
	int i;
	for(i = 0;i+k < len;i += k)
		Merge(a,i,i+k/2-1,i+k-1);
	if(i+k/2-1 <= len-1)
		Merge(a,i,i+k/2-1,len-1);
}
void Merge(int a[],int p,int q,int m)
{
	int n1,n2;
	int i,j,k;
	int * l,* r;
	
	n1 = q - p + 1;
	n2 = m - q;
	l = (int *)malloc(sizeof(int)*n1);
	r = (int *)malloc(sizeof(int)*n2);
	for(i = 0;i < n1;++i)
		l[i] = a[p+i];
	for(j = 0;j < n2;++j)
		r[j] = a[q+1+j];
	for(i = j = 0,k = p;i < n1 && j < n2;++k)
		if(l[i] < r[j])
			a[k] = l[i++];
		else
			a[k] = r[j++];
	while(i < n1)
		a[k++] = l[i++];
	while(j < n2)
		a[k++] = r[j++];
}
