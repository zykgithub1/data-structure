#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
typedef char DataType;
typedef struct BiNode
{
	DataType data;
	struct BiNode* lchild;
	struct BiNode* rchild;
}BiNode;
int count = 0;
void creat(BiNode* *bt)
{
	char ch;
	ch = getchar();
	if (ch == ' ')
		*bt = NULL;
	else
	{
		*bt = malloc(sizeof(BiNode));
		if (!*bt)
			return 0;
		(*bt)->data = ch;
		creat(&(*bt)->lchild);
		creat(&(*bt)->rchild);
	}
}

void preOrder(BiNode* bt)
{
	if (bt)
	{
		printf("%c ", bt->data);
		preOrder((*bt).lchild);
		preOrder((*bt).rchild);
	}
}
void inOrder(BiNode* bt)
{
	if (bt)
	{
		inOrder((*bt).lchild);
		printf("%c ", bt->data);
		inOrder((*bt).rchild);
	}
}
void postOrder(BiNode* bt)
{
	if (bt)
	{
		postOrder((*bt).lchild);
		postOrder((*bt).rchild);
		printf("%c ", bt->data);
	}
}
void leverOrder(BiNode* bt)
{
	BiNode p;
	BiNode q[50];
	int head = 0, tail = 0;
	if (bt)
	{
		q[tail++] = *bt;
		while (head != tail)
		{
			p = q[head++];
			printf("%c ", p.data);
			if (p.lchild)
				q[tail++] = *p.lchild;
			if (p.rchild)
				q[tail++] = *p.rchild;
		}
	}
}
void release(BiNode** bt)
{
	if (*bt)
	{
		if ((*bt)->lchild)
		{
			release(&(*bt)->lchild);
		}
		if ((*bt)->rchild)
			release(&(*bt)->lchild);
		free(*bt);
		*bt = NULL;
	}
}
int getLeaves(BiNode* bt)
{
	if (!bt)
		return 0;
	if (!bt->lchild&&!bt->rchild)
		return 1;
	else
		return getLeaves(bt->lchild) + getLeaves(bt->rchild);
}
int getDepth(BiNode* bt)
{
	int i = 0,j=0;
	if (bt == NULL)
		return 0;
	else
	{
		if (bt->lchild)
			i = getDepth(bt->lchild);
		if (bt->rchild)
			j = getDepth(bt->rchild);
		if (i >= j)
			return getDepth(bt->lchild) + 1;
		else
			return getDepth(bt->rchild) + 1;
	}
}
void creatArr(char* br, BiNode* bt,int i)
{
	if (bt)
	{
		br[i] = bt->data;
		if (bt->lchild)
			creatArr(br, bt->lchild, 2 * i);
		if (bt->rchild)
			creatArr(br, bt->rchild, 2 * i + 1);
	}
}
void destroy(BiNode* *bt)
{
	if (*bt)
	{
		if ((*bt)->lchild)
			destroy(&(*bt)->lchild);
		if ((*bt)->rchild)
			destroy(&(*bt)->rchild);
		free(*bt);
		*bt = NULL;
	}
}
void find(BiNode** bt,char x)
{
	if (*bt)
	{
		if ((*bt)->data == x)
			destroy(bt);
		else
		{
			find(&(*bt)->lchild, x);
			find(&(*bt)->rchild, x);
		}
	}
}
//void copyTree(BiNode** bt, BiNode** T)
//{
//	if (*bt)
//	{
//		*T = malloc(sizeof(BiNode));
//		if (*T == NULL)
//			return;
//		(*T)->data = (*bt)->data;
//		if ((*bt)->lchild)
//			copyTree(&(*bt)->lchild, &(*T)->lchild);
//		if ((*bt)->rchild)
//			copyTree(&(*bt)->rchild, &(*T)->rchild);
//	}
//}
int cp(BiNode* bt)
{

	if (bt)
	{
		count++;
		cp(bt->lchild);
		cp(bt->rchild);
	}
	return count;
}
int isFull(BiNode* bt)
{
	if ((pow(2, getDepth(bt))-1) == count)
		return 1;
	else
		return 0;
}
int main()
{
	BiNode* bt;
	creat(&bt);
	//preOrder(bt);
	/*char br[20] = {'0'};
	creatArr(br,bt,1);
	int i;
	for (i =0; i <20; i++)
	{
         printf("%c ", br[i]);
	}*/
	preOrder(bt);
	printf("\n节点数:%d\n", cp(bt));
	int ret = isFull(bt);
	if (ret == 1)
		printf("为满二叉树\n");
	else
		printf("不是满二叉\n");
	release(&bt);

	return 0;
}
