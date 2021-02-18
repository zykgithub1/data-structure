#include <iostream>
#include <stdio.h>
using namespace std;

struct BSTNode
{
	int data;
	BSTNode* lchild;
	BSTNode* rchild;
};
typedef BSTNode* BTree;
BTree insertNode(BTree T,int key)
{
	if (T == NULL)
	{
		T = new BSTNode;
		T->data = key;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	else
	{
		if (T->data > key)
			T->lchild=insertNode(T->lchild, key);
		else
			T->rchild=insertNode(T->rchild, key);
	}
	return T;
}
void destroyBST(BTree* T)
{
	if ((*T) == NULL)
		return;
	if ((*T)->lchild)
		destroyBST(&(*T)->lchild);
	if ((*T)->rchild)
		destroyBST(&(*T)->rchild);
	delete (*T);
}
void inOrderTraver(BTree T)
{
	if (!T)
		return;
	inOrderTraver(T->lchild);
	printf("%d ", T->data);
	inOrderTraver(T->rchild);
}
int searchBST(BTree T, int key)
{
	if (!T)
		return 0;
	else
	{
		if (T->data == key)
			return 1;
		else if (T->data > key)
			return searchBST(T->lchild, key);
		else
			return searchBST(T->rchild, key);
	}
}
void deletNode(BTree* T)
{
	BSTNode*p,*pre;
	if (!(*T))
		return;
	if (!(*T)->lchild&&!(*T)->rchild)
	{
		p = (*T);
		(*T) = NULL;
		delete p;
	}
	else if ((*T)->lchild&&!(*T)->rchild)
	{
		p = (*T);
		(*T) = (*T)->lchild;
		delete p;
	}
	else if ((*T)->rchild&&!(*T)->lchild)
	{
		p = (*T);
		(*T) = (*T)->rchild;
		delete p;
	}
	else
	{
		pre = (*T);
		p = (*T)->lchild;
		while (p)
		{
			pre = p;
			p = p->rchild;
		}
		(*T)->data = p->data;
		if (pre == (*T))
		{
			(*T)->lchild = p->lchild;
		}
		else
		{
			pre->rchild = p->lchild;
		}
		delete p;
	}
}
bool deletTree(BTree *T, int key)
{
	if (!*T)
		return false;
	if ((*T)->data == key)
	{
		deletNode(T);
		return true;
	}
	else if ((*T)->data > key)
		return deletTree(&(*T)->lchild, key);
	else
		return deletTree(&(*T)->rchild, key);
}
void convert(BTree T, BTree *last)
{
	if (!T)
		return;
	if (T->lchild)
		convert(T->lchild, last);
	T->lchild = (*last);
	if (*last)
		(*last)->rchild = T;
	(*last) = T;
	if (T->rchild)
		convert(T->rchild, last);
}
BSTNode* findFirst(BTree T)
{
	BTree B = T->lchild;
	if (!T)
	{
		return NULL;
	}
	else
	{
		while (B->lchild)
		{
			B = B->lchild;
		}
		return B;
	}
}
BTree BSTtoList(BTree T)
{
	if (!T)
		return NULL;
	BSTNode* head = findFirst(T);
	BSTNode* last = NULL;
	convert(T, &last);
	return head;
}
void traverList(BTree T)
{
	BSTNode* p = T;
	if (T == NULL)
	{
		printf("头节点为空\n");
		return;
	}
	while (p)
	{
		printf("%d ", p->data);
		p = p->rchild;
	}
}
void destroyList(BTree *T)
{
	if (!(*T))
		return;
	BSTNode* p, *q;
	p = (*T);
	while (p)
	{
		q = p->rchild;
		free(p);
		p = q;
	}
}
int main()
{
	BTree T = NULL;
	int arr[] = { 65, 55, 32, 47, 59, 78, 90, 98 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++)
	{
		T = insertNode(T, arr[i]);
	}
	//inOrderTraver(T);
	cout << endl;
	BSTNode* head = BSTtoList(T);
	traverList(head);
	/*int i, j;
	cout << "输入要查找的值" << endl;
	cin >> i;
	if (searchBST(T, i) == 1)
		cout << "找到" << endl;
	else
		cout << "没找到" << endl;
	cout << "输入要删除的元素" << endl;
	cin >> j;
	deletTree(&T, j);
	inOrderTraver(T);*/
	//destroyBST(&T);
	destroyList(&head);
	return 0;
}