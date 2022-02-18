#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int level;
char patty;
char cheese;
char cabbage;
char tomato;
char mushroom;
int ingredient[5] = { 0,0,0,0,0 };
int answer[6] = { 0,0,0,0,0,0 };
int myAnswer[6] = { 0,0,0,0,0,0 };

void burgerData();
void printHamburger(int inside);


int main(void)
{
	srand(time(NULL));

	long startTime = 0;
	long prevTime = 0;
	long totalTime = 0;

	int num;
	
	burgerData();
	startTime = clock();

	while (1)
	{
		printf("1번 : patty (ppppppppp)\n");
		printf("2번 : cheese (ccccccccc)\n");
		printf("3번 : cabbage (cabcabcab)\n");
		printf("4번 : tomato (ttttttttt)\n");
		printf("5번 : mushroom (mmmmmmmmm)\n\n\n");

		totalTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("총 경과 시간 : %d초\n", totalTime);
		prevTime = totalTime - prevTime;
		printf("직전 라운드부터 경과 시간 : %d초\n", prevTime);

		// 랜덤 버거 프린트
		
		if ((totalTime / 30) > level - 1)
		{
			printf("\n\n\n*** %d레벨로 레벨 업***\n\n\n", level + 1);
			level++;
			if (level == 5)
			{
				printf("***최종 레벨 도달 성공!***\n");
				exit(0);
			}
		}
		if (prevTime >= 10)
		{
			printf("\n시간 초과입니다. 게임을 종료합니다.\n");
			exit(0);
		}

		printf("┏━━━━━━━━┓\n");
		printf("┗━━━━━━━━┛\n");
		for (int i = 0; i < level + 2; i++)
		{
			int inside = rand() % 5;
			answer[i] = inside;
			printHamburger(inside);
		}
		printf("┏━━━━━━━━┓\n");
		printf("┗━━━━━━━━┛\n\n\n");

		// 내가 버거 만들 차례
		
		printf("버거를 만드세요 : ");
		for (int i = 0; i < level + 2; i++)
		{	
			scanf_s("%d", &num);
			myAnswer[i] = num-1;
			if (num > 5 || num < 1)
			{
				printf("잘못된 입력입니다.\n");
				exit(0);
			}
		}

		printf("┏━━━━━━━━┓\n");
		printf("┗━━━━━━━━┛\n");
		for (int i = 0; i < level + 2; i++)
		{
			printHamburger(myAnswer[i]);
		}
		printf("┏━━━━━━━━┓\n");
		printf("┗━━━━━━━━┛\n");
		

		for (int i = 0; i < level + 2; i++)
		{
			if (answer[i] == myAnswer[i])
			{
				continue;
			}
			else 
			{
				printf("버거가 올바른 순서로 쌓이지 않았습니다.\n");
				exit(0);
			}
		}
		printf("\n\n***성공***\n\n");

		prevTime = totalTime;
	}

	return 0;
}

void burgerData()
{
	level = 1;

	ingredient[0] = patty;
	ingredient[1] = cheese;
	ingredient[2] = cabbage;
	ingredient[3] = tomato;
	ingredient[4] = mushroom;
}

void printHamburger(int inside)
{
	
	if (inside == 0)
	{
		printf(" ppppppppp\n");
	}
	else if (inside == 1)
	{
		printf(" ccccccccc\n");
	}
	else if (inside == 2)
	{
		printf(" cabcabcab\n");
	}
	else if (inside == 3)
	{
		printf(" ttttttttt\n");
	}
	else if (inside == 4)
	{
		printf(" mmmmmmmmm\n");
	}
	
}