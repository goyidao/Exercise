#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int maxi;
	int maxj;
	int max;
} Info;

Info FindMaximumSubarray(int a[],int low,int high);
Info FindMaxCrossingSubarray(int a[],int low,int mid,int high);
Info violent(int a[],int len);
int main()
{
		int a[4] = {-3,-2,-3,-4};
		Info info1;

		info1 = FindMaximumSubarray(a,0,3);
		printf("max-letf:%d\nmax-right:%d\nmax:%d\n",info1.maxi,info1.maxj,info1.max);
		return 0;
}
Info FindMaxCrossingSubarray(int a[],int low,int mid,int high)
{
	Info info;
	int i,j;
	int sum = 0;
	int sum_left = a[mid];
	int sum_right = a[mid+1];
	int max_left = mid;
	int max_right = mid+1;
	
	for(i = mid;i >= 0;--i)
	{
		sum += a[i];
		if(sum > sum_left)
		{
			sum_left = sum;
			max_left = i;
		}
	}
	sum = 0;
	for(j = mid+1;j <= high;++j)
	{
		sum += a[j];
		if(sum > sum_right)
		{
			sum_right = sum;
			max_right = j;
		}
	}
	info.maxi = max_left;
	info.maxj = max_right;
	info.max = sum_left+sum_right;
	return info;
}
Info FindMaximumSubarray(int a[],int low,int high)
{
	if(low >= high)
	{
		Info info;
		info.max = a[low];
		info.maxi = info.maxj = low;
		return info;
	}
	else
	{
		int mid = (high + low)/2;
		Info info_left,info_right,info_cross;
		info_left = FindMaximumSubarray(a,low,mid);
		info_right = FindMaximumSubarray(a,mid+1,high);
		info_cross = FindMaxCrossingSubarray(a,low,mid,high);
		if(info_left.max >= info_right.max && info_left.max >= info_cross.max)
			return info_left;
		else if(info_right.max >= info_left.max && info_right.max >= info_cross.max)
			return info_right;
		else if(info_cross.max >= info_left.max && info_cross.max >= info_right.max)
			return info_cross;
	}
}
Info violent(int a[],int len)
{
	int i,j;
	int sum = 0;
	Info info;
	
	info.maxi = info.maxj = info.max = 0;
	
	for(i = 0;i < len;++i)
	{
		for(j = i;j < len;++j)
		{
			sum += a[j];
			if(sum > info.max)
			{
				info.max = sum;
				info.maxi = i;
				info.maxj = j;
			}
		}
		sum = 0;
	}
	return info;
}
