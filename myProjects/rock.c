#include <stdio.h>
#include <time.h>

void win();
void defeat();

int main_rock(void)
{
	srand(time(NULL));
	int choice;
	char* array[3] = { "가위", "바위", "보" };

	printf("\n\n== 가위바위보 게임 ==\n\n");
	printf("가위는 1, 바위는 2, 보는 3입니다. 하나를 선택하세요 : ");
	scanf_s("%d", &choice);
	printf("\n당신 : %s\n", array[choice - 1]);

	if (choice < 1 || choice > 3)
	{
		printf("잘못된 값입니다. 다시 시도해주세요.");
		exit(0);
	}

	int computer = rand() % 3;

	if (computer == 0)
	{
		printf("컴퓨터 : %s\n", array[computer]);
	}
	else if (computer == 1)
	{
		printf("컴퓨터 : %s\n", array[computer]);
	}
	else if (computer == 2)
	{
		printf("컴퓨터 : %s\n", array[computer]);
	}


	if (computer + 1 == choice)
	{
		printf("\n비겼습니다. \n");
	}
	else if ((computer + 1 == 1 && choice == 2) || (computer + 1 == 2 && choice == 3) || (computer + 1 == 3 && choice == 1))
	{
		win();
	}
	else
	{
		defeat();
	}

	return 0;
}

void win()
{
	printf("\n당신이 이겼습니다.\n");
}
void defeat()
{
	printf("\n당신이 졌습니다.\n");
}