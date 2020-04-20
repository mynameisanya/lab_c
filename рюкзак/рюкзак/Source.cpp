#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	const int k = 10; // количество предметов
	const double W = 30; // вместимость рюкзака
						 //предмет берет значения веса из w, а стоимости из массива k
	double w[k] = { 10, 4, 3, 12, 5, 2, 7, 1, 3, 5 }; // масса
	double p[k] = { 12, 11, 1, 3, 36, 4, 2, 1, 13, 8 }; // стоимость
	double mass[4][k]; //массив для расчетов
	double weight = 0; //суммарный вес
	double pay = 0; // суммарная стоимость
	for (int i = 0; i<k; i++)  //подсчет коэффициентов и заполнение строк массива
	{
		mass[0][i] = (p[i] / w[i]);
		mass[1][i] = w[i];
		mass[2][i] = p[i];
		mass[3][i] = i + 1;

	}
	for (int i = 0; i<k; i++) //распологаем в порядке убывания
	{
		for (int j = 0; j<k; j++)
		{
			double tmp;
			if (mass[0][i] > mass[0][j])
			{
				for (int z = 0; z < 4; z++)
				{
					tmp = mass[z][i];
					mass[z][i] = mass[z][j];
					mass[z][j] = tmp;
				}
			}
		}
	}
	cout << "Подходящие предметы: ";
	for (int i = 0; i<k; i++)
	{
		weight += mass[1][i];
		if (weight <= W)
		{
			cout << mass[3][i] << " ";
			pay += mass[2][i];
		}
		else
		{
			weight -= mass[1][i];
		}
	}
	cout << endl << "Общий вес: " << weight << endl << "Сумма: " << pay << endl << endl;

	system("pause");
	return 0;
}