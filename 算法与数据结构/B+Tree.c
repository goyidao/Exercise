#include<stdio.h>
#include<stdlib.h>
#define t 2//度 
typedef int KeyType;
typedef struct BPTNode{
	int keynum;//节点关键字数 
	int leaf;//叶子结点标志 
	KeyType k[2*t+1];//数组下表都从1开始，关键字数组 
	union{
		struct BPTNode *c[2*t+1];//内部结点：孩子数组 
		struct{
			int a[2*t+1];//叶子结点：地址数组 
			struct BPTNode *next;//叶子结点：下一个叶子结点 
		} leafElem;
	}CA;
} BPTNode;
typedef struct BPTree{
	BPTNode *root,*sqt;
}BPTree;


/*队列*/
typedef BPTNode* Elemtype;
typedef struct QNode{
	Elemtype T;
	struct QNode *next;
}QNode,*Qptr;
typedef struct Queue{
	Qptr front,rear;
}Queue;

void InitQueue(Queue *Q);
void EnQueue(Queue *Q,BPTNode *T);
void DeQueue(Queue *Q,BPTNode **T);
int isEmpty(Queue *Q);


void CreateEmptyBPTree(BPTree *T);
void BPTreeSplit(BPTNode *T,int i);
void BPTreeInsertNotFull(BPTNode *T,int key,int address);
void BPTreeInsert(BPTree *T,int key,int address);
void BTreeTraverse(BPTree BPT);


void InitQueue(Queue *Q)
{
	Q->front = Q->rear = (Qptr)malloc(sizeof(QNode));
	Q->front->next = Q->rear->next = NULL;
}
void EnQueue(Queue *Q,BPTNode *T)
{
	QNode *p = (QNode *)malloc(sizeof(QNode));
	p->T = T;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}
void DeQueue(Queue *Q,BPTNode **T)
{
	QNode *p;
	if(Q->front == Q->rear)
		printf("queue empty.\n");
	else
	{
		p = Q->front->next;
		*T = p->T;
		Q->front->next = p->next;
		if(p == Q->rear)
			Q->rear = Q->front;
		free(p);
	}
}
int isEmpty(Queue *Q)
{
	return Q->front == Q->rear;
}




void CreateEmptyBPTree(BPTree *T)
{
	T->sqt = T->root = (BPTNode *)malloc(sizeof(BPTNode));
	T->root->keynum = 0;
	T->root->leaf = 1;
	T->root->CA.leafElem.next = NULL;
}

void BPTreeSplit(BPTNode *T,int i)//T此时不满，并且T的第i个孩子满了，所以要分裂那个孩子 
{
	int j;
	BPTNode *y = T->CA.c[i];
	BPTNode *z = (BPTNode *)malloc(sizeof(BPTNode));
	z->leaf = y->leaf;
	z->keynum = t;
	for(j = 1;j <= t;++j)
		z->k[j] = y->k[j+t];
	if(!y->leaf)//内部结点需要复制其孩子 
	{
		for(j = 1;j <= t;++j)
			z->CA.c[j] = y->CA.c[j+t];
	}
	else//叶子结点需复制其地址数组,并生成指向下一个叶子结点的指针 
	{
		for(j = 1;j <= t;++j)
			z->CA.leafElem.a[j] = y->CA.leafElem.a[j+t];
		y->CA.leafElem.next = z;
		z->CA.leafElem.next = NULL;
	}
	y->keynum = t;
	T->CA.c[i] = z;
	for(j = T->keynum;j >= i;--j)
	{
		T->k[j+1] = T->k[j];
		T->CA.c[j+1] = T->CA.c[j];
	}
	T->k[i] = y->k[t];
	T->CA.c[i] = y;
	T->keynum++;
	printf("WRITE..\n");
	printf("WRITE..\n");
	printf("WRITE..\n");
}

void BPTreeInsertNotFull(BPTNode *T,int key,int address)
{
	int i,j;
	for(i = T->keynum;i > 0 && key < T->k[i];--i);//应该插入到x.ci+1如果有的话 (此处倒着来)
	if(T->leaf)//是叶子节点 
	{
		for(j = T->keynum;j >= i+1;--j)
		{
			T->k[j+1] = T->k[j];
			T->CA.leafElem.a[j+1] = T->CA.leafElem.a[j];
		} 
		T->k[i+1] = key;
		T->CA.leafElem.a[i+1] = address;
		T->keynum++;
	}
	else//不是叶节点往下插入 
	{
		if(i == T->keynum)//待插入的比当前节点最大的还大，更新当前最大值
		{
			T->k[T->keynum] = key;
			if(T->CA.c[T->keynum]->keynum == 2*t)
			{
				BPTreeSplit(T,T->keynum);
				BPTreeInsertNotFull(T->CA.c[T->keynum],key,address);
			}
			else
				BPTreeInsertNotFull(T->CA.c[T->keynum],key,address);
		}
		else
		{
			if(T->CA.c[i+1]->keynum == 2*t)
			{
				BPTreeSplit(T,i+1);
				BPTreeInsertNotFull(T,key,address);
			} 
			BPTreeInsertNotFull(T->CA.c[i+1],key,address);
		}
	}
}

void BPTreeInsert(BPTree *T,int key,int address)
{
	BPTNode *r = T->root;//不能通过r修改root指向的地址 
	BPTNode *s,*p;
	if(r->keynum == 2*t)
	{
		s = (BPTNode *)malloc(sizeof(BPTNode));
		s->leaf = 0;
		s->keynum = 1;
		T->root = s;
		s->CA.c[1] = r;
		s->k[1] = r->k[2*t];
		//printf("before...BPTreeSplit(s,1);\n");
		BPTreeSplit(s,1);
		//printf("after...BPTreeSplit(s,1);\n");
		BPTreeInsertNotFull(s,key,address);
	}
	else
		BPTreeInsertNotFull(r,key,address);
	p = T->root;
	while(!p->leaf)
		p = p->CA.c[1];
	T->sqt = p;
}


void BTreeTraverse(BPTree BPT)
{
	BPTNode *T = BPT.root;
	int i,j;
	BPTNode *parent,*flag;
	Queue Q;
	InitQueue(&Q);
	flag = NULL;
	if(!T)
		printf("empty btree\n");
	else
	{
		for(i = 1;i <= T->keynum;++i)
			printf("%d ",T->k[i]);
		printf("|");
		printf("\n");
		EnQueue(&Q,T);
		EnQueue(&Q,flag);
		while(!isEmpty(&Q))
		{
			DeQueue(&Q,&parent);
			if(parent == NULL)
			{
				printf("\n");
				if(!isEmpty(&Q))
				{
					DeQueue(&Q,&parent);
					EnQueue(&Q,flag);
				}
				else
					break;
			}
			if(!parent->leaf)
			{
				for(i = 1;i <= parent->keynum;++i)
				{
					for(j = 1;j <= parent->CA.c[i]->keynum;++j)
						printf("%d ",parent->CA.c[i]->k[j]);
					printf("|");
					EnQueue(&Q,parent->CA.c[i]);
				}
				//EnQueue(&Q,flag);
			}
		}
	}
}

int main()
{
	int i;
	int k[] = {1,2,3,4,5,6,7,8,9};
	int a[] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0xA9};
	BPTree T;
	BPTNode *p;
	CreateEmptyBPTree(&T);
	for(i = 0;i < 9;++i)
	{
		BPTreeInsert(&T,k[i],a[i]);
		printf("..insert:%d\n",a[i]);
	}
	BTreeTraverse(T);
	for(p = T.sqt;p;p=p->CA.leafElem.next)
	{
		for(i = 1;i <= p->keynum;++i)
			printf("key=%d address=0x%x\n",p->k[i],p->CA.leafElem.a[i]);
	}
}
