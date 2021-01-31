#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int status;
typedef int Boolean;

typedef enum {Link,Thread}PointTag;
typedef struct Node
{
	char data;
	struct Node* lchild, *rchild;
	PointTag LTag, RTag;
}Node,*ThreadTree;

status creatThreadTree(ThreadTree* T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == ' ')
		*T = NULL;
	else
	{
		if (!(*T = malloc(sizeof(Node))))
			return 0;
		(*T)->data = ch;
		(*T)->LTag = (*T)->RTag = Link;
		creatThreadTree(&((*T)->lchild));
		creatThreadTree(&(*T)->rchild);
	}
	return OK;
}
void inThread(ThreadTree T, ThreadTree *pre)
{
	if (!T) return;
	inThread(T->lchild,pre);
	if (!T->lchild)
	{
		T->LTag = Thread;
		T->lchild = *pre;
	}
	if (!((*pre)->rchild))
	{
		(*pre)->RTag = Thread;
		(*pre)->rchild = T;
	}
	*pre = T;
	inThread(T->rchild, pre);
}
status inOrderThread(ThreadTree T, ThreadTree*Thrt)
{
	if (!(*Thrt = malloc(sizeof(Node)))) return ERROR;
	(*Thrt)->RTag = Thread;
	(*Thrt)->rchild = *Thrt;
	(*Thrt)->data = 'Z';
	if (!T)
		return ERROR;
	(*Thrt)->LTag = Link;
	(*Thrt)->lchild = T;
	ThreadTree pre = *Thrt;
	inThread(T, &pre);
	pre->RTag = Thread;
	pre->rchild = *Thrt;
	(*Thrt)->rchild = pre;
	return OK;
}
status inOrderTraver(ThreadTree T)
{
	ThreadTree p=T->lchild;
	while (p!=T)
	{
		while (p->LTag == Link) p = p->lchild;
		printf("%c ", p->data);
		while (p->RTag == Thread&&p->rchild != T)
		{
			p = p->rchild;
			printf("%c ", p->data);
		}
		p = p->rchild;
	}
	return OK;
}

Node* prev(ThreadTree T)
{
	if (!T)
		return NULL;
	if (T->LTag == Thread)
		return T->lchild;
	else
	{
		T = T->lchild;
		while (T->RTag == Link)
		{
			T = T->rchild;
		}
	}
	return T;
}
void reverseTraver(ThreadTree T)
{
	ThreadTree p = T->rchild;
	printf("%c ", p->data);
	while (p != T)
	{
		p = prev(p);
		printf("%c ", p->data);
	}
}
int main()
{
	ThreadTree T,TH;
	creatThreadTree(&T);
	inOrderThread(T, &TH);
	inOrderTraver(TH);
	printf("\n");
	reverseTraver(TH);
	return 0;
}