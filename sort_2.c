#include<stdio.h>
#include<locale.h>
#include<conio.h>
#include<time.h>
#include<windows.h>

#define n 10

int array(int Numbers[]) {
	for (int i = 0; i < n; i++) {
		Numbers[i] = rand() % n + 1;
	}
	return 1;
}

void sort1(int Numbers[]) {
	int i, X;
	do
	{
		X = 0;
		for (i = 0; i < n-1; i++)
		{
			if (Numbers[i] > Numbers[i + 1])
			{
				int tmp = Numbers[i + 1];
				Numbers[i + 1] = Numbers[i];
				Numbers[i] = tmp;
				X++;
			}
		}
	} while (X != 0);
}


void sort2(int Numbers[]) {
	for (int i = 0; i < n; i++) {
		int minpos = i;
		for (int t = i + 1; t < n; t++) {
			if (Numbers[minpos] > Numbers[t])
				minpos = t;
		}
		int temp = Numbers[minpos];
		Numbers[minpos] = Numbers[i];
		Numbers[i] = temp;
	}

}


void sort3(int Numbers[]) {
	int pos = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("i=%d  ni=%d  \n", i, Numbers[i]); 
			printf("j=%d  nj=%d  \n", j, Numbers[j]);
			if ((Numbers[i] >= Numbers[j]) && (i != j)){
				pos++;
			}
		}
		int tmp = Numbers[pos];
		Numbers[pos] = Numbers[i];
		Numbers[i] = tmp;
	}
}



void sravn() {

}

void Task(int Numbers[]) {
	printf("�������� ������ ����������:\n");
	printf("������� (A) ��� ���������� ���������\n");
	printf("������� (S) ��� ���������� �������\n");
	printf("������� (D) ��� ���������� ��������\n");
	printf("������� (F) ��� ��������� ����������� ����������\n\n");
	char key = _getch();
	switch (key) {
	case 'a': sort1(Numbers); break;
	case 's': sort2(Numbers); break;
	case 'd': sort3(Numbers); break;
	case 'f': sravn(); break;
	case 'A': sort1(Numbers); break;
	case 'S': sort2(Numbers); break;
	case 'D': sort3(Numbers); break;
	case 'F': sravn(); break;
	case '�': sort1(Numbers); break;
	case '�': sort2(Numbers); break;
	case '�': sort3(Numbers); break;
	case '�': sravn(); break;
	case '�': sort1(Numbers); break;
	case '�': sort2(Numbers); break;
	case '�': sort3(Numbers); break;
	case '�': sravn(); break;
	default: printf("������ �������� �������"); break;
	}
	printf("��������������� ������:\n");
	for (int i = 0; i < n; i++) {
		printf("%d  ", Numbers[i]);
	}
}

int main() {
	int Numbers[n], i, t, trade;
	setlocale(LC_ALL, "rus");
	srand((unsigned)time(NULL));
	array(Numbers);
	Task(Numbers);
	_getch();
	return 0;
}