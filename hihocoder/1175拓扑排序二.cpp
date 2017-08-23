#include<cstdio>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;
const int MOD = 142857;
vector<int> alist[100001];
int main()
{
	int n,m,k;
	int virus[100001];
	int in[100001];
	while(scanf("%d%d%d",&n,&m,&k) != EOF)
	{
		int count = 0;
		memset(virus,0,sizeof(virus));
		memset(in,0,sizeof(in));
		for(int i = 1;i <= 100000;++i)
			alist[i].clear();
		for(int i=1;i <= k;++i)
		{
			int index;
			scanf("%d",&index);
			virus[index]++;
		}
		for(int i=1;i <= m;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			in[v]++;
			alist[u].push_back(v);
		}
		stack<int> st;
		for(int i=1;i <= n;++i)
		{
			if(in[i] == 0)
				st.push(i);
		}
		while(!st.empty())
		{
			int e = st.top();
			st.pop();
			count = (count + virus[e]) % MOD;
			for(int i=0;i < alist[e].size();++i)
			{
				int v = alist[e][i];
				virus[v] = (virus[v] + virus[e]) % MOD;
				in[v]--;
				if(in[v] == 0)
					st.push(v);
			}
		}
		printf("%d\n",count % MOD);
	}
	return 0;
}
