#include <stdio.h>
#include <stdlib.h>

// Динамические массивы без проверки

void Task1()
{
	int N, i;
	float *mass;
	printf("\nEnter masssive size: ");
	scanf_s("%d", &N);
	mass = (float*)calloc(N, sizeof(float));
	for (i = 0; i < N; ++i)
	{
		mass[i] = 1.0 / (1 + i);
		printf("\n\nmass[%d] = %f", i, mass[i]);
	}
	getchar();
}

void Task2()
{
	int countAllocated = 1, N, i=0, j, *mass, countInput=0;
	mass = (int*)calloc(countAllocated, sizeof(int));
	while (1)
	{
		printf("\nEnter number: ");
		scanf_s("%d", &N);
		countInput++;
		if (countInput > countAllocated)
		{
			countAllocated *= 2;
			mass = (int*)realloc(mass, sizeof(int)*countAllocated);
		}
		mass[i] = N;
		i++;
		for (j = 0; j < i; ++j)
		{
			printf("\nmass[%d] = %d", j, mass[j]);
		}
	}
	getchar();
}

void Task3()
{
	
	getchar();
}

int main()
{
	int TuskNumber;
	//char key;
	do
	{
		/*if (kbhit())
		{
		key=_getch();
		}*/
		printf("\nEnter Tusk Number: ");
		scanf_s("%d", &TuskNumber);
		switch (TuskNumber)
		{
		case 1:
			Task1();
			break;
		case 2:
			Task2();
			break;
		/*case 3:
			Task3();
			break;*/
		default:
			printf("Wrong Tusk Number.\n");
		}
	} while (1 /*key!=ESC*/);
	return 0;
}