#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int cal(string str);
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		int res = cal(str);
		cout<<res<<endl;
	}
	return 0;
}
int cal(string str)
{
	int res = 0;//�Գư뾶 
	int len = str.length();
	string s = "";
	int newlen = len*2+3;
	s.resize(newlen);
	s[0] = '$';
	s[1] = '#';
	s[newlen-1] = '@';
	for(int i = 0,j = 2;i < len;i++)//Ԥ�������ż�����⣬�����Ի����Ӵ�����ֱ�Ӿ���res 
	{
		s[j++] = str[i];
		s[j++]= '#';
	}
	vector<int> r(newlen,0);
	/*��֪i֮ǰ��r,������r[i]*/
	for(int i = 1,id = 0;i < newlen;i++)//id��ʾi֮ǰ�����Ӵ�������Զ������λ�� 
	{
		if(r[id] + id >= i)//i����r[id]��ʾ�Ļ����Ӵ���
			r[i] = min(r[2*id-i],id+r[id]-i);//2*id-i��ʾi����id�ĶԳ�λ�ã�������һЩ���� 
		int j = r[i];
		while(s[i-j-1] == s[i+j+1])
			j++;
		r[i] = j;
		res = max(res,r[i]);
		if(i+r[i] > id+r[id])
			id = i;
	}
	return res;
}
