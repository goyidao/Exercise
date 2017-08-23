#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int Maxsize = 100;
int p[Maxsize][Maxsize];
int dp(string str);
int main()//��ʱ 
{
	int n;
	string line;
	cin>>n;
	while(n)
	{
		cin>>line;
		int res = dp(line);
		cout<<res<<endl;
		n--;
	}
	return 0;
}
/*��̬�滮:p[i][j]=1��0����ʾstr[i]��str[j]�ǻ��ǻ��� */
int dp(string str)
{
	int res = 0;
	int len = str.length();
	memset(p,0,sizeof(p));
	for(int i = 0;i < len;i++)
	{
		p[i][i] = 1;
		if(i+1 <= len && str[i] == str[i+1])
		{
			p[i][i+1] = 1;
			res = 2;
		}
	}
	int k;
	for(k = 3;k <=len;k++)//k�ǻ����Ӵ��ĳ��� 
	{
		for(int i = 0,j = i+k-1;j < len;i+=1,j=i+k-1)
		{
			if(str[i] == str[j] && p[i+1][j-1] == 1)
			{ 
				p[i][j] = 1;
				res = k;
			} 
		}
	}
	return res;
}
