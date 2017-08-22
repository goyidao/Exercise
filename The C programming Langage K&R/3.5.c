#include<stdio.h>
void shellsort(int v[],int n);
void shellsort1(int v[],int n);
main()
{
	int i;
	int v[7] = {6,5,4,3,2,1,0};
	shellsort1(v,7);
	for(i = 0;i < 7;++i)
		printf("%d\t",v[i]);
}
void shellsort(int v[],int n)
{
	int gap;
	int i,j;
	int temp;
	
	for(gap = n/2;gap > 0;gap /= 2)
	{
		for(i = gap;i < n;++i)
		{
			if(v[i] < v[i - gap])
			{
				temp = v[i];
				for(j = i - gap;j >= 0 && v[j] > temp;j -= gap)//这里使用腾空位 
					v[j + gap] = v[j];
				v[j + gap] = temp;
			}
		}
	}
}
void shellsort1(int v[],int n)
{
	int gap;
	int i,j;
	int temp;
	for(gap = n/2;gap > 0;gap /= 2)
		for(i = gap;i < n;++i)
			for(j = i - gap;j >= 0 && v[j] > v[j+gap];j -= gap)//这里使用交换 
			{
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}
/*这种没太大意义，希尔排序本来就是结合了直接插入排序
在待排序列基本有序时比较次数少的优点，通过按照一定增量
分组分别排序后达来到整个序列基本有序，下边这种不能减少
比较次数*/
//void shellsort(int v[],int n)
//{
//	int gap;
//	int i,j;
//	int temp;
//	gap = n / 2;
//	while(gap > 0)
//	{
//		for(i = 0;i < n;i += gap)
//		{
//			for(j = i + gap;j < n;j += gap)
//			{
//				if(v[i] > v[j])
//				{
//					temp = v[i];
//					v[i] = v[j];
//					v[j] = temp;
//				}
//			}
//		}
//		gap /= 2;
//	}
//}
