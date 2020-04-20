#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(char *x, char *y){
	char tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}


void Task1()
{
	char string[101], i, k = 0;
	printf("Enter string: ");
	scanf("%s", string);
	for (i = 0; string[i] != 0; ++i)
	{
		// !(A && B) == !A || !B
		if (!(((string[i] >= 'a') && (string[i] <= 'z')) || ((string[i] >= 'A') && (string[i] <= 'Z'))))
		{
			k++;
		}
	}
	printf("Number of non-letter symbols: %d", k);
	getchar();
}

void Task2()
{
	char string[101], i, j = 0;
	printf("Enter string: ");
	scanf("%s", string);
	j = strlen(string) - 1;
	for (i = 0; i < j; ++i, --j)
	{
		Swap(&string[i], &string[j]);
	}
	printf("%s", string);
	getchar();
}

void Task3()
{
	char string[101];
	int i, j, lenth, n;
	printf("Enter string: ");
	scanf("%s", string);
	lenth = strlen(string);
	/*j=lenth-1;
	for (i = 0; i < j; ++i, --j)
	{
	Swap(&string[i], &string[j]);
	}
	;strnset(string, 0, 4)
	for (i = 0; i < j; ++i, --j)
	{
	Swap(&string[i], &string[j]);
	}*/
	printf("Enter n: ");
	scanf("%d", &n);
	string[lenth - n] = 0;
	printf("%s", string);
	getchar();
}

int main(){
	int TuskNumber;
	while (1){
		printf("\nEnter Tusk Number: ");
		scanf("%d", &TuskNumber);
		switch (TuskNumber){
		case 1: Task1(); break;
		case 2: Task2(); break;
		case 3: Task3(); break;
		default: printf("Wrong Tusk Number.\n");
		}
	}
  return 0;
}

//int main()
//{
//	char string[101], i, k = 0;
//	printf("Enter string: ");
//	gets_s(string);
//	for (i = 0; string[i] != 0; ++i)
//	{
//		if (!(((string[i] >= 65) && (string[i] <= 90)) || ((string[i] >= 97) && (string[i] <= 122))))
//		{
//			k++;
//		}
//	}
//	printf("Number of non-letter symbols: %d", k);
//	getchar();
//	return 0;
//}

//int main()
//{
//	char string[101], i, j = 0;
//	printf("Enter string: ");
//	gets_s(string);
//	for (i = 0; string[i] != 0; ++i)
//	{
//		j = i;
//	}
//	for (i = 0; i < j; ++i, --j)
//	{
//		Swap(&string[i], &string[j]);
//	}
//	puts(string);
//	getchar();
//	return 0;
//}

//int main(){
//		char string[101];
//		int i, j, lenth, n;
//		printf("Enter string: ");
//		gets_s(string);
//		lenth = strlen(string);
//		printf("Enter n: ");
//		scanf_s("%d", &n);
//		/*j=lenth-1;
//		for (i = 0; i < j; ++i, --j)
//		{
//		Swap(&string[i], &string[j]);
//		}
//		strnset(string, 0, n);
//		for (i = 0; i < j; ++i, --j)
//		{
//		Swap(&string[i], &string[j]);
//		}*/
//		string[lenth - n] = 0;
//		puts(string);
//		getchar(); getchar();
//		return 0;
//}