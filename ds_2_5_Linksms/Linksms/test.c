#include "sms.h"

void menu(){
	printf(" * * * * * * * * * ��     �� * * * * * * * * * *\n");
	printf("     1 ����ѧ����¼            2 ɾ��ѧ����¼                     \n");
	printf("     3 ����ѧ����¼            4 �޸�ѧ����¼                     \n");
	printf("     5 ͳ��ѧ������            6 ��ʾѧ����¼                     \n");
	printf("     7 �˳�ϵͳ                8 ����                     \n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * * *\n");
}
int main()
{

	int input;
	Link head = malloc(sizeof(Node));
	if (!head) return 0;
	head->next = NULL;
	head->pre = NULL;
	Load(head);
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Add(head);
			break;
		case 2:
			Delet(head);
			break;
		case 3:
			Search(head);
			break;
		case 4:
			Modify(head);
			break;
		case 5:
			Count(head);
			break;
		case 6:
			Show(head);
			break;
		case 7:
			printf("�˳�ϵͳ\n");
			break;
		case 8:
			Save(head);
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	
	free(head);
	return 0;
}