#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
	int x;
	int y;
} Vector;

Vector CreateVector(int x, int y)
{
	Vector result;
	result.x = x;
	result.y = y;
	return result;
}

Vector ScanVector()
{
	Vector result;
	printf("\nEnter x and y: ");
	scanf_s("%d%d", &result.x, &result.y);
	return result;
}

void PrintVector(Vector V)
{
	printf("(%3d, %3d)", V.x, V.y);
}

Vector SummaVectorov(Vector A, Vector B)
{
	Vector Summa;
	Summa.x = A.x + B.x;
	Summa.y = A.y + B.y;
	return Summa;
}

Vector CreateRandomVector()
{
	Vector result;
	//srand((unsigned)time(NULL));
	result.x = rand() % 21 - 10;
	result.y = rand() % 21 - 10;
	return result;
}

void Task1()
{
	printf("\nCreate vector A: ");
	Vector A = ScanVector();
	printf("\nCreate vector B: ");
	Vector B = ScanVector();
	Vector C = SummaVectorov(A, B);
	Vector D = SummaVectorov(C, SummaVectorov(A, B));
	printf("\nVector A = "); PrintVector(A);
	printf("\nVector B = "); PrintVector(B);
	printf("\nVector C = A + B = "); PrintVector(C);
	printf("\nC + A + B = "); PrintVector(D);
	getchar();
}

void Task2()
{
	Vector Vectors[10];
	float max = 0, dlina;
	int maxi;
	for (int i = 0; i < 10; ++i)
	{
		Vectors[i] = CreateRandomVector();
		printf("\n");
		PrintVector(Vectors[i]);
		dlina = sqrt((float)(Vectors[i].x*Vectors[i].x + Vectors[i].y*Vectors[i].y));
		if (dlina > max)
		{
			max = dlina;
			maxi = i;
		}
	}
	printf("\nMax dlina vector: Vectors[%d] = ", maxi); PrintVector(Vectors[maxi]);
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
	} while (TuskNumber != -1);
	return 0;
}