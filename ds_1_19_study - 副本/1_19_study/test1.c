#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	FILE*pf=fopen("test1.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
	fclose(pf);
	pf = NULL;
	return 0;
}