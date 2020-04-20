#include <stdio.h>
#include <stdlib.h>

// Динамические массивы с проверкой

void Task1()
{
	int N, i;
	float *mass;
	do
	{
		printf("\nEnter masssive size: ");
		scanf_s("%d", &N);
		mass = (float*)calloc(N, sizeof(float));
		if (mass == NULL)
		{
			printf("\nNot Enough Memory.");
		}
	} while (mass == NULL);
	
	for (i = 0; i < N; ++i)
	{
		mass[i] = 1.0 / (1 + i);
		printf("\nmass[%2d] = %f", i, mass[i]);
	}
	printf("\n");
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
			/*if ((int*)realloc(mass, sizeof(int)*countAllocated) == 0)
			{
				printf("\nNot Enough Memory."); break;
			}*/
			mass = (int*)realloc(mass, sizeof(int)*countAllocated);
			if (mass == NULL)
			{
				printf("\nNot Enough Memory."); break;
			}
		}
		mass[i] = N;
		i++;
		for (j = 0; j < i; ++j)
		{
			printf("\nmass[%2d] = %d", j, mass[j]);
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
	do
	{
		printf("\nEnter Tusk Number ('-1' to Exit): ");
		scanf_s("%d", &TuskNumber);
		switch (TuskNumber)
		{
		case -1:
			break;
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
	} while (TuskNumber!=-1);
	return 0;
}