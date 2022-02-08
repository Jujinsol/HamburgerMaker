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

void initCats();
void printCat(int collect);
int checkCollection();

int main(void)
{
	srand(time(NULL));

	initCats();
	while (1)
	{
		printf("엔터를 치고 당신의 고양이를 만나보세요.\n");
		getchar();

		int collect = rand() % 5;
		printCat(collect);
		collection[collect] = 1;
		int collectAll = checkCollection();
		
		if (collectAll == 1)
		{
			printf("모든 고양이를 모으셨네요.\n\n");
			break;
		}
	}

	return 0;
}

void initCats()
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

void printCat(int collect)
{
	printf("  이름:  %s\n", cats[collect].name);
	printf("  나이:  %d\n", cats[collect].age);
	printf("  특징:  %s\n", cats[collect].character);
	printf("  레벨:  ");

	for (int i = 0; i < cats[collect].level; i++)
	{
		printf("★");
	}
	printf("\n");
}

int checkCollection()
{
	int collectAll = 1;

	for (int i = 0; i < 5; i++)
	{
		if (collection[i] == 1)
		{
			printf("%10s", cats[i].name);
		}
		else
		{
			printf("%10s", "(빈자리)");
			collectAll = 0;
		}
	}
	printf("\n\n====================================================\n\n");

	return collectAll;
}