#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include <string.h>

int dist[10][10];
int path[10][10];
typedef struct {
	char vex[20];
	int vexnum;
	int arcnum;
	int matrix[20][20];
}Graph;
int location(Graph G, char e)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		if (G.vex[i] == e)
			return i;
	}
	return -1;
}
void creatGraph(Graph* G, int vexnum, int arcnum, char v1[], char v2[], int weight[],char vex[])
{
	G->vexnum = vexnum; G->arcnum = arcnum;
	int i, j;
	for (i = 0; i < G->vexnum; i++)
	{
		G->vex[i] = vex[i];
	}
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
	for (i = 0; i < G->arcnum; i++)
	{
		int m, n;
		m = location(*G, v1[i]);
		n = location(*G, v2[i]);
		G->matrix[m][n] = weight[i];
	}
}
void print(Graph G)
{
	printf("顶点集合为：\n");
	int i, j;
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%c ", G.vex[i]);
	}
	printf("矩阵：\n");
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			printf("%d ", G.matrix[i][j]);
		}
		printf("\n");
	}
	printf("dist数组：\n");
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	printf("path数组:\n");
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			printf("%d ", path[i][j]);
		}
		printf("\n");
	}
	printf("-------------\n");
}
void Ppath(int path[10][10], int i, int j,Graph G)
{
	int k;
	k = path[i][j];
	if (k == -1)
	{
		return;
	}
	Ppath(path, i, k,G);
	printf("%c ", G.vex[k]);
	Ppath(path, k, j,G);
}
void display(int dist[10][10],int path[10][10],Graph G)
{
	int i, j;
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			if (dist[i][j] == 999)
			{
				if (i != j)
				{
					printf("从%c到%c没有路径\n", G.vex[i], G.vex[j]);
				}
				
			}
			else
			{
				printf("从 %c 到 %c =>最短路径长度为 %d ,路径为：\n", G.vex[i], G.vex[j], dist[i][j]);
				printf("%c ", G.vex[i]);
				Ppath(path, i, j, G);
				printf("%c \n", G.vex[j]);
			}
		}
	}
}
void floyd(Graph G)
{
	int i, j, k;
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			dist[i][j] = G.matrix[i][j];
			path[i][j] = -1;
		}
	}
	for (k = 0; k < G.vexnum; k++)
	{
		for (i = 0; i < G.vexnum; i++)
		{
			for (j = 0; j < G.vexnum; j++)
			{
				if (dist[i][j]>dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;
				}
			}
		}
	}
	display(dist, path, G);
	printf("=====================\n");
}

int main()
{
	Graph G;
	int vexnum, arcnum, i = 0;
	char v1[100], v2[100]; int  weight[100]; char a, b; int c;
	char vex[20] = { 0 }; char point;
	printf("请输入顶点个数和边数\n");
	scanf("%d %d", &vexnum, &arcnum);
	getchar();
	printf("请输入顶点集合\n");
	for (i = 0; i < vexnum;i++)
	{
		scanf("%c", &point);
		vex[i] = point;
	}
	printf("\n");
	for (i = 0; i < arcnum; i++)
	{
		getchar();
		printf("请输入边依附的两个顶点编号和权值：\n");
		scanf("%c %c %d", &a, &b, &c);
		v1[i] = a; v2[i] = b; weight[i] = c;
	}
	creatGraph(&G, vexnum, arcnum, v1, v2, weight,vex);
	floyd(G);
	print(G);
	return 0;
}