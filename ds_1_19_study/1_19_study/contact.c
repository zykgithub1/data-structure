#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "contact.h"

void DestoryContact(struct Contact* con)
{
	free(con->data);
}
void InitContact(struct Contact* con)
{
	con->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (con->data == NULL)
		return;
	con->size = 0;
	con->capacity = DEFAULT_SZ;
}
void CheakCapacity(struct Contact* con)
{
	if (con->capacity == con->size)
	{
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(con->data, (con->capacity + 2)*sizeof(struct PeoInfo));
		if (ptr == NULL)
			return;
		con->data = ptr;
		con->capacity += 2;
		printf("���ݳɹ�\n");
	}
}
void AddContact(struct Contact* con)
{
	CheakCapacity(con);
	printf("����������:>\n");
	scanf("%s", con->data[con->size].name);
	printf("����������:>\n");
	scanf("%d", &(con->data[con->size].age));
	printf("�������Ա�:>\n");
	scanf("%s", con->data[con->size].sex);
	printf("������绰:>\n");
	scanf("%s", con->data[con->size].tele);
	printf("�������ַ:>\n");
	scanf("%s", con->data[con->size].addr);
	con->size++;
	printf("¼��ɹ�\n");
	//if (con->size == DEFAULT_SZ)
	//{
	//	printf("ͨѶ¼����,�޷�����\n");
	//}
	//else
	//{
	//	printf("����������:>\n");
	//	scanf("%s", con->data[con->size].name);
	//	printf("����������:>\n");
	//	scanf("%d", &(con->data[con->size].age));
	//	printf("�������Ա�:>\n");
	//	scanf("%s", con->data[con->size].sex);
	//	printf("������绰:>\n");
	//	scanf("%s", con->data[con->size].tele);
	//	printf("�������ַ:>\n");
	//	scanf("%s", con->data[con->size].addr);
	//	con->size++;
	//	printf("¼��ɹ�\n");

	//}
}

void ShowContact(const struct Contact* con)
{
	if (con->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (i = 0; i < con->size; i++)
		{
			printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				con->data[i].name,
				con->data[i].age, 
				con->data[i].sex, 
				con->data[i].tele,
				con->data[i].addr);
		}
	}
}
static int FindByName(struct Contact* con, char* name)
{
	int i = 0;
	for (i = 0; i < con->size; i++)
	{
		if (0 == strcmp(con->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
void DelContact(struct Contact* con)
{
	char name[MAX_NAME];
	printf("������Ҫɾ���˵����֣�>");
	scanf("%s", name);
	int pos = FindByName(con, name);
	
	if (pos == con->size)
	{
		printf("ɾ�����˲�����\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < con->size - 1; j++)
		{
			con->data[j] = con->data[j + 1];
			//(*con).data[j] = (*con).data[j + 1];
		}
		con->size--;
		printf("ɾ���ɹ�\n");
	}
}
void SearchContact(struct Contact* con)
{
	char name[MAX_NAME];
	printf("��������Ҫ�����˵�����\n");
	scanf("%s", name);
	int pos=FindByName(con, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			con->data[pos].name,
			con->data[pos].age,
			con->data[pos].sex,
			con->data[pos].tele,
			con->data[pos].addr);
	}
}
void modifyContact(struct Contact* con)
{
	char name[MAX_NAME];
	printf("��������Ҫ�޸��˵�����\n");
	scanf("%s", name);
	int pos = FindByName(con, name);
	if (pos == -1)
	{
		printf("�޸��˲�����\n");
	}
	else
	{
		printf("����������:>\n");
		scanf("%s", con->data[pos].name);
		printf("����������:>\n");
		scanf("%d", &(con->data[pos].age));
		printf("�������Ա�:>\n");
		scanf("%s", con->data[pos].sex);
		printf("������绰:>\n");
		scanf("%s", con->data[pos].tele);
		printf("�������ַ:>\n");
		scanf("%s", con->data[pos].addr);
		printf("�޸ĳɹ�\n");
	}
}
//void SortContact(struct Contact* con)
//{
//	int i = 0;
//	for (i = 0; i < con->size-1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < con->size - 1 - i; j++)
//		{
//			if (con->data[j].age>con->data[j + 1].age)
//			{
//				char tname[MAX_NAME] = con->data[j].name;
//				int tage = con->data[i].age;
//				char tsex[MAX_SEX] = con->data[j].sex;
//				char ttele[MAX_TELE] = con->data[j].tele;
//				char taddr[MAX_ADDR] = con->data[j].addr;
//				con->data[j].name = con->data[j + 1].name;
//				con->data[j].age = con->data[j + 1].age;
//				con->data[j].sex = con->data[j + 1].sex;
//				con->data[j].tele = con->data[j + 1].tele;
//				con->data[j].addr = con->data[j + 1].addr;
//				con->data[j + 1].name = tname;
//			}
//		}
//	}
//}