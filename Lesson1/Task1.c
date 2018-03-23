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

//Балеев В.С. 
//Задание № 3. 
//*Реализовать алгоритм поиска простых чисел «Решето Эратосфена».
//**Вывести самое большое число найденное с помощью этого алгоритма.
//***Рассчитать время нахождения этого числа.

int main(int argc, const char *argv[])
{
	setlocale(LC_ALL, "Russian");

	int arrayNumbers[NUMBERS] = { 0 };

	int value = 0;
	long start_time, end_time;
	start_time = GetTickCount();

	//Заполнение массива, если число(индекс массива) простое, то false; иначе true
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

	//Проходим по массиву и ввыводим простые числа
	for (int i = 0; i < NUMBERS; i++)
	{
		if (!arrayNumbers[i])
		{
			printf("%d_", i);
			MaxSimpleNumbers = i;
		}
	}

	printf("\nМаксимальное простое число: %d", MaxSimpleNumbers);

	printf("\nВремя: %d", (end_time - start_time));

	printf("\n");
	system("pause");
	return 0;
}
