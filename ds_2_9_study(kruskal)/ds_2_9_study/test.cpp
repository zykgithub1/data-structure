#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "EdgeType.h"
using namespace std;

void print(EdgeGraph G);
void kruskal(EdgeGraph G);
int findRoot(int parent[], EdgeGraph G);
void outputMST(EdgeGraph G, int k);
int main()
{
	int vernum, edge, f, t, w, i;
	int from[MaxEdage] = { 0 };
	int to[MaxEdage] = { 0 };
	int weight[MaxEdage] = { 0 };
	printf("输入顶点个数和边数\n");
	{
		scanf("%d %d", &vernum, &edge);
	}
	printf("请输入边的起点，终点，权值 格式(1 2 15)\n");
	for (i = 1; i <= edge; i++)
	{
		scanf("%d %d %d", &f, &t, &w);
		from[i] = f; to[i] = t; weight[i] = w;
		getchar();
	}
	EdgeGraph G(vernum, edge, from, to, weight);
	print(G);
	cout << endl;
	G.sort();
	kruskal(G);
	return 0;
}

int findRoot(int parent[], int t)
{
	int v = t;
	while (parent[t] != -1)
	{
		t = parent[t];
	}
	return t;
}

void outputMST(EdgeGraph G, int k)
{
	EdgeType* fuck = G.getTyEdge();
	printf("(%d->%d)%d\n", fuck[k].from, fuck[k].to, fuck[k].weight);
}

void kruskal(EdgeGraph G)
{
	int i; int parent[100] = { 0 };
	int vex1, vex2, num;
	for (i = 0; i < G.getVex(); i++)
	{
		parent[i] = -1;
	}
	for (num=0,i = 0; i < G.getEdge(); i++)
	{
		EdgeType* fuck = G.getTyEdge();
		vex1 = findRoot(parent, fuck[i].from);
		vex2 = findRoot(parent, fuck[i].to);
		if (vex1 != vex2)
		{
			outputMST(G,i);
			parent[vex2] = vex1;
			num++;
			if (num == G.getVex() - 1)
			{
				return;
			}
		}
	}
}


void print(EdgeGraph G)
{
	int i;
	printf("点集为：\n");
	for (i = 0; i < G.getVex(); i++)
	{
		printf("%d ", i);
	}
	cout << endl;
	cout << "from\tto\tweight" << endl;
	for (i = 1; i <= G.getEdge(); i++)
	{
		printf("%d\t%d\t%d\n", G.getFrom(i), G.getTo(i), G.getWeight(i));
	}
}