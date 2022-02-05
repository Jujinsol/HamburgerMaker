#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main_array(void)
{
	srand(time(NULL));
	printf("\n\n==발모제 찾기 게임==\n\n");
	int answer;
	int treatment = rand() % 4; // 발모제 결정

	int prevShowBottle = 0;
	int curShowBottle = 0;

	for (int i = 1; i <= 3; i++)
	{
		printf("%d번째 시도입니다.\n\n", i);
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
		printf("번 약을 바릅니다.\n\n");


		if (isIncluded == 1)
		{
			printf("성공입니다.\n\n");
		}
		else
		{
			printf("실패입니다.\n\n");
		}
		getchar();
	}

	printf("\n\n발모제는 ? ");
	scanf_s("%d", &answer);

	if (answer == treatment + 1)
	{
		printf("정답입니다~\n");
	}
	else
	{
		printf("오답입니다. 정답은 %d번 입니다.", treatment + 1);
	}


	return 0;
}