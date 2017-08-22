#include<stdio.h>
#include<stdlib.h>
#define t 2
typedef struct BTNode{
	int keynum;
	int k[2*t];//k1.2.3 
	struct BTNode *c[2*t];//c0.1.2
	int leaf;
}BTNode,*BTree;
typedef struct Result{
	BTNode *pt;
	int i;
	int tag;
} Result;
/*队列，层序遍历时使用*/
typedef BTree Elemtype;
typedef struct QNode{
	Elemtype T;
	struct QNode *next;
}QNode,*Qptr;
typedef struct Queue{
	Qptr front,rear;
}Queue;

void InitQueue(Queue *Q);
void EnQueue(Queue *Q,BTree T);
void DeQueue(Queue *Q,BTree *T);
int isEmpty(Queue *Q);

void BTreeSplit(BTree *parent,int i);
void BTreeNotNullInsert(BTree *x,int key);
void BTreeInsert(BTree *T,int key);
Result BTreeSearch(BTree *T,int key);

void adjust2a(BTree *T,int i);
void adjust2b(BTree *T,int i);
void adjust2c(BTree *T,int i);
void adjust3aFront(BTree *T,int i);
void adjust3aRear(BTree *T,int i);
void adjust3bFront(BTree *T,int i);
void adjust3bRear(BTree *T,int i);
void BTreeDeleteMoreThanT_1(BTree *T,int key);

void InitQueue(Queue *Q)
{
	Q->front = Q->rear = (Qptr)malloc(sizeof(QNode));
	Q->front->next = Q->rear->next = NULL;
}
void EnQueue(Queue *Q,BTree T)
{
	QNode *p = (QNode *)malloc(sizeof(QNode));
	p->T = T;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}
void DeQueue(Queue *Q,BTree *T)
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



/*BTree基本操作*/ 
void BTreeSplit(BTree *parent,int i)//*parent结点的ci指向的结点满了（keynum = 2*t-1)，所以将其分裂 
{
	int j;
	BTNode *z = (BTNode *)malloc(sizeof(BTNode));
	z->keynum = t-1;
	z->leaf = (*parent)->c[i]->leaf;
	for(j = t+1;j <= 2*t-1;++j)
		z->k[j-t] = (*parent)->c[i]->k[j];
	//printf("BTreeSplit..%d..\n",z->k[1]);
	if(!z->leaf)
		for(j = t;j < 2*t;++j)
			z->c[j-t] = (*parent)->c[i]->c[j];
	for(j = (*parent)->keynum;j>=i+1;--j)
		(*parent)->k[j+1] = (*parent)->k[j];
	(*parent)->k[j+1] = (*parent)->c[i]->k[t];
	for(j = (*parent)->keynum;j>=i+1;--j)
		(*parent)->c[j+1] = (*parent)->c[j];
	(*parent)->c[j+1] = z;
	(*parent)->c[i]->keynum = t-1;
	(*parent)->keynum +=1;
	printf("WRITE..\n");
	printf("WRITE..\n");
	printf("WRITE..\n");
}
void BTreeNotNullInsert(BTree *x,int key)//*x不是满的，则在其中插入key 
{
	int i;
	if((*x)->leaf)//是叶子结点直接插入到其中
	{
		for(i = (*x)->keynum;i > 0 && key < (*x)->k[i];--i)
			(*x)->k[i+1] = (*x)->k[i];
		(*x)->k[i+1] = key;
		(*x)->keynum +=1;
	}
	else
	{
		for(i = (*x)->keynum;i > 0 && key < (*x)->k[i];--i);
		if((*x)->c[i]->keynum == 2*t-1)
		{
			BTreeSplit(x,i);
			if(key > (*x)->k[i+1])
				++i;
		}
		BTreeNotNullInsert(&(*x)->c[i],key);
	}
}
void BTreeInsert(BTree *T,int key)
{
	if((*T)->keynum == 2*t-1)//是否是满结点 
	{
		BTNode *p = (BTNode *)malloc(sizeof(BTNode));
		p->keynum = 0;
		p->leaf = 0;
		p->c[0] = *T;
		*T = p;
		BTreeSplit(T,0);
		//printf("BTreeInsert..%d..",(*T)->c[1]->k[1]);
		BTreeNotNullInsert(T,key);
	}
	else
		BTreeNotNullInsert(T,key);
}

Result BTreeSearch(BTree *T,int key)
{
	int i;
	Result res;
	if(!(*T))
	{
		res.tag = res.i = 0;
		res.pt = NULL;
		return res;
	}
	else
	{
		printf("READ..\n");
		for(i = 1;i <= (*T)->keynum && (*T)->k[i] < key;++i);//到ci-1孩子中找 
		if((*T)->k[i] == key)
		{
			res.i = i;
			res.tag = 1;
			res.pt = *T;
			return res;
		}
		else
		{
			if((*T)->leaf)//是叶子节点查找失败 
			{
				res.i = 0;
				res.tag = 0;
				res.pt = NULL;
				return res;
			}
			else
			{
				BTreeSearch(&(*T)->c[i-1],key);
			}
		}
	}
}

void adjust2a(BTree *T,int i)
{
	BTree x = (*T)->c[i-1];
	int front;
	printf("2a..\n");
	while(!x->leaf)
	{
		x = x->c[x->keynum];
		printf("READ..\n");
	}
	front = x->k[x->keynum];
	BTreeDeleteMoreThanT_1(&(*T)->c[i-1],front);
	(*T)->k[i] = front;
	printf("WRITE..\n");
}
void adjust2b(BTree *T,int i)
{
	BTree x = (*T)->c[i];
	int rear;
	printf("2b..\n");
	while(!x->leaf)
	{
		x = x->c[0];
		printf("READ..\n");
	}
	rear = x->k[1];
	BTreeDeleteMoreThanT_1(&(*T)->c[i],rear);
	(*T)->k[i] = rear;
	printf("WRITE..\n");
}

void adjust2c(BTree *T,int i)
{
	int j;
	printf("2c..\n");
	(*T)->c[i-1]->k[t] = (*T)->k[i];
	for(j = t+1;j <= 2*t-1;++j)
		(*T)->c[i-1]->k[j] = (*T)->c[i]->k[j-t];
	for(j = t;j <=2*t-1;++j)
		(*T)->c[i-1]->c[j] = (*T)->c[i]->c[j-t];
	(*T)->c[i-1]->keynum = 2*t-1;
	free((*T)->c[i]);
	for(j = i+1;j <= (*T)->keynum;++j)
	{
		(*T)->k[j-1] = (*T)->k[j];
		(*T)->c[j-1] = (*T)->c[j];
	}
	(*T)->keynum--;
	printf("WRITE..\n");
	printf("WRITE..\n");
	printf("WRITE..\n");
}
void adjust3aFront(BTree *T,int i)
{
	int j;
	printf("3aFront..\n");
	for(j = t-1;j >= 1;--j)
		(*T)->c[i-1]->k[j+1] = (*T)->c[i-1]->k[j];
	for(j = t-1;j >= 0;--j)
		(*T)->c[i-1]->c[j+1] = (*T)->c[i-1]->c[j];
	(*T)->c[i-1]->k[1] = (*T)->k[i-1];
	(*T)->c[i-1]->c[0] = (*T)->c[i-2]->c[(*T)->c[i-2]->keynum];
	(*T)->c[i-1]->keynum++;
	(*T)->k[i-1] = (*T)->c[i-2]->k[(*T)->c[i-2]->keynum];
	(*T)->c[i-2]->keynum--;
	printf("WRITE..\n");
	printf("WRITE..\n");
	printf("WRITE..\n");
}
void adjust3aRear(BTree *T,int i)
{
	int j;
	printf("3aRear..\n");
	(*T)->c[i-1]->k[t] = (*T)->k[i];
	(*T)->c[i-1]->c[t] = (*T)->c[i]->c[0];
	(*T)->c[i-1]->keynum++;
	(*T)->k[i] = (*T)->c[i]->k[1];
	for(j = 2;j <= (*T)->c[i]->keynum;++j)
		(*T)->c[i]->k[j-1] = (*T)->c[i]->k[j];
	for(j = 1;j <= (*T)->c[i]->keynum;++j)
		(*T)->c[i]->c[j-1] = (*T)->c[i]->c[j];
	(*T)->c[i]->keynum--;
	printf("WRITE..\n");
	printf("WRITE..\n");
	printf("WRITE..\n");
}
void adjust3bFront(BTree *T,int i)
{
	int j;
	printf("3bFront..\n");
	for(j = t-1;j >= 1;--j)
		(*T)->c[i-1]->k[j+t] = (*T)->c[i-1]->k[j];
	for(j = t-1;j >= 0;--j)
		(*T)->c[i-1]->c[j+t] = (*T)->c[i-1]->c[j];
	(*T)->c[i-1]->k[t] = (*T)->k[i-1];
	for(j = 1;j <= t-1;++j)
		(*T)->c[i-1]->k[j]=(*T)->c[i-2]->k[j];
	for(j = 0;j <= t-1;++j)
		(*T)->c[i-1]->c[j]=(*T)->c[i-2]->c[j];
	(*T)->c[i-1]->keynum = 2*t-1;
	free((*T)->c[i-2]);
	for(j = i;j <= (*T)->keynum;++j)
		(*T)->k[j-1] = (*T)->k[j];
	for(j = i-1;j <= (*T)->keynum;++j)
		(*T)->c[j-1] = (*T)->c[j];
	(*T)->keynum--;
	printf("WRITE..\n");
	printf("WRITE..\n");
	printf("WRITE..\n");
}
void adjust3bRear(BTree *T,int i)
{
	int j;
	printf("3bRear..\n");
	(*T)->c[i-1]->k[t] = (*T)->k[i];
	for(j = 1;j <= t-1;++j)
		(*T)->c[i-1]->k[j+t] = (*T)->c[i]->k[j];
	for(j = 0;j <= t-1;++j)
		(*T)->c[i-1]->c[j+t] = (*T)->c[i]->c[j];
	(*T)->c[i-1]->keynum = 2*t-1;
	free((*T)->c[i]);
	for(j = i+1;j <= (*T)->keynum;++j)
	{
		(*T)->k[j-1] = (*T)->k[j];
		(*T)->c[j-1] = (*T)->c[j];
	}
	(*T)->keynum--;
	printf("WRITE..\n");
	printf("WRITE..\n");
	printf("WRITE..\n");
}

void BTreeDeleteMoreThanT_1(BTree *T,int key)//*T结点这时至少有t个key,根节点除外 
{
	int i,j;
	printf("READ..\n");
	for(i = 1;i <= (*T)->keynum && key > (*T)->k[i];++i);//ci-1
	if(i <= (*T)->keynum && (*T)->k[i] == key)//key在结点x中 
	{
		if((*T)->leaf)//1.x是叶子节点直接删除 
		{
			for(j = i+1;j <= (*T)->keynum;++j)
			{
				(*T)->k[j-1] = (*T)->k[j];
			}
			(*T)->keynum--;
			printf("WRITE..\n");
		}
		else//2.x是内部结点分为a.b.c三种情况 
		{
			if((*T)->c[i-1]->keynum >= t)//2.a
			{
				printf("READ..\n");
				adjust2a(T,i);
			}
			else if((*T)->c[i]->keynum >= t)//2.b
			{
				printf("READ..\n");
				adjust2b(T,i);
			}
			else//2.c
			{
				printf("READ..\n");
				printf("READ..\n");
				adjust2c(T,i);
				BTreeDeleteMoreThanT_1(&(*T)->c[i-1],key);
			}
		}
	}
	else//3.key在结点x.ci-1中 
	{
		if((*T)->c[i-1]->keynum == t-1)
		{
			if(i-2>=0)//x.ci-1左兄弟存在 
			{
				if((*T)->c[i-2]->keynum >= t)//3.a和左兄弟调整
				{
					printf("READ..\n");
					adjust3aFront(T,i);
					BTreeDeleteMoreThanT_1(&(*T)->c[i-1],key);
				}
				else if(i <= (*T)->keynum && (*T)->c[i]->keynum >= t)//3.a和右兄弟调整
				{
					printf("READ..\n");
					printf("READ..\n");
					adjust3aRear(T,i);
					BTreeDeleteMoreThanT_1(&(*T)->c[i-1],key);
				}
				else//3.b和左兄弟调整 
				{
					printf("READ..\n");
					printf("READ..\n");
					adjust3bFront(T,i);
					if((*T)->keynum == 0)
					{
						BTree p = *T;
						*T = (*T)->c[1];
						free(p);
						BTreeDeleteMoreThanT_1(T,key);
					}
					else
						BTreeDeleteMoreThanT_1(&(*T)->c[i-2],key);
				}
			}
			else//x.ci-1只有右兄弟 
			{
				if((*T)->c[i]->keynum == t-1)//3.b
				{
					printf("READ..\n");
					adjust3bRear(T,i);
					if((*T)->keynum == 0)
					{
						BTree p = *T;
						*T = (*T)->c[0];
						free(p);
						BTreeDeleteMoreThanT_1(T,key);
					}
					else
						BTreeDeleteMoreThanT_1(&(*T)->c[i-1],key);
				}
				else//3.a
				{
					printf("READ..\n");
					adjust3aRear(T,i);
					BTreeDeleteMoreThanT_1(&(*T)->c[i-1],key);
				}
			}
		}
		else//正常下降
		{
			BTreeDeleteMoreThanT_1(&(*T)->c[i-1],key);
		}
	}
}
void BTreeTraverse(BTree T)
{
	int i,j;
	BTree parent,flag;
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
				for(i = 0;i <= parent->keynum;++i)
				{
					for(j = 1;j <= parent->c[i]->keynum;++j)
						printf("%d ",parent->c[i]->k[j]);
					printf("|");
					EnQueue(&Q,parent->c[i]);
				}
				//EnQueue(&Q,flag);
			}
		}
	}
}
int main()
{
	int a[9] = {1,2,3,4,5,6,7,8,9};
	int i;
	Result res; 
	BTree BT;
	BT = (BTNode *)malloc(sizeof(BTNode));
	BT->keynum = 0;
	BT->leaf = 1;
	for(i = 0;i < 9;++i)
		BTreeInsert(&BT,a[i]);
	BTreeTraverse(BT);
	BTreeDeleteMoreThanT_1(&BT,1);
	printf("删除1之后：\n");
	BTreeTraverse(BT);
	BTreeDeleteMoreThanT_1(&BT,6);
	printf("删除6之后：\n");
	BTreeTraverse(BT);
	BTreeDeleteMoreThanT_1(&BT,3);
	printf("删除3之后：\n");
	BTreeTraverse(BT);
	BTreeDeleteMoreThanT_1(&BT,4);
	printf("删除4之后：\n");
	BTreeTraverse(BT);
	res = BTreeSearch(&BT,7);
	if(res.tag)
		printf("找到了%d:i = %d NodeKeySize = %d\n",7,res.i,res.pt->keynum);
	else
		printf("没找到\n");
}
