#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 10000

int main_file(void)
{
	char line[MAX];
	char contents[MAX];
	char password[20];
	char c;

	printf("=== ���� ����ϱ� ===\n");
	printf("��й�ȣ�� �Է����ּ��� : ");

	int i = 0;
	while (1)
	{
		c = getch();
		if (c == 13)
		{
			password[i] = '\0';
			break;
		}
		else
		{
			printf("*");
			password[i] = c;
		}
		i++;
	}

	printf("\n\n== ��й�ȣ Ȯ���� ==\n\n");
	if (strcmp(password, "a") == 0)
	{
		printf("��й�ȣ�� ��ġ�մϴ�.\n");
		char* fileName = "C:\\Users\\SG\\Desktop\\secretdiary.txt";
		FILE* file = fopen(fileName, "a+b");

		if (file == NULL)
		{
			printf("������ �������� �ʽ��ϴ�.\n");
			return 1;
		}

		while (fgets(line, MAX, file) != NULL)
		{
			printf("%s", line);
		}
		printf("���ο� ������ �Է��ϼ���.\n�����ϰ� �����ø� EXIT�� �Է��ϼ���.\n\n");

		while (1)
		{
			scanf("%[^\n]", contents);
			getchar();

			if (strcmp(contents, "EXIT") == 0)
			{
				printf("�Է��� �����մϴ�.\n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file);
		}
		fclose(file);
	}

	else
	{
		printf("��й�ȣ�� Ʋ�Ƚ��ϴ�.\n");
	}

	return 0;
}