#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <process.h>
#include <limits.h>
#include <string.h>

typedef int status;
#define OK 1
#define ERROR 0

typedef struct LNode* List;
struct LNode
{
	int data;
	struct LNode* next;
};
status InitList(List *L)/*³õÊ¼»¯*/
{
	*L = (List)malloc(sizeof(struct LNode));
	if (!*L)
		exit(0);
	(*L)->next = NULL;
	return OK;
}
void TraverList(List L,void(*vi)(int))
{
	List Q=L->next;
	while (Q)
	{
		vi(Q->data);
		Q = Q->next;
	}
	printf("\n");
}
void visit(int a)
{
	printf("%d ", a);
}/*
status ListInsert(List L)
{
	List Q=L;
	int n = 0;
	scanf("%d", &n);
	while (n != -1)
	{
		List S;
		S = (List)malloc(sizeof(struct LNode));
		S->data = n;
		Q->next = S;
		S->next = NULL;
		Q=S;
		scanf("%d",&n);
	}
	return OK;
}*/

status ListInsert(List L)
{
	int n;
	List s, p = L;
	scanf("%d", &n);
	while (n != -1)
	{
		s = (List)malloc(sizeof(struct LNode));
		s->data = n;
		s->next = NULL;
		p->next = s;
		p = s;
		scanf("%d", &n);
	}
	return OK;
}/*
List merge(List L1, List L2)
{
	List L = (List)malloc(sizeof(struct LNode));
	L->next = NULL;
	List Q = L,r,s,j;
	r = L1->next;
	s = L2->next;
	while (r&&s)
	{
		j = (List)malloc(sizeof(struct LNode));
		if (r->data <= s->data)
		{
			j->data = r->data;
			j->next = NULL;
			Q->next = j;
			Q = j;
			r = r->next;
		}
		else
		{
			j->data = s->data;
			j->next = NULL;
			Q->next = j;
			Q = j;
			s = s->next;
		}
	}
	while (r)
	{
		j = (List)malloc(sizeof(struct LNode));
		j->data = r->data;
		j->next = NULL;
		Q->next = j;
		Q = j;
		r = r->next;
	}
	while (s)
	{
		j = (List)malloc(sizeof(struct LNode));
		j->data = s->data;
		j->next = NULL;
		Q->next = j;
		Q = j;
		s = s->next;
	}
	free(L1);
	free(L2);
	return L;
}*/
/*
List merge(List L1, List L2)
{
    List q,r,cur;
    q=L1->next;r=L2->next;
    List L=(List)malloc(sizeof(struct LNode));
    L=L1;
    while(q)
    {
        cur=q;
        q=q->next;
    }
    cur->next=L2->next;
    return L;
}*/
List merge(List La, List Lb)
{
    List Lc=La,pa,pb,pc;
    pc=Lc;
    pa=La->next;
    pb=Lb->next;
    while(pa&&pb)
    {
        if(pa->data<=pb->data)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
        pc->next=pa?pa:pb;
        free(Lb);
    }
    return Lc;
}
int main()
{
	List L1, L2, L3;
	InitList(&L1);
	InitList(&L2);
	ListInsert(L1);
	ListInsert(L2);
	L3 = merge(L1, L2);
	if (!L3->next)
		printf("NULL");
	else
	{
		L3 = L3->next;
		printf("%d", L3->data);
		L3 = L3->next;
		while (L3->next)
		{
			printf(" %d", L3->data);
			L3 = L3->next;
		}
		printf(" %d", L3->data);
	}
	return 0;
}
