#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>

#define NUMBERS 10000

//������ �.�. 
//������� � 3. 
//*����������� �������� ������ ������� ����� ������� ����������.
//**������� ����� ������� ����� ��������� � ������� ����� ���������.
//***���������� ����� ���������� ����� �����.

int main(int argc, const char *argv[])
{
	setlocale(LC_ALL, "Russian");

	int arrayNumbers[NUMBERS] = { 0 };

	int value = 0;
	long start_time, end_time;
	start_time = GetTickCount();

	//���������� �������, ���� �����(������ �������) �������, �� false; ����� true
	for (int i = 0; i < NUMBERS; i++)
	{
		if (arrayNumbers[i] || i == 0 || i == 1)
		{
			arrayNumbers[i] = 1;
		}
		else
		{
			for (int j = i + 1; j < NUMBERS; j++)
			{
				if (arrayNumbers[j])
				{
					continue;
				}
				if (j % i == 0)
				{
					arrayNumbers[j] = 1;
					value++;
				}
			}
		}
	}

	end_time = GetTickCount();

	int MaxSimpleNumbers = 0;

	//�������� �� ������� � �������� ������� �����
	for (int i = 0; i < NUMBERS; i++)
	{
		if (!arrayNumbers[i])
		{
			printf("%d_", i);
			MaxSimpleNumbers = i;
		}
	}

	printf("\n������������ ������� �����: %d", MaxSimpleNumbers);

	printf("\n�����: %d", (end_time - start_time));

	printf("\n");
	system("pause");
	return 0;
}
