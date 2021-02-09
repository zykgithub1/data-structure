#define _CRT_SECURE_NO_WARNINGS
#ifndef EDGETYPE_H
#define EDGETYPE_H
#include <iostream>
using namespace std;
const int MaxVertex = 10;
const int MaxEdage = 100;

typedef struct EdgeType
{
	int from, to;
	int weight;
}EdgeType;

class EdgeGraph
{
private:
	int vertex[MaxVertex];
	struct EdgeType edge[MaxEdage];
	int vertexnum, edgenum;
public:
	EdgeGraph(int v,int e,int ef[],int et[],int we[])
	{
		this->vertexnum = v;
		this->edgenum = e;
		int i;
		for (i = 0; i < vertexnum; i++)
		{
			this->vertex[i] = i;
		}
		for (i = 1; i <= edgenum; i++)
		{
			edge[i].from = ef[i];
			edge[i].to = et[i];
			edge[i].weight = we[i];
		}
		edge[0].from = edge[0].to = edge[0].weight = 0;
	}
	void sort()
	{
		int i, j; int r1,rt,rf;
		for (i = 2; i <= this->edgenum; i++)
		{
			r1 = edge[i].weight; rf = edge[i].from; rt = edge[i].to;
			j = i - 1;
			while (r1 < edge[j].weight&&j>=0)
			{
				edge[j + 1] = edge[j];
				j--;
			}
			edge[j + 1].from = rf;
			edge[j + 1].to = rt;
			edge[j + 1].weight = r1;
		}
		printf("插入排序后的序列：\n");
		for (i = 0; i < this->edgenum; i++)
		{
			cout << "from\tto\tweight" << endl;
			for (i = 1; i <= this->edgenum; i++)
			{
				printf("%d\t%d\t%d\n", this->getFrom(i), this->getTo(i), this->getWeight(i));
			}
		}
	}
	int getVex()
	{
		return this->vertexnum;
	}
	int getEdge()
	{
		return this->edgenum;
	}
	int getFrom(int i)
	{
		return this->edge[i].from;
	}
	int getTo(int i)
	{
		return this->edge[i].to;
	}
	int getWeight(int i)
	{
		return this->edge[i].weight;
	}
	EdgeType* getTyEdge()
	{
		return edge;
	}
	int ret1(int i)
	{
		return this->edge[i].from;
	}
	int ret2(int i)
	{
		return this->edge[i].to;
	}
};

#endif // !EDGETYPE_H
