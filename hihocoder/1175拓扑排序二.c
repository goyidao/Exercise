#include<stdio.h>
#include<string.h>
#define MOD 142857
typedef struct VetxNode{
    int vri;
    int in;
}VetxNode;
typedef struct EdgeNode{
    int s;
    int e;
}EdgeNode;
typedef struct Graph{
    VetxNode vetxs[100001];
    EdgeNode edges[100001];
    int vetxnum;
    int edgenum;
}Graph;
int stack[100003];
int top;
int main(){
	
    /*创建边集数组,并初始化*/
    int n,m,k;
    int i,index;
    int e;
    int count;
    Graph G;
    while(scanf("%d%d%d",&n,&m,&k) != EOF)
    {
        G.vetxnum = n;
        G.edgenum = m;
        count = 0;
        top = -1;
        memset(G.vetxs,0,sizeof(G.vetxs));
        
        for(i = 1;i <= k;++i)
        {
            scanf("%d",&index);
            G.vetxs[index].vri = (G.vetxs[index].vri + 1) % MOD;
        }
        for(i = 1;i <= m;++i)
        {
            scanf("%d%d",&G.edges[i].s,&G.edges[i].e);
            G.vetxs[G.edges[i].e].in++;
        }
        for(i = 1;i <= n;++i)//开始按照顶点找入度为0的入栈
        {
            if(G.vetxs[i].in == 0)
            {
                stack[++top] = i;
            }
        }
        while(top >= 0)//开始拓扑排序
        {
            e = stack[top--];
            count =(count + G.vetxs[e].vri) % MOD;
            for(i = 1;i <= m;++i)
            {
                if(G.edges[i].s == e)
                {
                    G.vetxs[G.edges[i].e].vri =(G.vetxs[e].vri + G.vetxs[G.edges[i].e].vri) % MOD;
                    if(--G.vetxs[G.edges[i].e].in == 0)
                    {
                        stack[++top] = G.edges[i].e;
                    }
                }
            }
        }
        printf("%d\n",count % MOD);
    }
    return 0;
}
