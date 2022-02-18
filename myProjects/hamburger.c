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
		printf("1�� : patty (ppppppppp)\n");
		printf("2�� : cheese (ccccccccc)\n");
		printf("3�� : cabbage (cabcabcab)\n");
		printf("4�� : tomato (ttttttttt)\n");
		printf("5�� : mushroom (mmmmmmmmm)\n\n\n");

		totalTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("�� ��� �ð� : %d��\n", totalTime);
		prevTime = totalTime - prevTime;
		printf("���� ������� ��� �ð� : %d��\n", prevTime);

		// ���� ���� ����Ʈ
		
		if ((totalTime / 30) > level - 1)
		{
			printf("\n\n\n*** %d������ ���� ��***\n\n\n", level + 1);
			level++;
			if (level == 5)
			{
				printf("***���� ���� ���� ����!***\n");
				exit(0);
			}
		}
		if (prevTime >= 10)
		{
			printf("\n�ð� �ʰ��Դϴ�. ������ �����մϴ�.\n");
			exit(0);
		}

		printf("��������������������\n");
		printf("��������������������\n");
		for (int i = 0; i < level + 2; i++)
		{
			int inside = rand() % 5;
			answer[i] = inside;
			printHamburger(inside);
		}
		printf("��������������������\n");
		printf("��������������������\n\n\n");

		// ���� ���� ���� ����
		
		printf("���Ÿ� ���弼�� : ");
		for (int i = 0; i < level + 2; i++)
		{	
			scanf_s("%d", &num);
			myAnswer[i] = num-1;
			if (num > 5 || num < 1)
			{
				printf("�߸��� �Է��Դϴ�.\n");
				exit(0);
			}
		}

		printf("��������������������\n");
		printf("��������������������\n");
		for (int i = 0; i < level + 2; i++)
		{
			printHamburger(myAnswer[i]);
		}
		printf("��������������������\n");
		printf("��������������������\n");
		

		for (int i = 0; i < level + 2; i++)
		{
			if (answer[i] == myAnswer[i])
			{
				continue;
			}
			else 
			{
				printf("���Ű� �ùٸ� ������ ������ �ʾҽ��ϴ�.\n");
				exit(0);
			}
		}
		printf("\n\n***����***\n\n");

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