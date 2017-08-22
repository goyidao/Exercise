#include<stdio.h>
void QuickSort_v1(int a[],int low,int high);
int Partation_v1(int a[],int low,int high);
int Partation_v2(int a[],int low,int high);
void swap(int a[],int i,int j);
void printarr(int a[],int len);
int main()
{
	int a[4] = {4,3,2,1};
	QuickSort_v1(a,0,3);
	printarr(a,4);
	return 0;
}
void QuickSort_v1(int a[],int low,int high)
{
	if(low < high)
	{
		int pivot = Partation_v2(a,low,high);
		QuickSort_v1(a,low,pivot-1);
		QuickSort_v1(a,pivot+1,high); 
	}
}
int Partation_v2(int a[],int low,int high)
{
	int last;
	int i;
	
	swap(a,low,(high + low)/2);
	last = low;
	for(i = low + 1;i <= high;++i)
		if(a[i] < a[low])
			swap(a,++last,i);
	swap(a,last,low);
	return last; 
}
int Partation_v1(int a[],int low,int high)
{
	int mid = (low + high)/2;
	int pivotkey;
	swap(a,mid,low);
	pivotkey = a[low];
	while(low < high)
	{
		while(low < high && a[high] >= pivotkey) --high;
		a[low] = a[high];
		while(low < high && a[low] <= pivotkey) ++low;
		a[high] = a[low];
	}
	a[low] = pivotkey;
	return low;
}
void swap(int a[],int i,int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void printarr(int a[],int len)
{
	int i;
	for(i = 0;i < len;++i)
		printf("%d%c",a[i],i == len-1 ? '\n':',');
}
