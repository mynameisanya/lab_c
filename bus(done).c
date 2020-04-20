#include <iostream>
#include <conio.h>
using namespace std;

typedef struct Bus
{
	char Number[10];
	char FIO[40];
	int NumRoute;
	struct Bus *next;
}BusData;

BusData *headPark = nullptr, *headRoute = nullptr, *endPark = nullptr, *endRoute = nullptr;

BusData *Create()
{
	BusData *p = new BusData;
	cout << "Enter Number: ";
	cin >> p->Number;
	cout << "Enter FIO: ";
	cin >> p->FIO;
	cout << "Enter NumRoute: ";
	cin >> p->NumRoute;
	cout << endl;
	p->next = nullptr;
	return p;
}

void Show(BusData *h)
{
	BusData *p = h;
	if (!p)
	{
		cout << "Empty" << endl;
		return;
	}
	while (p)
	{
		cout << p->Number << " " << p->FIO << " " << p->NumRoute << endl;
		p = p->next;
	}
}

BusData *Search(BusData *h, char word[])
{
	BusData *cur = h, *t = h;
	while (cur && strcmp(cur->Number, word) != 0)
	{
		t = cur;
		cur = cur->next;
	}
	return t;
}

void menu(int &num)
{
	int x;
	char n[10];
	BusData *p;
	cout << "1 - Input" << endl;
	cout << "2 - Bus to Route" << endl;
	cout << "3 - Bus to Park" << endl;
	cout << "4 - Output in park or on route" << endl;
	cout << "5 - Exit" << endl << endl;
	cin >> num;
	cout << endl;
	switch (num)
	{
	case 1:
		if (headPark == nullptr)
		{
			headPark = Create();
			endPark = headPark;
		}
		else
		{
			p = Create();
			endPark->next = p;
			endPark = p;
		}
		break;
	case 2:
		cout << "Input bus Number to Route: ";
		cin >> n;
		cout << endl;
		if (strcmp(headPark->Number, n) == 0)
		{
			if (headRoute == nullptr)
			{
				headRoute = headPark;
				endRoute = headRoute;
				headPark = headPark->next;
				headRoute->next = nullptr;
			}
			else
			{
				endRoute->next = headPark;
				endRoute = endRoute->next;
				headPark = headPark->next;
				endRoute->next = nullptr;
			}
		}
		else
		{
			p = Search(headPark, n);
			if (p->next == nullptr)
			{
				cout << "Not found" << endl << endl;
			}
			else
			{
				if (headRoute == nullptr)
				{
					headRoute = p->next;
					endRoute = headRoute;
					p->next = p->next->next;
					headRoute->next = nullptr;
				}
				else
				{
					endRoute->next = p->next;
					endRoute = endRoute->next;
					p->next = p->next->next;
					endRoute->next = nullptr;
				}
			}
		}
		break;
	case 3:
		cout << "Input bus Number to Park: ";
		cin >> n;
		cout << endl;
		if (strcmp(headRoute->Number, n) == 0)
		{
			if (headPark == nullptr)
			{
				headPark = headRoute;
				endPark = headPark;
				headRoute = headRoute->next;
				headPark->next = nullptr;
			}
			else
			{
				endPark->next = headRoute;
				endPark = endPark->next;
				headRoute = headRoute->next;
				endPark->next = nullptr;
			}
		}
		else
		{
			p = Search(headRoute, n);
			if (p->next == nullptr)
			{
				cout << "Not found" << endl << endl;
			}
			else
			{
				if (headPark == nullptr)
				{
					headPark = p->next;
					endPark = headPark;
					p->next = p->next->next;
					headPark->next = nullptr;
				}
				else
				{
					endPark->next = p->next;
					endPark = endPark->next;
					p->next = p->next->next;
					endPark->next = nullptr;
				}
			}
		}
		break;
	case 4:
		cout << "1 - Output bus is in park" << endl;
		cout << "2 - Output bus is on route" << endl << endl;
		cin >> x;
		cout << endl;
		switch (x)
		{
		case 1: Show(headPark); break;
		case 2: Show(headRoute); break;
		}
		cout << endl;
	}
}

int main()
{
	int num = 0;
	do
	{
		menu(num);
	} while (num != 5);
	return 0;
}