#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
//函数状态结果代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status是函数的类型，其值是函数结果状态代码
typedef int status;
typedef enum PointerTag
{
	Link,
	Thread
}PointerTag;
typedef struct BiThrNode
{
	char data;
	struct BiThrNode* lchild, *rchild;
	PointerTag  LTag, RTag;
}BiThrNode,*BiThirTree;

status creatBiThTree(BiThirTree* T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == ' ')
		*T = NULL;
	else
	{
		*T = malloc(sizeof(BiThrNode));
		if (!*T)
			exit(OVERFLOW);
		(*T)->data = ch;
		(*T)->LTag = (*T)->RTag = Link;
		creatBiThTree(&(*T)->lchild);
		creatBiThTree(&(*T)->rchild);
	}
	return OK;
}
void inThread(BiThirTree*P)
{
    if(!*P) return;
    static BiThirTree pre=NULL;
    inThread((*P)->lchild);
    if(!(*P)->lchild)
    {
        (*P)->LTag=Thread;
        (*P)->lchild=pre;
    }
    if(pre!=NULL&&!pre->rchild)
    {
        pre->RTag=Thread;
        pre->rchild=*P;
    }
    pre=*P;
    inThread((*P)->rchild);
}
BiThirTree next(BiThrNode* p)
{
    BiThrNode* q;
    if(p->RTag==Thread)
        q=p->rchild;
    else
    {
        q=p->rchild;
        while(q->LTag==Link)
            q=q->lchild;
    }
    return q;
}
status inorderThead(BiThirTree T)
{
    BiThrNode* p;
    if(!T)
        return;
    p=T;
    while(p->LTag==Link)
        p=p->lchild;
    printf("%c ",p->data);
    while(!p->rchild)
    {
        p=next(p);
        printf("%c ",p->data);
    }
}
int main()
{
	BiThirTree B;
	creatBiThTree(&B);
	inThread(&B);
	inorderThead(B);
	return 0;
}
