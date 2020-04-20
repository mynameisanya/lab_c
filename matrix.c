#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3 //Размер строк и столбцов.

int main()
{
	int Matrix[N][N]; //Матрица.
	int Numbers[N]; //Массив номеров столбцов, элементы которых упорядочены по возрастанию.
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; ++i) //Заполнение и вывод матрицы.
	{
		printf("| ");
		for (int j = 0; j < N; ++j)
		{
			Matrix[i][j] = rand() % 21 - 10;
			printf(" %3d | ", Matrix[i][j]);
		}
		
		printf("\n");
	}
	
	int k = 0; //Индекс для массива номеров.
	int Dlina; //Промежуточная длина возрастающей посл-ти.
	int MaxDlina; //Макс-я длина возрастающей посл-ти.
		for (int j = 0; j < N; ++j) //Проходим по столбцам.
		{
			Dlina = 1; //Приводим промежуточную длину к начальному значению ("обнуляем").
			MaxDlina = 1; //Приводим макс-ю длину к начальному значению ("обнуляем").
			for (int i = 0; i < N-1; ++i) //Проходим по строкам в столбце.
				{
				if (Matrix[i + 1][j] >= Matrix[i][j]) //Если посл-ть возрастает,
					{
						Dlina++; //считаем её длину.
					}
				else //Иначе,
					{
						Dlina = 1; //"обнуляем" длину
					}
				if (Dlina > MaxDlina) //Если нашёлся новый максимум длины,
					{
						MaxDlina = Dlina; //сохраняем его.
					}
				}
			
			if (MaxDlina == N) //Если макс-я длина возрастающей посл-ти равна размеру столбца,
				{
					Numbers[k] = j; // то элементы всего столбца возрастают. Сохраняем его номер.
					k++; //Увеличиваем индекс.
				}
			}
		if (k == 0) //Если таких столбцов нет,
			{
				printf("\nNo results."); //выводим "Нет результатов.".
			}
		else //Иначе,
			{
				printf("\nNumbers = "); //выводим номера столбцов.
				for (int i = 0; i < k; ++i)
			{
			
		printf("%d ", Numbers[i]);
		}
		}
	getchar();
	return 0;
}