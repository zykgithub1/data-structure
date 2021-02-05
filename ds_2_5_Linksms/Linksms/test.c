#include "sms.h"

void menu(){
	printf(" * * * * * * * * * 菜     单 * * * * * * * * * *\n");
	printf("     1 增加学生记录            2 删除学生记录                     \n");
	printf("     3 查找学生记录            4 修改学生记录                     \n");
	printf("     5 统计学生人数            6 显示学生记录                     \n");
	printf("     7 退出系统                8 保存                     \n");
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
		printf("请选择>");
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
			printf("退出系统\n");
			break;
		case 8:
			Save(head);
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	
	free(head);
	return 0;
}