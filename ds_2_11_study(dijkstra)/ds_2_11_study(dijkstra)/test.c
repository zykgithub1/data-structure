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
int minDest(int dest[],Graph G,int s[])
{
	int min = 888, i, tmp;
	for (i = 0; i < G.vexnum; i++)
	{
		if (s[i] == 0 && min>dest[i])
		{
			min = dest[i];
			tmp = i;
		}
	}
	return tmp;
}
void display(int dest[], int path[], int s[], int start, int Vexnum)
{
	int i = 0;
	printf("���·��Ϊ:\n");
	int t = Vexnum - 1;
	printf("%d ", t);
	while (path[t] != start)
	{
		printf("%d ", path[t]);
		t = path[t];
	}
	printf("%d\n",start);
	for (i = 1; i < Vexnum; i++)
	{
		printf(" 0-> %d �����·��Ȩֵ�ͣ�%d\n", i, dest[i]);
	}
}
void dijkstra(Graph G, int start)
{
	start = 0;
	int s[100] = { 0 };
	int dest[100] = { 0 };
	int path[100] = { 0 };
	int i, j, k, num;
	for (i = 0; i < G.vexnum; i++)//��ʼ���������� S{�㼯��}��dist{����}��path{·������}
	{
		s[i] = 0;
		dest[i] = G.matrix[start][i];
		if (dest[i] != 999)
			path[i] = start;
		else
			path[i] = -1;
	}
	s[start] = 1;
	num = 1;
	while (num <G.vexnum)
	{
		k = minDest(dest, G, s);
		printf("k=%d\n", k);
		s[k] = 1;
		for (i = 0; i < G.vexnum; i++)
		{
			if (s[i] == 0 && dest[i]>dest[k] + G.matrix[k][i])
			{
				dest[i] = dest[k] + G.matrix[k][i];
				path[i] = k;
			}
		}
		num++;
	}
	display(dest, path, s, start, G.vexnum);
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
		printf("����������������������ź�Ȩֵ��\n");
		scanf("%d %d %d", &a, &b, &c);
		v1[i] = a; v2[i] = b; weight[i] = c;
	}
	creatGraph(&G, vexnum, arcnum, v1, v2, weight);
	print(G);
	dijkstra(G, 0);
	return 0;
}