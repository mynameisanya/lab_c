#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//сортировки

void Swap(int *x, int *y){
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

//сортировка пузырем

void SortBubble(int array[], int count){
	int i, j, noSwap;
	for (i = count - 1, noSwap = 0; (i >= 0) && (noSwap == 0); --i){
		noSwap = 1;
		for (j = 0; j<i; ++j){
			if (array[j]>array[j + 1]){
				Swap(&array[j], &array[j + 1]);// &*(array + j)
				noSwap = 0;
			}
		}
	}
}

//сортировка выбором

void SortChoice(int array[], int count){
	int i, j, min;
	for (i = 0; i < count; ++i){
		min = i;
		for (j = i + 1; j < count; ++j){
			if (array[j] < array[min]){
				min = j;
			}
		}
		Swap(&array[i], &array[min]);
	}
}

//сортировка вставкой

void SortPaste(int array[], int count){
	int i, j;
	for (i = 1; i < count; ++i){
		for (j = i; (j > 0)&&(array[j-1]>array[j]); --j){
			Swap(&array[j - 1], &array[j]);
			}
	}
}

int Checking(int array1[], int array2[], int count){
	for (int i = 0; i<count; ++i){
		if (array1[i] != array2[i]){
			return 0;
		}
	}
	return 1;
}

void Task1()
{
	int count = 10, i, Numbers[10];
	srand((unsigned)time(NULL));
	for (i = 0; i<count; ++i){
		Numbers[i] = rand() % 11;
		printf("\nA[%d] = %d", i, Numbers[i]);
	}
	SortBubble(Numbers, count);
	printf("\n\nSort Bubble:\n");
	for (i = 0; i<count; ++i){
		printf("\nA[%d] = %d", i, Numbers[i]);
	}
	getchar();
}

void Task2()
{
	int count = 10, i, Numbers[10];
	srand((unsigned)time(NULL));
	for (i = 0; i<count; ++i){
		Numbers[i] = rand() % 11;
		printf("\nA[%d] = %d", i, Numbers[i]);
	}
	SortChoice(Numbers, count);
	printf("\n\nSort Choice:\n");
	for (i = 0; i<count; ++i){
		printf("\nA[%d] = %d", i, Numbers[i]);
	}
	getchar();
}

void Task3()
{
	int count = 10, i, Numbers[10];
	srand((unsigned)time(NULL));
	for (i = 0; i<count; ++i){
		Numbers[i] = rand() % 11;
		printf("\nA[%d] = %d", i, Numbers[i]);
	}
	SortPaste(Numbers, count);
	printf("\n\nSort Paste:\n");
	for (i = 0; i<count; ++i){
		printf("\nA[%d] = %d", i, Numbers[i]);
	}
	getchar();
}

void Task4()
{
	int count = 10, i, Numbers1[10], Numbers2[10], Numbers3[10];
	srand((unsigned)time(NULL));
	for (i = 0; i<count; ++i){
		Numbers1[i] = rand() % 11;
		printf("\nA[%d] = %d", i, Numbers1[i]);
	}
	for (i = 0; i<count; ++i){
		Numbers2[i] = Numbers1[i];
		Numbers3[i] = Numbers1[i];
	}
	SortBubble(Numbers1, count);
	SortChoice(Numbers2, count);
	SortPaste(Numbers3, count);
	printf("\n\nSort Bubble:\t\t\tSort Choice:\t\t\tSort Paste:\n");
	for (i = 0; i<count; ++i){
		printf("\nA[%d] = %d\t\t\tA[%d] = %d\t\t\tA[%d] = %d", i, Numbers1[i], i, Numbers2[i], i, Numbers3[i]);
	}
	if ((Checking(Numbers1, Numbers2, count)) && (Checking(Numbers2, Numbers3, count))){
		printf("\n\nResults identical.\n");
	}
	else {
		printf("\n\nResults not identical.\n");
	}
	getchar();
}

int main(){
	int TuskNumber;
	while (1){
		printf("\nEnter Tusk Number: ");
		scanf_s("%d", &TuskNumber);
		switch (TuskNumber){
		case 1: Task1(); break;
		case 2: Task2(); break;
		case 3: Task3(); break;
		case 4: Task4(); break;
		default: printf("Wrong Tusk Number.\n");
		}
	}
}