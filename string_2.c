#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<windows.h>

#define l 100

void Count()
{
	printf("Введите строку:\n");
	char str[l];
	scanf("%s", &str);
	int count = 0;
	int lenght = strlen(str);
	for (int i = 0; i < lenght;i++){
		if ((str[i] >= '0') || (str[i] <= '9'))
		{
			count++;
		}
	} 
	printf("В строке символов %d цифр\n", count);
}

void Obrat()
{	
	printf("Введите строку:\n");
	char str[l];
	scanf("%s", str);
	int lenght = strlen(str);
	for (int i = lenght; i >= 0; i--)
	{
		
	}
	printf("\n");
}

void Delete()
{
	printf("Введите строку:\n");
	char str[l];
	scanf("%s", &str);
	int n;
	printf("Введите количество элементов для удаления:\n");
	scanf_s("%d", &n);
	int lenght = strlen(str);
	for (int i = lenght; i >= 0; i--)
	{
		str[i] = '\0';
	}
	printf("%s\n", str);
}

void Task(char str[]) {
	printf("Выберите дейвствие:\n");
	printf("Нажмите (A) для вывода количества цифр в строке\n");
	printf("Нажмите (S) для вывода строки в обратную сторону\n");
	printf("Нажмите (D) для вывода строки с удаленными (n) символами\n");
	char key = _getch();
	switch (key) {
	case 'a': Count(); break;
	case 's': Obrat(); break;
	case 'd': Delete(); break;
	case 'A': Count(); break;
	case 'S': Obrat(); break;
	case 'D': Delete(); break;
	case 'ф': Count(); break;
	case 'ы': Obrat(); break;
	case 'в': Delete(); break;
	case 'Ф': Count(); break;
	case 'Ы': Obrat(); break;
	case 'В': Delete(); break;
	default: printf("нажата неверная клавиша"); break;
	}
}

int main() {
	char str[l];
	setlocale(LC_ALL, "rus");
	Task(str);
	_getch();
	return 0;
}