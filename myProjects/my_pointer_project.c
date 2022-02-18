#include <stdio.h>
#include <time.h>

int fishbowl[6];
int level;
int* cursor;

void initData();
void printFish();
void decreaseWater(long elapseTime);
int checkWater();

int main_pointer(void)
{
	long startTime = 0;
	long totalTime = 0;
	long prevTime = 0;

	int num;

	initData();

	cursor = fishbowl;
	startTime = clock();

	while (1)
	{
		printFish();
		printf("�� �� ���׿� ���� �ֽðڽ��ϱ�? : ");
		scanf_s("%d", &num);
		printf("\n");

		if (num < 1 || num>6)
		{
			printf("�߸��� �Է��Դϴ�.\n");
			continue;
		}

		totalTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("�� ��� �ð� : %d��\n", totalTime);
		prevTime = totalTime - prevTime;
		printf("���� ���ֱ���� ��� �ð� : %d��\n", prevTime);
		
		decreaseWater(prevTime);

		if (cursor[num - 1] == 0)
		{
			printf("����Ⱑ �̹� �׾����ϴ�.\n");
			exit(0);
		}
		else if (cursor[num - 1] < 100)
		{
			printf("%d�� ���׿� ���� �ݴϴ�.\n", num);
			cursor[num - 1] += 1;
		}

		if ((totalTime / 20) > level - 1)
		{
			printf("\n\n***%d�������� %d������ ���׷��̵� �ƽ��ϴ�.***\n\n", level, level+1);
			level++;
			if (level == 5)
			{
				printf("\n\n���� �����Դϴ�. ������ �����մϴ�.\n\n");
				exit(0);
			}
		}

		if (checkWater() == 0)
		{
			printf("��� ����Ⱑ �׾����ϴ�. ������ �����մϴ�.\n\n");
			exit(0);
		} 
		else
		{
			printf("����Ⱑ ����ֽ��ϴ�.\n\n");
		}

		prevTime = totalTime;
	}

	return 0;
}

void initData()
{
	level = 1;
	for (int i = 0; i < 6; i++)
	{
		fishbowl[i] = 100;
	}
}

void printFish()
{
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++)
	{
		printf(" %4d ", fishbowl[i]);
	}
	printf("\n\n");
}

void decreaseWater(long elapseTime)
{
	for (int i = 0; i < 6; i++)
	{
		fishbowl[i] -= (level * 2 * (int)elapseTime);
		if (fishbowl[i] < 0)
		{
			fishbowl[i] = 0;
		}
	}
}

int checkWater()
{
	for (int i = 0; i < 6; i++)
	{
		if (fishbowl[i] > 0)
		{
			return 1;
		}
		return 0;
	}
}