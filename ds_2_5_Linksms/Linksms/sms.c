#include "sms.h"
Link FindByname(Link L, char name[]);
void Add(Link L)
{
	
	Link node = malloc(sizeof(Node));
	if (!node)
	{
		return;
	}
	Link p; 
	printf("请输入学生Id:\n");
	scanf("%d", &node->st.Id);
	printf("请输入学生的姓名:\n");
	scanf("%s", node->st.Name);
	node->next = NULL;
	if (FindByname(L,node->st.Name)!=(Link)-1)
	{
		printf("该名字已存在，无法添加\n");
	}
	else
	{
		if (L->next == NULL)
		{
			L->next = node;
			node->pre = L;
			printf("增加成功第一个学生\n");
		}
		else
		{
			p = L->next;
			p->pre = L;
			while (p->next)
			{
				if (node->st.Id < p->st.Id)
				{
					node->next = p;
					node->pre = p->pre;
					p->pre->next = node;
					p->pre = node;
					printf("增加成功插入型\n");
					return;
				}
				else
				{
					p = p->next;
				}
			}
			p->next = node;
			node->pre = p;
			printf("增加成功结尾型\n");
			return;
		}
	}
}
void Show(Link L)
{
	Link q;
	if (!L->next)
	{
		printf("数据为空\n");
	}
	else
	{
		q = L->next;
		printf("学生ID\t\t学生姓名\n");
		while (q)
		{
			printf("%d\t\t%s\n", q->st.Id, q->st.Name);
			q = q->next;
		}
	}
}
Link FindByname(Link L, char name[])
{
	Link q = L->next;
	while (q)
	{
		if (strcmp(name, q->st.Name) == 0)
		{
			return q;
		}
		else
		{
			q = q->next;
		}
	}
	return (Link)-1;
}
void Delet(Link L)
{
	char name[20];
	if (!L->next)
	{
		printf("数据为空,无法删除\n");
		return;
	}
	else
	{
		printf("请输入要删除学生的姓名\n");
		scanf("%s", name);
		Link q = FindByname(L, name);
		if (q ==(Link) -1)
		{
			printf("系统没有该学生\n");
		}
		else
		{
			if (L->next == q&&q->next==NULL)
			{
				
				L->next = NULL;
				free(q);
				printf("删除成功\n");
			}
			else
			{
				
				q->next->pre = q->pre;
				
				q->pre->next = q->next;

				free(q);
				printf("删除成功\n");
			}
		}
	}
}
void Search(Link L)
{
	char name[20];
	printf("请输入要查找的学生姓名\n");
	scanf("%s", name);
	Link q = FindByname(L, name);
	if (q ==(Link) -1)
	{
		printf("未找到该学生\n");
	}
	else
	{
		printf("学生Id\t\t学生姓名\n");
		printf("%d\t\t%s\n", q->st.Id, q->st.Name);
	}
}
void Modify(Link L)
{
	char name[20];
	printf("请输入要查找的学生姓名\n");
	scanf("%s", name);
	Link q = FindByname(L, name);
	if (q == (Link)-1)
	{
		printf("未找到该学生\n");
	}
	else
	{
		printf("请输入新的学号\n");
		scanf("%d", &q->st.Id);
		printf("请输入新的姓名\n");
		scanf("%s", q->st.Name);
	}
	printf("修改成功\n");
}
void Count(Link L)
{
	int count = 0;
	Link q=L->next;
	if (q== NULL)
	{
		printf("人数为0\n");
	}
	else
	{
		while (q)
		{
			count++;
			q = q->next;
		}
		printf("人数为%d\n", count);
	}
}
void Save(Link L)
{
	FILE *pfWrite = fopen("Linksys.dat", "wb");
	if (!pfWrite)
	{
		printf("文件操作失败\n");
		return;
	}
	Link q = L->next;
	while (q)
	{
		fwrite(&(q->st),sizeof(student),1,pfWrite);
		q = q->next;
		
	}
	printf("保存成功\n");
	fclose(pfWrite);
	pfWrite = NULL;
}
void addtoL(Link q,Link L)
{
	if (L->next == NULL)
	{
		L->next = q;
	}
	else
	{
		Link end = L->next;
		while (end->next)
		{
			end = end->next;
		}
		end->next = q;
		q->pre = end;
	}
}
void Load(Link L)
{
	student tmp = { 0 };
	FILE *pfRead = fopen("Linksys.dat", "rb");
	if (!pfRead)
	{
		printf("流错误\n");
		return;
	}
	while (fread(&tmp, sizeof(student), 1, pfRead))
	{
		Link q = malloc(sizeof(Node));
		q->st = tmp;
		q->next = NULL;
		addtoL(q,L);
	}
	fclose(pfRead);
}