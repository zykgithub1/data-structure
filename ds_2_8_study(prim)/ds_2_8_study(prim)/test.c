#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include <string.h>


typedef struct {
	int vexnum;
	int arcnum;
	int matrix[20][20];
}Graph;
struct S
{
	int adjvex;
	int lowcost;
}shortEdge[20];
void creatGraph(Graph* G, int vexnum, int arcnum, int v1[], int v2[], int weight[])
{
	G->vexnum = vexnum; G->arcnum = arcnum;
	int i, j;
	for (i = 0; i <vexnum; i++)
	{
		for (j = 0; j <vexnum; j++)
		{
			G->matrix[i][j] = 999;
			if (i == j)
			{
				G->matrix[i][j] = 0;
			}
		}
	}
	int t = 0;
	for (j = 0; j < arcnum; j++)
	{
		G->matrix[v1[j]][v2[j]] = weight[j];
		G->matrix[v2[j]][v1[j]] = weight[j];
	}
}
void print(Graph G)
{
	int i, j;
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			printf("%d ", G.matrix[i][j]);
		}
		printf("\n");
	}
}
int minEdge(struct S shortEdge[], Graph G);
void outPrin(int k,struct S shortEdge[]);
void prim(Graph G,int start)
{
	int i, k, j;
	for (i = 0; i < G.vexnum; i++)
	{
		shortEdge[i].lowcost = G.matrix[start][i];
		shortEdge[i].adjvex = start;
	}
	shortEdge[start].lowcost = 0;
	for (i = 0; i < G.vexnum - 1; i++)
	{
		k = minEdge(shortEdge, G);
		outPrin(k, shortEdge);
		shortEdge[k].lowcost = 0;
		for (j = 0; j < G.vexnum; j++)
		{
			if (G.matrix[k][j] < shortEdge[j].lowcost)
			{
				shortEdge[j].lowcost = G.matrix[k][j];
				shortEdge[j].adjvex = k;
			}
		}
	}
}
void outPrin(int k, struct S shortEdge[])
{
	printf("(%d %d)%d\n", shortEdge[k].adjvex, k, shortEdge[k].lowcost);
}
int minEdge(struct S shortEdge[], Graph G)
{
	int i, max = 888, tmp = 0;
	for (i = 0; i < G.vexnum; i++)
	{
		if (shortEdge[i].lowcost != 0 && max>shortEdge[i].lowcost)
		{
			max = shortEdge[i].lowcost;
			tmp = i;
		}
	}
	return tmp;
}
int main()
{
	Graph G;
	int vexnum, arcnum, i = 0;
	int v1[100], v2[100], weight[100], a, b, c;
	scanf("%d %d", &vexnum, &arcnum);
	for (i = 0; i < arcnum; i++)
	{
		getchar();
		printf("请输入边依附的两个顶点编号和权值：\n");
		scanf("%d %d %d", &a, &b, &c);
		v1[i] = a; v2[i] = b; weight[i] = c;
	}
	creatGraph(&G,vexnum,arcnum,v1,v2,weight);
	print(G);
	prim(G,0);
	return 0;
}