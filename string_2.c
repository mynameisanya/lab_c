#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<windows.h>

#define l 100

void Count()
{
	printf("������� ������:\n");
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
	printf("� ������ �������� %d ����\n", count);
}

void Obrat()
{	
	printf("������� ������:\n");
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
	printf("������� ������:\n");
	char str[l];
	scanf("%s", &str);
	int n;
	printf("������� ���������� ��������� ��� ��������:\n");
	scanf_s("%d", &n);
	int lenght = strlen(str);
	for (int i = lenght; i >= 0; i--)
	{
		str[i] = '\0';
	}
	printf("%s\n", str);
}

void Task(char str[]) {
	printf("�������� ���������:\n");
	printf("������� (A) ��� ������ ���������� ���� � ������\n");
	printf("������� (S) ��� ������ ������ � �������� �������\n");
	printf("������� (D) ��� ������ ������ � ���������� (n) ���������\n");
	char key = _getch();
	switch (key) {
	case 'a': Count(); break;
	case 's': Obrat(); break;
	case 'd': Delete(); break;
	case 'A': Count(); break;
	case 'S': Obrat(); break;
	case 'D': Delete(); break;
	case '�': Count(); break;
	case '�': Obrat(); break;
	case '�': Delete(); break;
	case '�': Count(); break;
	case '�': Obrat(); break;
	case '�': Delete(); break;
	default: printf("������ �������� �������"); break;
	}
}

int main() {
	char str[l];
	setlocale(LC_ALL, "rus");
	Task(str);
	_getch();
	return 0;
}