#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
	int data;
	Node* lchild;
	Node* rchild;
};
void insert(Node* &T, int key)
{
	if (!T)
	{
		T = new Node;
		T->lchild = T->rchild = NULL;
		T->data = key;
	}
	else
	{
		if (key > T->data)
			insert(T->rchild, key);
		else
			insert(T->lchild, key);
	}
}
void creatBST(Node* &T,int arr[],int size)
{
	for (int i = 0; i < size; i++)
	{
		insert(T, arr[i]);
	}
}
void inOrder(Node* T)
{
	if (!T)
		return;
	inOrder(T->lchild);
	printf("%d ", T->data);
	inOrder(T->rchild);
}
int search(Node* T, int key)
{
	if (!T)
		return 0;
	else
	{
		if (T->data == key)
			return 1;
		else if (T->data > key)
			return search(T->lchild, key);
		else
			return search(T->rchild, key);
	}
	return 0;
}
void destroy(Node* &T)
{
	if (!T)
		return;
	else
	{
		if(T->lchild)
			destroy(T->lchild);
		if(T->rchild)
			destroy(T->rchild);
		delete T;
	}
}
void deleteNode(Node* &T)
{
	
	Node *p;
	if (T->lchild == NULL&&T->rchild == NULL)
	{
		p = T;
		T = NULL;
		delete p;
	}
	else if (T->rchild == NULL)
	{
		p = T;
		T = T->lchild;
		delete p;
	}
	else if (T->lchild == NULL)
	{
		p = T;
		T = T->rchild;
		delete p;
	}
	else
	{
		Node* pre = T;
		p = T->lchild;
		while (p->rchild)
		{
			pre = p;
			p = p->rchild;
		}
		T->data = p->data;
		if (pre == T)
		{
			T->lchild = p->lchild;
		}
		else
		{
			pre->rchild = p->lchild;
		}
		delete p;
	}
	
}
bool deleteBST(Node* &T, int key)
{
	
	if (!T)
		return false;
	else
	{
		if (T->data == key)
		{
			
			deleteNode(T);
		}
		else if (T->data > key)
			return deleteBST(T->lchild, key);
		else
			return deleteBST(T->rchild, key);
		return true;
	}
}
//Node* findPre(Node* &T)
//{
//
//	Node *p;
//	if (!T)
//		return NULL;
//	p = T->lchild;
//	while (p)
//		p = p->rchild;
//	return p;
//
//}
//Node* findNext(Node* T)
//{
//	
//	Node *p;
//	if (!T)
//		return NULL;
//	p = T->rchild;
//	while (p)
//		p = p->lchild;
//	return p;
//	
//}
//void change(Node* &T)
//{
//
//	Node*p,*q;
//	p = T;
//	q= findPre(p);
//
//	p->lchild = q;
//	
//	q->rchild = p;
//	
//	p->rchild = findNext(p);
//	//p->rchild->lchild = p;
//	
//}
//void linkTree(Node* &T)
//{
//	if (!T)
//		return;
//	Node* pre, *next, *start;
//	pre = T->lchild;
//	next = T->rchild;
//	while (pre!= NULL)
//	{
//		change(pre);
//		pre = pre->lchild;
//	}
//	
//	start = pre;
//	while (next != NULL)
//	{
//		change(next);
//		next = next->rchild;
//	}
//	while (start)
//	{
//		printf("%d ", start->data);
//		start = start->rchild;
//	}
//
//}
int main()
{
	Node* T = NULL;
	int arr[] = {63,55,90,98,70};
	int sz = sizeof(arr) / sizeof(arr[0]);
	creatBST(T,arr,sz);
	inOrder(T);
	cout << endl;
	cout << "请输入要查找的数字" << endl;
	int i,j, ret;
	cin >> i;
	ret = search(T, i);
	if (ret==1)
		cout << "找到了" << endl;
	else
		cout << "没有找到" << endl;
	cout << "请输入要删除的数字" << endl;
	cin >> j;
	if (deleteBST(T, j))
		printf("删除成功\n");
	else
		printf("未找到该元素，删除失败\n");
	inOrder(T);
	destroy(T);
}
