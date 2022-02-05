#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 10000

int main_file(void)
{
	char line[MAX];
	char contents[MAX];
	char password[20];
	char c;

	printf("=== 나의 비밀일기 ===\n");
	printf("비밀번호를 입력해주세요 : ");

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

	printf("\n\n== 비밀번호 확인중 ==\n\n");
	if (strcmp(password, "a") == 0)
	{
		printf("비밀번호가 일치합니다.\n");
		char* fileName = "C:\\Users\\SG\\Desktop\\secretdiary.txt";
		FILE* file = fopen(fileName, "a+b");

		if (file == NULL)
		{
			printf("파일이 존재하지 않습니다.\n");
			return 1;
		}

		while (fgets(line, MAX, file) != NULL)
		{
			printf("%s", line);
		}
		printf("새로운 내용을 입력하세요.\n종료하고 싶으시면 EXIT를 입력하세요.\n\n");

		while (1)
		{
			scanf("%[^\n]", contents);
			getchar();

			if (strcmp(contents, "EXIT") == 0)
			{
				printf("입력을 종료합니다.\n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file);
		}
		fclose(file);
	}

	else
	{
		printf("비밀번호가 틀렸습니다.\n");
	}

	return 0;
}