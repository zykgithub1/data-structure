#define _CRT_SECURE_NO_WARNINGS
#include "sms.h"



void menu()
{
	printf(" * * * * * * * * * ��     �� * * * * * * * * * *\n");
	printf("     1 ����ѧ����¼            2 ɾ��ѧ����¼                     \n");
	printf("     3 ����ѧ����¼            4 �޸�ѧ����¼                     \n");
	printf("     5 ͳ��ѧ������            6 ��ʾѧ����¼                     \n");
	printf("     0 �˳�ϵͳ                                     \n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * *\n");
}
int main()
{
	Link L;
	L = malloc(sizeof(Node));
	L->next = NULL;
	int input;
	int n = 1;
	do
	{
		menu();
		printf("������������:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Insert(L);
			break;
		case 2:
			Delet(L);
			break;
		case 3:
			printf("3\n");
			break;
		case 4:
			printf("4\n");
			break;
		case 5:
			printf("5\n");
			break;
		case 6:
			Show(L);
			break;
		case 7:
			Destroy(L);
			printf("�˳�����ϵͳ\n");
			break;
		default:
			printf("��������ȷ��ѡ��:\n");
			break;
		}
	} while (input);
	return 0;
}