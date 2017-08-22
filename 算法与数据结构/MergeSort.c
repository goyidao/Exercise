#include<stdio.h>
#include<stdlib.h>
void Merge(int a[],int p,int q,int r);//合并待排序列中a[]中a[p]-a[q]和a[q+1]-a[r]
void MergeSort(int a[],int i,int j);//对a[]中的元素a[i]-a[j]归并排序 
int main()
{
	int i;
	int a[5] = {5,4,3,2,1};
	
	MergeSort(a,0,4);
	for(i = 0;i < 5;++i)
		printf("%d%c",a[i],i == 4 ? '\n':',');
	return 0;
}
void MergeSort(int a[],int i,int j)
{

	if(i < j)
	{
		int k = (i+j)/2;
		MergeSort(a,i,k);
		MergeSort(a,k+1,j);
		Merge(a,i,k,j);
	}
}
void Merge(int a[],int p,int q,int n)
{
	int n1,n2;
	int *l,*r;
	int i,j,k;
	
	n1 = q - p +1;
	n2 = n - q;
	l = (int *)malloc(n1*sizeof(int));
	r = (int *)malloc(n2*sizeof(int));
	
	for(i = 0;i < n1;++i)
		l[i] = a[p + i];
	for(i = 0;i < n2;++i)
		r[i] = a[q + i + 1];
	for(i = 0,j = 0,k = p;i < n1 && j < n2;++k)
	{
		if(l[i] < r[j])
			a[k] = l[i++];
		else
			a[k] = r[j++];
	}
	while(i < n1)
		a[k++] = l[i++];
	while(j < n2)
		a[k++] = r[j++];
}
