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
	printf("������ѧ��Id:\n");
	scanf("%d", &node->st.Id);
	printf("������ѧ��������:\n");
	scanf("%s", node->st.Name);
	node->next = NULL;
	if (FindByname(L,node->st.Name)!=(Link)-1)
	{
		printf("�������Ѵ��ڣ��޷����\n");
	}
	else
	{
		if (L->next == NULL)
		{
			L->next = node;
			node->pre = L;
			printf("���ӳɹ���һ��ѧ��\n");
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
					printf("���ӳɹ�������\n");
					return;
				}
				else
				{
					p = p->next;
				}
			}
			p->next = node;
			node->pre = p;
			printf("���ӳɹ���β��\n");
			return;
		}
	}
}
void Show(Link L)
{
	Link q;
	if (!L->next)
	{
		printf("����Ϊ��\n");
	}
	else
	{
		q = L->next;
		printf("ѧ��ID\t\tѧ������\n");
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
		printf("����Ϊ��,�޷�ɾ��\n");
		return;
	}
	else
	{
		printf("������Ҫɾ��ѧ��������\n");
		scanf("%s", name);
		Link q = FindByname(L, name);
		if (q ==(Link) -1)
		{
			printf("ϵͳû�и�ѧ��\n");
		}
		else
		{
			if (L->next == q&&q->next==NULL)
			{
				
				L->next = NULL;
				free(q);
				printf("ɾ���ɹ�\n");
			}
			else
			{
				
				q->next->pre = q->pre;
				
				q->pre->next = q->next;

				free(q);
				printf("ɾ���ɹ�\n");
			}
		}
	}
}
void Search(Link L)
{
	char name[20];
	printf("������Ҫ���ҵ�ѧ������\n");
	scanf("%s", name);
	Link q = FindByname(L, name);
	if (q ==(Link) -1)
	{
		printf("δ�ҵ���ѧ��\n");
	}
	else
	{
		printf("ѧ��Id\t\tѧ������\n");
		printf("%d\t\t%s\n", q->st.Id, q->st.Name);
	}
}
void Modify(Link L)
{
	char name[20];
	printf("������Ҫ���ҵ�ѧ������\n");
	scanf("%s", name);
	Link q = FindByname(L, name);
	if (q == (Link)-1)
	{
		printf("δ�ҵ���ѧ��\n");
	}
	else
	{
		printf("�������µ�ѧ��\n");
		scanf("%d", &q->st.Id);
		printf("�������µ�����\n");
		scanf("%s", q->st.Name);
	}
	printf("�޸ĳɹ�\n");
}
void Count(Link L)
{
	int count = 0;
	Link q=L->next;
	if (q== NULL)
	{
		printf("����Ϊ0\n");
	}
	else
	{
		while (q)
		{
			count++;
			q = q->next;
		}
		printf("����Ϊ%d\n", count);
	}
}
void Save(Link L)
{
	FILE *pfWrite = fopen("Linksys.dat", "wb");
	if (!pfWrite)
	{
		printf("�ļ�����ʧ��\n");
		return;
	}
	Link q = L->next;
	while (q)
	{
		fwrite(&(q->st),sizeof(student),1,pfWrite);
		q = q->next;
		
	}
	printf("����ɹ�\n");
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
		printf("������\n");
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