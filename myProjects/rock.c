#include <stdio.h>
#include <time.h>

void win();
void defeat();

int main_rock(void)
{
	srand(time(NULL));
	int choice;
	char* array[3] = { "����", "����", "��" };

	printf("\n\n== ���������� ���� ==\n\n");
	printf("������ 1, ������ 2, ���� 3�Դϴ�. �ϳ��� �����ϼ��� : ");
	scanf_s("%d", &choice);
	printf("\n��� : %s\n", array[choice - 1]);

	if (choice < 1 || choice > 3)
	{
		printf("�߸��� ���Դϴ�. �ٽ� �õ����ּ���.");
		exit(0);
	}

	int computer = rand() % 3;

	if (computer == 0)
	{
		printf("��ǻ�� : %s\n", array[computer]);
	}
	else if (computer == 1)
	{
		printf("��ǻ�� : %s\n", array[computer]);
	}
	else if (computer == 2)
	{
		printf("��ǻ�� : %s\n", array[computer]);
	}


	if (computer + 1 == choice)
	{
		printf("\n�����ϴ�. \n");
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
	printf("\n����� �̰���ϴ�.\n");
}
void defeat()
{
	printf("\n����� �����ϴ�.\n");
}