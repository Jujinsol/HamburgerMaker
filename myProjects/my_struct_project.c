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
		printf("���͸� ġ�� ����� ����̸� ����������.\n");
		getchar();

		int collect = rand() % 5;
		printCat(collect);
		collection[collect] = 1;
		int collectAll = checkCollection();
		
		if (collectAll == 1)
		{
			printf("��� ����̸� �����̳׿�.\n\n");
			break;
		}
	}

	return 0;
}

void initCats()
{
	cats[0].name = "������";
	cats[0].age = 5;
	cats[0].character = "�¼�";
	cats[0].level = 1;

	cats[1].name = "�Ϳ��";
	cats[1].age = 3;
	cats[1].character = "��ī�ο�";
	cats[1].level = 2;

	cats[2].name = "������";
	cats[2].age = 7;
	cats[2].character = "�� �Ḹ ��";
	cats[2].level = 3;

	cats[3].name = "�����";
	cats[3].age = 2;
	cats[3].character = "�ò�����";
	cats[3].level = 4;

	cats[4].name = "�ų���";
	cats[4].age = 1;
	cats[4].character = "�����";
	cats[4].level = 5;
}

void printCat(int collect)
{
	printf("  �̸�:  %s\n", cats[collect].name);
	printf("  ����:  %d\n", cats[collect].age);
	printf("  Ư¡:  %s\n", cats[collect].character);
	printf("  ����:  ");

	for (int i = 0; i < cats[collect].level; i++)
	{
		printf("��");
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
			printf("%10s", "(���ڸ�)");
			collectAll = 0;
		}
	}
	printf("\n\n====================================================\n\n");

	return collectAll;
}