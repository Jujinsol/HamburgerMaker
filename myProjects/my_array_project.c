#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main_array(void)
{
	srand(time(NULL));
	printf("\n\n==�߸��� ã�� ����==\n\n");
	int answer;
	int treatment = rand() % 4; // �߸��� ����

	int prevShowBottle = 0;
	int curShowBottle = 0;

	for (int i = 1; i <= 3; i++)
	{
		printf("%d��° �õ��Դϴ�.\n\n", i);
		int bottle[4] = { 0,0,0,0 };
		do
		{
			curShowBottle = rand() % 2 + 2; // 2~3
		} while (prevShowBottle == curShowBottle);
		prevShowBottle = curShowBottle;

		int isIncluded = 0;

		for (int j = 0; j < curShowBottle; j++)
		{

			int randBottle = rand() % 4;

			if (randBottle == treatment)
			{
				isIncluded = 1;
			}

			if (bottle[randBottle] == 0)
			{
				bottle[randBottle] = 1;
			}
			else
			{
				j--;
			}
		}

		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1)
				printf("%d ", k + 1);
		}
		printf("�� ���� �ٸ��ϴ�.\n\n");


		if (isIncluded == 1)
		{
			printf("�����Դϴ�.\n\n");
		}
		else
		{
			printf("�����Դϴ�.\n\n");
		}
		getchar();
	}

	printf("\n\n�߸����� ? ");
	scanf_s("%d", &answer);

	if (answer == treatment + 1)
	{
		printf("�����Դϴ�~\n");
	}
	else
	{
		printf("�����Դϴ�. ������ %d�� �Դϴ�.", treatment + 1);
	}


	return 0;
}