#include "sms.h"


void Insert(Link L)
{
	Link node=malloc(sizeof(Node));
	if (!node)
		return;
	printf("请输入学生ID:\n");
	scanf("%s",&(node->data.sno));
	printf("请输入学生姓名\n");
	scanf("%s",&(node->data.sname));
	node->next = NULL;
	Link p,q;
	p = L; q = L->next;
	if (L->next == NULL)
	{
		L->next = node;
	}
	else
	{
		while (q)
		{
			
			if (node->data.sno < q->data.sno)
			{
				p->next = node;
				node->next = q;
				return ;
			}
			else
			{
				p = q;
				q = q->next;
			}
		}
		p->next = node;
		return;
	}
}
void Show(Link L)
{
	Link p;
	p = L->next;
	printf("学生学号\t学生姓名\n");
	while (p)
	{
		printf("%s\t%s\n", p->data.sno, p->data.sname);
		p = p->next;
	}
}
void Delet(Link L)
{
	if (!L->next)
	{
		printf("信息为空，无法删除\n");
		exit(0);
	}
	printf("请输入要删除的学生的姓名\n");
	char s[20];
	scanf("%s", s);
	Link q = L->next;
	Link cur=L;
	while (q)
	{
		if (strcmp(q->data.sname, s) == 0)
		{
			cur->next = q->next;
			free(q);
			printf("删除成功\n");
			return;
		}
		cur = q;
		q = q->next;
	}
	printf("未找到该信息，删除失败\n");
}
void Destroy(Link L)
{
	free(L);
	L = NULL;
}