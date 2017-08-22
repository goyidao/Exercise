#include<stdio.h>
#include<limits.h>
#include<stdlib.h> 
#define MAXSIZE 100
#define INF INT_MAX
/*邻接矩阵*/
typedef struct MGraph{
	char vertexes[MAXSIZE];
	int edges[MAXSIZE][MAXSIZE];
	int vertexnum,edgenum;
} MGraph;
/*邻接表*/ 
typedef struct EdgeNode{
	int adjvex;
	struct EdgeNode *next;
	int w;
} EdgeNode;
typedef struct VertexNode{
	char data;
	struct EdgeNode *firstEdge; 
} VertexNode,VexList[MAXSIZE];
typedef struct AdjListGraph{
	VexList vexList;
	int vertexnum;
	int edgenum;
} AdjListGraph;
/*边集表示法*/
typedef struct{
	int vexbegin,vexend,w;
} EGNode,EdgeList[MAXSIZE];
typedef struct{
	char data;
}VList[MAXSIZE];
typedef struct{
	EdgeList edgelist;
	VList vexlist;
	int edgenum;
	int vertexnum;
} EdgeGraph;
/*队列*/
typedef struct SqQueue{
	int base[MAXSIZE];
	int front;
	int rear;
}SqQueue;
/*CSTree*/
typedef struct CSTNode{
	char data;
	struct CSTNode *firstchild,*nextsibling;
} CSTNode,*CSTree;
/*队列操作*/
void InitQueue(SqQueue *Q)
{
	Q->front = Q->rear = 0;
}
int QueueEmpty(SqQueue *Q)
{
	return Q->front == Q->rear ? 1 : 0;
}
void EnQueue(SqQueue *Q,int e)
{
	if((Q->rear + 1)%MAXSIZE == Q->front)
		printf("error:Queue full.\n");
	else
	{
		Q->base[Q->rear] = e;
		Q->rear = (Q->rear + 1)%MAXSIZE;
	}
}
void DeQueue(SqQueue *Q,int *e)
{
	if(QueueEmpty(Q))
		printf("error:Queue empty.\n");
	else
	{
		*e = Q->front;
		Q->front = (Q->front + 1)%MAXSIZE;
	}
}



/*图操作*/ 
void CreateGraph_L(AdjListGraph *G)
{
	int i,j,w,n;
	EdgeNode *p; 
	printf("输入顶点数和边数:\n");
	scanf("%d%d",&i,&j);
	getchar();
	G->vertexnum = i;
	G->edgenum = j;
	printf("vertexnum=%d,edgenum=%d\n",G->vertexnum,G->edgenum);
	printf("输入顶点信息:\n");
	for(i = 0;i < G->vertexnum;++i)
	{
		scanf("%c",&G->vexList[i].data);
		G->vexList[i].firstEdge = NULL;
	}
	printf("输入无向图中的边(vi,vj)坐标和权值，i,j,w:\n");
	for(n = 0;n < G->edgenum;++n)
	{
		EdgeNode *e1 = (EdgeNode *)malloc(sizeof(EdgeNode));
		EdgeNode *e2 = (EdgeNode *)malloc(sizeof(EdgeNode));
		
		e1->next = NULL;
		e2->next = NULL;
		
		scanf("%d,%d,%d",&i,&j,&w);
		e1->adjvex = j;
		e1->w = w;
		e1->next = G->vexList[i].firstEdge;
		G->vexList[i].firstEdge = e1;
		
		e2->adjvex = i;
		e2->w = w;
		e2->next = G->vexList[j].firstEdge;
		G->vexList[j].firstEdge = e2;
	}
	printf("\n");
	for(i = 0;i < G->vertexnum;++i)
	{
		printf("%c:",G->vexList[i].data);
		for(p = G->vexList[i].firstEdge;p != NULL;p = p->next)
			printf("%d ",p->adjvex);
		printf("\n");
	}
	
}
void CreateGraph_M(MGraph *G)
{
	int i,j,w,n;
	printf("输入顶点数和边数:\n");
	scanf("%d%d",&i,&j);
	getchar();
	G->vertexnum = i;
	G->edgenum = j;
	printf("vertexnum=%d,edgenum=%d\n",G->vertexnum,G->edgenum);
	printf("输入顶点信息:\n");
	for(i = 0;i < G->vertexnum;++i)
		scanf("%c",&G->vertexes[i]);
	for(i = 0;i < G->vertexnum;++i)//初始化邻接矩阵 
		for(j = 0;j < G->vertexnum;++j)
		{
			if(i != j)
				G->edges[i][j] = INF;
			else
				G->edges[i][j] = 0;
		}
	printf("输入无向图中的边(vi,vj)坐标和权值，i,j,w:\n");
	for(n = 0;n < G->edgenum;++n)
	{
		scanf("%d,%d,%d",&i,&j,&w);
		G->edges[i][j] = G->edges[j][i] = w;
	}
	printf("生成邻接矩阵:\n");
	printf("\t");
	for(i = 0;i < G->vertexnum;++i)
		printf("%c\t",G->vertexes[i]);
	printf("\n");
	for(i = 0;i < G->vertexnum;++i)
	{
		printf("%c\t",G->vertexes[i]);
		for(j = 0;j < G->vertexnum;++j)
		{
			if(G->edges[i][j] == INF)	
				printf("INF\t");
			else
				printf("%d\t",G->edges[i][j]);
		}
		printf("\n");
	}
}

int visited[MAXSIZE];
void DFS_M(MGraph *G,int i)
{
	int j;
	visited[i] = 1;
	printf("%c",G->vertexes[i]);
	for(j = 0;j < G->vertexnum;++j)
	{
		if(i != j && G->edges[i][j] != INF && !visited[j])
			DFS_M(G,j);
	}
}
void DFSTraverse_M(MGraph *G)
{
	int i;
	for(i = 0;i < G->vertexnum;++i)
		visited[i] = 0;
	for(i = 0;i < G->vertexnum;++i)
	{
		if(!visited[i])
			DFS_M(G,i);
	}
}

void DFS_L(AdjListGraph *G,int i)
{
	int j;
	EdgeNode *p;
	visited[i] = 1;
	printf("%c",G->vexList[i].data);
	for(p = G->vexList[i].firstEdge;p != NULL;p = p->next)
	{
		if(!visited[p->adjvex])
			DFS_L(G,p->adjvex);
	}
}
void DFSTraverse_L(AdjListGraph *G)
{
	int i;
	for(i = 0;i < G->vertexnum;++i)
		visited[i] = 0;
	for(i = 0;i < G->vertexnum;++i)
	{
		if(!visited[i])
			DFS_L(G,i);
	}
}
void BFSTraverse_M(MGraph *G)
{
	int i,j,e;
	SqQueue Q;
	InitQueue(&Q);
	for(i = 0;i < G->vertexnum;++i)
		visited[i] = 0;
	for(i = 0;i < G->vertexnum;++i)
	{
		if(!visited[i])
		{
			printf("%c",G->vertexes[i]);
			EnQueue(&Q,i);
			visited[i] = 1;
			while(!QueueEmpty(&Q))
			{
				DeQueue(&Q,&e);
				for(j = 0;j < G->vertexnum;++j)
				{
					if(e != j && G->edges[e][j] != INF && !visited[j])
					{
						printf("%c",G->vertexes[j]);
						visited[j] = 1;
						EnQueue(&Q,j);
					}
				}
			}
		}
	}
}
void BFSTraverse_L(AdjListGraph *G)
{
	int i,index;
	EdgeNode *p;
	SqQueue Q;
	InitQueue(&Q);
	for(i = 0;i < G->vertexnum;++i)
		visited[i] = 0;
	for(i = 0;i < G->vertexnum;++i)
	{
		if(!visited[i])
		{
			printf("%c",G->vexList[i].data);
			visited[i] = 1;
			EnQueue(&Q,i);
			while(!QueueEmpty(&Q))
			{
				DeQueue(&Q,&index);
				for(p = G->vexList[index].firstEdge;p != NULL;p = p->next)
				{
					if(!visited[p->adjvex])
					{
						printf("%c",G->vexList[p->adjvex].data);
						visited[p->adjvex] = 1;
						EnQueue(&Q,p->adjvex);
					}
				}
			}
		}	
	}
}
void DFSTree_M(MGraph *G,CSTree T,int v)//从节点v开始创建无向图连通图G的深度优先生成树T,v点已经存进T中 
{
	int i,j,first;
	CSTree p,q;
	
	q = T;
	visited[v] = 1;
	first = 1;
	for(j = 0;j < G->vertexnum;++j)
	{
		if(v != j && G->edges[v][j] != INF && !visited[j])
		{
			p = (CSTree)malloc(sizeof(CSTNode));
			p->data = G->vertexes[j];
			p->firstchild = p->nextsibling = NULL;
			if(first)
			{
				q->firstchild = p;
				first = 0;
			}
			else
				q->nextsibling = p;
			q = p;
			DFSTree_M(G,q,j);
		}
	}
}
void DFSForest_M(MGraph *G,CSTree *T)
{
	int i;
	CSTree p,q;
	for(i = 0;i < G->vertexnum;++i)
		visited[i] = 0;
	for(i = 0;i < G->vertexnum;++i)
	{
		if(!visited[i])
		{
			p = (CSTree)malloc(sizeof(CSTNode));
			p->data = G->vertexes[i];
			p->firstchild = p->nextsibling = NULL;
			if(*T != NULL)//不是第一次 
			{
				q->nextsibling = p;
			}
			else//是第一次 
			{
				*T = p;
			}
			q = p;
			DFSTree_M(G,q,i);
		}
	}
}
void PreOrderTrav(CSTree T)
{
	if(T)
	{
		printf("%c",T->data);
		PreOrderTrav(T->firstchild);
		PreOrderTrav(T->nextsibling);
	}
}

/*MiniSpanTree_PRIM*/
void MiniSpanTree_PRIM(MGraph *G,int u)//从u开始生成G的最小代价生成树
{
	int adjvex[MAXSIZE];
	int lowcost[MAXSIZE];
	int i,j,minindex,mincost;
	
	lowcost[u] = 0;
	for(i = 0;i < G->vertexnum;++i)//初始化 
	{
		if(i != u)
		{
			lowcost[i] = G->edges[u][i];
			adjvex[i] = u;
		}
	}
	for(i = 0;i < G->vertexnum-1;++i)//找剩余的N-1个vex 
	{
		mincost = INT_MAX;
		for(j = 0;j < G->vertexnum;++j)//找最小代价边 
		{
			if(lowcost[j] != 0 && lowcost[j] < mincost)
			{
				minindex = j;
				mincost = lowcost[j];
			}
		}
		printf("%d---%d:%d\n",adjvex[minindex],minindex,mincost);
		lowcost[minindex] = 0;//加入生成树并在原集中去除 
		for(j = 0;j < G->vertexnum;++j)//调整剩余vex到生成树中vex的最小代价信息 
		{
			if(lowcost[j] != 0 && G->edges[minindex][j] < lowcost[j] && minindex != j)
			{
				lowcost[j] = G->edges[minindex][j];
				adjvex[j] = minindex;
			}
		}
	}
}
void swap(EGNode elist[],int i,int j)
{
	EGNode node;
	node = elist[i];
	elist[i] = elist[j];
	elist[j] = node;
}
void mqsort(EGNode elist[],int left,int right)
{
	if(left < right)
	{
		int i;
		int last = left;
		for(i = left+1;i <= right;++i)
			if(elist[i].w < elist[left].w)
				swap(elist,i,++last);
		swap(elist,left,last);
		mqsort(elist,left,last-1);
		mqsort(elist,last+1,right);
	}
}
int find(int parent[],int i)
{
	while(parent[i] != -1)
		i = parent[i];
	return i;
}
void MiniSpanTree_kruskal(MGraph *G)
{
	EdgeGraph eg;
	int i,j,k;
	int parent[MAXSIZE];
	
	k = 0;
	eg.edgenum = 0;
	eg.vertexnum = 0;
	
	for(i = 0;i < G->vertexnum;++i)//转换为边集表示法 
		for(j = 0;j < i;++j)
		{
			if(G->edges[i][j] != INF)
			{
				eg.edgelist[k].w = G->edges[i][j];
				eg.edgelist[k].vexbegin = i;
				eg.edgelist[k].vexend = j;
				eg.vexlist[2*k].data=G->vertexes[i];
				eg.vexlist[2*k + 1].data=G->vertexes[j];
				eg.edgenum++;
				eg.vertexnum += 2;
				++k;
			}
		}
	mqsort(eg.edgelist,0,eg.edgenum-1);//安边的权重升序排序
	for(i = 0;i < eg.vertexnum;++i)//初始化双亲表示法表示的n个节点 
		parent[i] = -1;
	for(i = 0;i < eg.edgenum;++i)
	{
		int n = find(parent,eg.edgelist[i].vexbegin);
		int m = find(parent,eg.edgelist[i].vexend);
		if(n != m)
		{
			parent[m] = n;
			printf("%d---%d:%d\n",eg.edgelist[i].vexbegin,eg.edgelist[i].vexend,eg.edgelist[i].w);
		}
	}
}

int main()
{
	MGraph G;
	AdjListGraph G1;
	CSTree T = NULL;
	
	CreateGraph_M(&G);
	printf("\nDFS_M:\n");
	DFSTraverse_M(&G);
	printf("\nBFS_M:\n");
	BFSTraverse_M(&G);
	
	CreateGraph_L(&G1);
	printf("\nDFS_L:\n");
	DFSTraverse_L(&G1);
	
	printf("\nBFS_L:\n");
	BFSTraverse_L(&G1);
	
	DFSForest_M(&G,&T);
	printf("\nDFSTree_M:\n");
	PreOrderTrav(T);
	
	printf("\n普利姆算法，最小生成树：\n");
	MiniSpanTree_PRIM(&G,0);
	printf("\nkruskal算法，最小生成树：\n");
	MiniSpanTree_kruskal(&G);
	return 0;
}
