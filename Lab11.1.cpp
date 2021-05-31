#include <iostream>
using namespace std;

struct point
{
	int key; // Информационное поле
	point* next; // Переход не следующую ячейку динамической структуры данных
};

bool flag = false; // Флажок для вывода списка до и после удаления элемента

point* make_point(int n)
{
	point* first, * p;
	first = NULL;

	for (int i = n; i > 0; i--)
	{
		p = new(point);
		p->key = rand() % 50;
		p->next = first;
		first = p;
	}

	return first;
}

//удаление первого четного элемента
point* delete_point(point* first)
{
	if (first == NULL) return NULL;
	point* p = first;

	while (p->next != NULL)
	{
		if (p->key % 2 == 0 && flag == false)
		{
			while (p->next != NULL)
			{
				p->key = p->next->key;
				p = p->next;
			}
			flag = true; // флажок для вывода в консоль на 1 элемент меньше
		}
		else p = p->next;
	}

	return first;
}

//Вывод массива на экран
point* print_point(point* first)
{
	if (first == NULL)return NULL;

	point* p = first; // Объявление структуры данных

	while (p->next != NULL)
	{
		cout << p->key << " ";
		p = p->next;
	}

	if (flag == false) cout << p->key << " ";
	cout << endl;

	return first;
}

int main()
{
	system("chcp 1251>nul");

	cout << "Введите количество элементов списка: ";
	int n; // Количество элементов списка
	cin >> n;

	while (n < 2) // Защита от ввода неверных данных
	{
		cout << "Список не существует. Введите количество элементов списка больше 1: ";
		cin >> n;
	}

	point* first;

	first = make_point(n);

	print_point(first);
	delete_point(first);
	print_point(first);

	return 0;
}