//Подключение необходимых библиотек
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<locale.h>
#include<iso646.h>
#include<math.h>


void clrscr()
{
	system("@cls||clear");
}

//Быстрый метод сортировки
void fastSort(long double* array3, int start, int end)
{
	printf("Пожалуйста, подождите. Идет процесс сортировки\n");

	int left = start;
	int right = end;

	long double middle = array3[(left + right) / 2];
	while (left <= right)
	{
		while (array3[left] < middle)
		{
			left++;
		}
		while (array3[right] > middle)
		{
			right--;
		}
		if (left <= right)
		{
			double buff = array3[left];
			array3[left] = array3[right];
			array3[right] = buff;
			left++;
			right--;
		}
    	if (start < right){
		fastSort(array3, start, right);
  }
	  if (end > left){
		  fastSort(array3, left, end);
  }
	}
}

//Пузырьковая сортировка
void bSort(long double* array1, int size) {
	printf("Пожалуйста, подождите. Идет процесс сортировки\n");
	int a, b;
	long double c;

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size - (a + 1); b++)
		{
			if (array1[b] > array1[b + 1])
			{
				c = array1[b];
				array1[b] = array1[b + 1];
				array1[b + 1] = c;
			}
		}
	}


}

//Сортировка вставками
void sortInsertion(long double* array2, int size)
{
	printf("Пожалуйста, подождите. Идет процесс сортировки\n");
	long double b;
	int f, k;

	for (f = 1; f < size; f++)
	{
		for (k = f; k > 0 and array2[k - 1] > array2[k]; k--)
		{
			b = array2[k];
			array2[k] = array2[k - 1];
			array2[k - 1] = b;
		}
	}

}

const long double RAND_MAX_F = RAND_MAX;

int stringCount(FILE* strC) {
	int result = 0;
	while (!ferror(strC) and !feof(strC)) {
		if (fgetc(strC) == '\n')
			result++;
	}
	rewind(strC);
	return result;
}


int main()
{
	int size, flag = 0, flag2 = 0, i;
	double startTime, endTime, time_on_prog;
	long double* MASSIVE1, * MASSIVE2;

	FILE* file = fopen("textFile.txt", "r");

	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	printf("Читаем файл\n\n");

	size = stringCount(file);

	MASSIVE1 = (long double*)malloc(size * sizeof(long double));
	MASSIVE2 = (long double*)malloc(size * sizeof(long double));

	if (MASSIVE1 == 0 or MASSIVE2 == 0)
		return 1;

	for (int i = 0; i < size; i++)
		fscanf(file, "%Lf", &MASSIVE1[i]);


	memcpy(MASSIVE2, MASSIVE1, sizeof(long double) * size);

	do
	{
		printf("Выберете действие:\n1. Сортировка\n2. Распечатать числа\n3. Сброс\n4. Выйти\n\nВЫБОР: ");

		do
		{
			scanf("%d", &flag);
			if (flag < 1 or flag > 4)
			{
				printf("Ошибка. Введите значение снова\n\nВЫБОР:");
			}
		} while (flag < 1 or flag > 4);

		if (flag == 1)
		{
			clrscr();
			printf("Выберите способ сортировки:\n1. Пузырьком\n2. Вставками\n3. Быстрая\n4. Вернуться в меню\n\nВыбор:");
			do
			{
				scanf("%d", &flag2);
				if (flag2 < 1 or flag2 > 4)
				{
					printf("Неверный ввод. Введите снова\n Выбор:");
				}
			} while (flag2 < 1 or flag2 > 4);


			if (flag2 == 1)
			{
				clrscr();
				startTime = clock();
				bSort(MASSIVE2, size);
				endTime = clock();

				time_on_prog = (double)(endTime - startTime) / 1000;

				printf("Соритровка завершена\n");
				printf("Время выполнения %f\n\n", time_on_prog);
			}
			else if (flag2 == 2)
			{
				clrscr();
				startTime = clock();
				sortInsertion(MASSIVE2, size);
				endTime = clock();

				time_on_prog = (double)(endTime - startTime) / 1000;

				printf("Сортировка завершена\n");
				printf("Время выполнения %f\n\n", time_on_prog);
			}

			else if (flag2 == 3)
			{
				clrscr();
				startTime = clock();
				fastSort(MASSIVE2, 0, size - 1);
				endTime = clock();

				time_on_prog = (double)(endTime - startTime) / 1000;

				printf("Сортировка завершена\n");
				printf("Время выполнения %f\n\n", time_on_prog);
			}
			else
			{
				clrscr();
			}
		}
		if (flag == 2)
		{
			for (i = 0; i < size; i++)
				printf("%d) %Lf\n", i, MASSIVE2[i]);
		}
		if (flag == 3)
		{
			clrscr();
			memcpy(MASSIVE2, MASSIVE1, sizeof(long double) * size);
			printf("Сортировка успешно сброшена.\n\n");

		}
		if (flag == 4)
		{
			printf("Программа завершена\n");
			return 0;
		}
	} while (flag == 1 or flag == 2 or flag == 3 or flag == 4);

	fclose(file);
	free(MASSIVE1);
	free(MASSIVE2);
}
