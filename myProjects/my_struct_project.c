#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
	char* name;
	int age;
	char* character;
	int level;
} CAT;

int collection[5] = { 0,0,0,0,0 };

CAT cats[5];

void initData();
void printCat(int selected);
int checkCollection();

int main_struct(void)
{
	srand(time(NULL));

	initData();
	while (1)
	{
		printf("=== 아무 키나 눌러서 당신의 고양이를 만나보세요. ===\n\n");
		getchar();

		int selected = rand() % 5;
		printCat(selected);
		collection[selected] = 1;

		int collectAll = checkCollection();
		if (collectAll == 1)
		{
			break;
		}
	}

	return 0;
}

void initData()
{
	cats[0].name = "깜냥이";
	cats[0].age = 5;
	cats[0].character = "온순";
	cats[0].level = 1;

	cats[1].name = "귀요미";
	cats[1].age = 3;
	cats[1].character = "날카로움";
	cats[1].level = 2;

	cats[2].name = "수줍이";
	cats[2].age = 7;
	cats[2].character = "늘 잠만 잠";
	cats[2].level = 3;

	cats[3].name = "까꿍이";
	cats[3].age = 2;
	cats[3].character = "시끄러움";
	cats[3].level = 4;

	cats[4].name = "돼냥이";
	cats[4].age = 1;
	cats[4].character = "배고픔";
	cats[4].level = 5;
}

void printCat(int selected)
{
	printf("  이름  : %s\n", cats[selected].name);
	printf("  나이  : %d\n", cats[selected].age);
	printf("  성격  : %s\n", cats[selected].character);
	printf("  레벨  :");

	for (int i = 0; i < cats[selected].level; i++)
	{
		printf("★");
	}
	printf("\n");
}

int checkCollection()
{
	int collectAll = 1; // 고양이를 다 모은 상태

	printf("\n\n=== 보유한 고양이 목록 ===\n\n");
	for (int i = 0; i < 5; i++)
	{
		if (collection[i] == 0)
		{
			printf("%10s", "(빈 박스)");
			collectAll = 0; // 고양이를 다 모으지 못한 상태
		}
		else
		{
			printf("%10s", cats[i].name);
		}
	}
	printf("\n\n============================================\n\n");

	if (collectAll)
	{
		printf("\n모든 고양이를 모으셨습니다.\n");
	}

	return collectAll;
}