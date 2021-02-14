#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include <string.h>
#define ERROR 0
int visited[100];
typedef struct arcNode
{
	int adjvex;
	struct arcNode* next;
}arcNode;

typedef struct VNode
{
	int in;
	char data;
	arcNode* firstarc;
}VNode, AdjList[30];
typedef struct
{
	AdjList vertices;
	int vexnum,arcnum;
}Graph;
typedef struct
{
	VNode* base;
	int top;
}Sqstack;
void Initstack(Sqstack &S)
{
	S.base =(VNode*)malloc(sizeof(VNode));
	if (!S.base)
		return;
	S.top = -1;
}
void push(Sqstack &S,VNode V)
{
	S.top++;
	S.base[S.top].data = V.data;
	S.base[S.top].firstarc = V.firstarc;
	S.base[S.top].in = V.in;
}
VNode* pop(Sqstack &S)
{
	if (S.top == -1)
		return NULL;
	VNode *V;
	V = &S.base[S.top];
	S.top--;
	return V;
}
int location(Graph G, char e)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data == e)
			return i;
	}
	return -1;
}
void creatGraph(Graph &G)
{
	printf("输入顶点数和边数\n");
	scanf("%d %d", &G.vexnum, &G.arcnum);
	printf("请输入顶点的信息\n");
	int i; 
	getchar();
	for (i = 0; i < G.vexnum; i++)
	{
		scanf("%c",&G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
		G.vertices[i].in = 0;
	}
	for (i = 0; i < G.arcnum; i++)
	{
		getchar();
		printf("请输入边的信息(a b):\n");
		char a, b;
		scanf("%c %c", &a,&b);
		int p,q;
		p = location(G, a);
		q = location(G, b);
		G.vertices[q].in +=1;
		arcNode* next = (arcNode*) malloc(sizeof(arcNode));
		if (!next)
			return;
		next->adjvex = q;
		next->next = NULL;
		if (G.vertices[p].firstarc == NULL)
		{
			G.vertices[p].firstarc = next;
		}
		else
		{
			arcNode* h = G.vertices[p].firstarc;
			while (h->next!=NULL)
				h = h->next;
			h->next = next;
		}
	}
}
void show(Graph G)
{
	int i; arcNode* p;
	for (i = 0; i < G.vexnum; i++)
	{
		printf("in=%d  %c ->",G.vertices[i] .in,G.vertices[i].data);
		p = G.vertices[i].firstarc;
		while(p)
		{
			printf("%d->", p->adjvex);
			p = p->next;
		}
		printf("\n");
	}
}
void destroy(Graph &G)
{
	int i; arcNode* p, *q;
	for (i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		if (p)
		{
			if (!p->next)
				free(p);
			else
			{
				while (p)
				{
					q = p;
					p = p->next;
					free(q);
				}
			}
		}
	}
}
int isEmpty(Sqstack S)
{
	if (S.top == -1)
		return 1;
	else
		return 0;
}
void paixu(Graph &G)
{
	int count = 0;
	Sqstack S; VNode *V;
	Initstack(S);
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		visited[i] = 0;
		if (G.vertices[i].in == 0)
		{
			push(S,G.vertices[i]);
			visited[i] = 1;
		}
	}
	while (!isEmpty(S))
	{
		V = pop(S);
		printf("%c ", (*V).data);
		count++;
		arcNode *p = (*V).firstarc;
		while (p)
		{
			G.vertices[p->adjvex].in -= 1;
			p = p->next;
		}
		for (i = 0; i < G.vexnum; i++)
		{
			if (visited[i] == 0 && G.vertices[i].in == 0)
			{
				push(S, G.vertices[i]);
				visited[i] = 1;
			}
				
		}
	}
	//free(S.base);
	//printf("================\n");
}
int main()
{
	
	Graph G;
	creatGraph(G);
	show(G);
	paixu(G);
	destroy(G);
	
	return 0;
}