#include<stdio.h>
void QuickSort(int a[],int len);
void QSort(int a[],int low,int high);
int Partition(int a[],int low,int high);
void swap(int a[],int i,int j);
int main()
{
	int a[] = {5,4,3,2,1};
	int i;
	QuickSort(a,5);
	for(i = 0;i < 5;++i)
		printf("%d%c",a[i],i == 4 ? ' ':',');
	return 0;
}
void QuickSort(int a[],int len)
{
	QSort(a,0,len - 1);
}
void QSort(int a[],int low,int high)
{
	int pivot; 
	while(low < high)//尾递归 
	{
		pivot = Partition(a,low,high);
		QSort(a,low,pivot-1);
		low = pivot + 1;
	}
}
int Partition(int a[],int low,int high)
{
	int pivotkey;
	
	int m = (low + high)/2;//三点取中法 
	if(a[low] > a[high])
		swap(a,low,high);
	if(a[m] > a[high])
		swap(a,m,high);
	if(a[low] < a[m])
		swap(a,low,m);
	pivotkey = a[low];
		
	while(low <high)
	{
		while(low < high && a[high] >= pivotkey)
			--high;
		a[low] = a[high];
		while(low < high && a[low] <= pivotkey)
			++low;
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
