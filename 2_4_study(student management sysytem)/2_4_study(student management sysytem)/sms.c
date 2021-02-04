#include "sms.h"


void Insert(Link L)
{
	Link node=malloc(sizeof(Node));
	if (!node)
		return;
	printf("������ѧ��ID:\n");
	scanf("%s",&(node->data.sno));
	printf("������ѧ������\n");
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
	printf("ѧ��ѧ��\tѧ������\n");
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
		printf("��ϢΪ�գ��޷�ɾ��\n");
		exit(0);
	}
	printf("������Ҫɾ����ѧ��������\n");
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
			printf("ɾ���ɹ�\n");
			return;
		}
		cur = q;
		q = q->next;
	}
	printf("δ�ҵ�����Ϣ��ɾ��ʧ��\n");
}
void Destroy(Link L)
{
	free(L);
	L = NULL;
}