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
	int res = 0;//对称半径 
	int len = str.length();
	string s = "";
	int newlen = len*2+3;
	s.resize(newlen);
	s[0] = '$';
	s[1] = '#';
	s[newlen-1] = '@';
	for(int i = 0,j = 2;i < len;i++)//预处理，解决偶数问题，这样对回文子串长度直接就是res 
	{
		s[j++] = str[i];
		s[j++]= '#';
	}
	vector<int> r(newlen,0);
	/*已知i之前的r,现在求r[i]*/
	for(int i = 1,id = 0;i < newlen;i++)//id表示i之前回文子串延伸最远的中心位置 
	{
		if(r[id] + id >= i)//i处在r[id]表示的回文子串中
			r[i] = min(r[2*id-i],id+r[id]-i);//2*id-i表示i关于id的对称位置，能跳过一些计算 
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
