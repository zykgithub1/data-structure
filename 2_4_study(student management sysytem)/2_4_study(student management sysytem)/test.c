#define _CRT_SECURE_NO_WARNINGS
#include "sms.h"



void menu()
{
	printf(" * * * * * * * * * 菜     单 * * * * * * * * * *\n");
	printf("     1 增加学生记录            2 删除学生记录                     \n");
	printf("     3 查找学生记录            4 修改学生记录                     \n");
	printf("     5 统计学生人数            6 显示学生记录                     \n");
	printf("     0 退出系统                                     \n");
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
		printf("请输入操作序号:\n");
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
			printf("退出管理系统\n");
			break;
		default:
			printf("请输入正确的选择:\n");
			break;
		}
	} while (input);
	return 0;
}