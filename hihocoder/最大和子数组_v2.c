#include<stdio.h>
int maxsub_ultimate(int a[],int len,int *start,int *end);
int main()
{
	int arr[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int start,end;
	int maxsum = maxsub_ultimate(arr,16,&start,&end);
	printf("maxsum=%d\n",maxsum);
	for(;start <= end;++start)
		printf("%d\t",arr[start]);
	return 0;
}
int maxsub_ultimate(int arr[],int len,int *s,int *e)
{
	int i;
	int end,all;
	int curstart;
	end = all = arr[0];
	curstart = *s = *e = 0;
	for(i = 1;i < len;++i)
	{
		if(end < 0)
		{
			end = arr[i];
			curstart = i;
		}
		else
			end += arr[i];
		if(end > all)
		{
			all = end;
			*s = curstart;
			*e = i;
		}
	}
	return all;
}
