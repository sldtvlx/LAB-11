#include <iostream>
using namespace std;

struct point
{
	double key;
	point* next;
	point* prev;
};

point* make_point(int n)
{
	point* first, * p;
	p = new(point);

	p->key = rand() % 50;

	first = p;

	p->next = NULL;
	p->prev = NULL;

	for (int i = 1; i < n; i++)
	{
		point* h = new(point);
		point* q = p;

		p->next = h;
		p = p->next;
		p->key = rand() % 50;
		p->next = NULL;
		p->prev = q;
	}

	return first;
}

point* add_point(point* first, int l, int x, int n)
{
	if (first == NULL)return NULL;
	point* p = first;

	while (p->next != NULL)
	{
		p = p->next;
	}

	while (p->key != l && p->prev != NULL)
	{
		p->key = p->prev->key;
		p = p->prev;
	}

	if (p->key == l)p->next->key = x;
	p = first;

	return first;
}

point* print_point(point* first, bool flag) // вывод структуры
{
	if (first == NULL)return NULL;
	point* p = first;

	while (p->next != NULL)
	{
		cout << p->key << " ";
		p = p->next;
	}

	if (flag) cout << p->key << " ";

	cout << endl;

	return first;
}
int main()
{
	system("chcp 1251>nul");

	cout << "Введите количество элементов списка: " << endl;

	int n;
	bool flag = false;

	cin >> n;

	while (n < 2) // Защита от ввода неверных данных
	{
		cout << "Список не существует. Введите количество элементов списка больше 1: ";
		cin >> n;
	}
	point* first;
	n++;
	
	first = make_point(n);
	print_point(first, flag);
	
	flag = true;
	
	cout << "Введите элемент после которого нужно добавить элемент: " << endl;
	int l;
	cin >> l;
	
	cout << "Введите элемент который нужно добавить: ";
	int x;
	cin >> x;
	
	add_point(first, l, x, n);
	print_point(first, flag);
	
	return 0;
}