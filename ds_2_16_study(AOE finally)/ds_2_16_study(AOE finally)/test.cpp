#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include <string.h>
#include <iostream>
using namespace std;
#define ERROR 0

int ve[20] = { 0 };
int vl[20] = { 0 };
typedef struct arcNode
{
	int weight;
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
	int vexnum, arcnum;
}Graph;
typedef struct
{
	VNode* base;
	int top;
}Sqstack;
void Initstack(Sqstack &S)
{
	S.base = (VNode*)malloc(sizeof(VNode));
	if (!S.base)
		return;
	S.top = -1;
}
void push(Sqstack &S, VNode V)
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
		scanf("%c", &G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
		G.vertices[i].in = 0;
	}
	for (i = 0; i < G.arcnum; i++)
	{
		getchar();
		printf("请输入边的信息(a b 权值):\n");
		char a, b; int w;
		scanf("%c %c %d", &a, &b, &w);
		int p, q;
		p = location(G, a);
		q = location(G, b);
		G.vertices[q].in += 1;
		arcNode* next = (arcNode*)malloc(sizeof(arcNode));
		if (!next)
			return;
		next->adjvex = q;
		next->weight = w;
		next->next = G.vertices[p].firstarc;
		G.vertices[p].firstarc = next;
		/*if (G.vertices[p].firstarc == NULL)
		{
		G.vertices[p].firstarc = next;
		}
		else
		{
		arcNode* h = G.vertices[p].firstarc;
		while (h->next!=NULL)
		h = h->next;
		h->next = next;
		}*/
	}
}
void show(Graph G)
{
	int i; arcNode* p;
	for (i = 0; i < G.vexnum; i++)
	{
		printf("in=%d  %c ->", G.vertices[i].in, G.vertices[i].data);
		p = G.vertices[i].firstarc;
		while (p)
		{
			printf("%d(%d)->", p->adjvex, p->weight);
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
		while (p)
		{
			q = p;
			p = p->next;
			free(q);
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
	int inVex, outVex;
	int count = 0;
	Sqstack S; VNode *V;
	Initstack(S);
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		ve[i] = 0;
		if (G.vertices[i].in == 0)
		{
			push(S, G.vertices[i]);
		}
	}
	while (!isEmpty(S))
	{
		V = pop(S);
		printf("%c ", (*V).data);
		inVex = location(G, (*V).data);
		count++;
		arcNode *p = (*V).firstarc;
		while (p)
		{
			outVex = p->adjvex;
			G.vertices[outVex].in -= 1;
			if (G.vertices[outVex].in == 0)
			{
				push(S, G.vertices[p->adjvex]);
			}
			if (ve[inVex] + p->weight > ve[outVex])
			{
				ve[outVex] = ve[inVex] + p->weight;
			}
			p = p->next;
		}
	}
	//vl数组
	for (i = 0; i < G.vexnum; i++)//初始化为ve最大值：
	{
		vl[i] = ve[G.vexnum - 1];
	}
	int resultTop = G.vexnum - 1;//=8
	while (resultTop != 0)
	{
		inVex = --resultTop;
		arcNode* p = G.vertices[inVex].firstarc;
		while (p)
		{
			outVex = p->adjvex;
			if (vl[inVex] > vl[outVex] - p->weight)
				vl[inVex] = vl[outVex] - p->weight;
			p = p->next;
		}
	}
	cout << endl;
	cout << "关键路径" << endl;
	for (inVex = 0; inVex < G.vexnum; inVex++)
	{
		arcNode* p = G.vertices[inVex].firstarc;
		while (p)
		{
			outVex = p->adjvex;
			int ee = ve[inVex];
			int el = vl[outVex] - p->weight;
			if (ee == el)
			{
				printf("<%c %c> %d\n", G.vertices[inVex].data, G.vertices[outVex].data, p->weight);
			}
			p = p->next;
		}
	}
	if (count != G.vexnum)
		printf("有环，无法进行拓扑排序\n");
}
int main()
{

	Graph G;
	creatGraph(G);
	show(G);
	paixu(G);
	destroy(G);
	cout << endl;
	cout << "ve数组：";
	for (int i = 0; i < G.vexnum; i++)
	{
		printf("%d ", ve[i]);
	}
	cout << endl;
	cout << "vl数组：";
	for (int i = 0; i < G.vexnum; i++)
	{
		printf("%d ", vl[i]);
	}
	return 0;
}