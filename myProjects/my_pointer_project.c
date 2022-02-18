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
		printf("몇 번 어항에 물을 주시겠습니까? : ");
		scanf_s("%d", &num);
		printf("\n");

		if (num < 1 || num>6)
		{
			printf("잘못된 입력입니다.\n");
			continue;
		}

		totalTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("총 경과 시간 : %d초\n", totalTime);
		prevTime = totalTime - prevTime;
		printf("직전 물주기부터 경과 시간 : %d초\n", prevTime);
		
		decreaseWater(prevTime);

		if (cursor[num - 1] == 0)
		{
			printf("물고기가 이미 죽었습니다.\n");
			exit(0);
		}
		else if (cursor[num - 1] < 100)
		{
			printf("%d번 어항에 물을 줍니다.\n", num);
			cursor[num - 1] += 1;
		}

		if ((totalTime / 20) > level - 1)
		{
			printf("\n\n***%d레벨에서 %d레벨로 업그레이드 됐습니다.***\n\n", level, level+1);
			level++;
			if (level == 5)
			{
				printf("\n\n최종 레벨입니다. 게임을 종료합니다.\n\n");
				exit(0);
			}
		}

		if (checkWater() == 0)
		{
			printf("모든 물고기가 죽었습니다. 게임을 종료합니다.\n\n");
			exit(0);
		} 
		else
		{
			printf("물고기가 살아있습니다.\n\n");
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
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
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