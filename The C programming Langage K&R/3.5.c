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
				for(j = i - gap;j >= 0 && v[j] > temp;j -= gap)//����ʹ���ڿ�λ 
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
			for(j = i - gap;j >= 0 && v[j] > v[j+gap];j -= gap)//����ʹ�ý��� 
			{
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}
/*����û̫�����壬ϣ�����������ǽ����ֱ�Ӳ�������
�ڴ������л�������ʱ�Ƚϴ����ٵ��ŵ㣬ͨ������һ������
����ֱ������������������л��������±����ֲ��ܼ���
�Ƚϴ���*/
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
