#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "List.h"

using namespace std;

List::List()
{
	nil = new ListNode;
	(*nil).prev = nil;
	(*nil).next = nil;
	(*nil).value = 0;
}

List::~List()
{
	Clear();
	delete nil;
}

void List::Clear()
{
	ListNode* el = (*nil).next;
	ListNode* el_next;

	while (el != nil)
	{
		el_next = (*el).next;
		delete el;
		el = el_next;
	}
}

// Wczytuje tablicê z pliku i zwraca jej rozmiar.
// Plik powinien byæ postaci [rozmiar][znak pojedynczego odstêpu][liczby rozdzielone znakiem pojedynczego odstêpu].
int List::LoadFromFile(string file_name)
{
	ifstream file;

	file.open(file_name);

	if(file.good())
	{
		int null_stream;

		Clear();

		// chcemy pomin¹æ pierwsz¹ liczbê - jest to niepotrzebna dla nas wielkoœæ
		if(!file.eof())
			file >> null_stream;

		int value;

		while (!file.eof())
		{
			file >> value;
			Add(value);
		}
	}
	
	return 0;
}

bool List::Contains(int val)
{
	ListNode* el = (*nil).next;

	while (el != nil)
	{
		if ((*el).value == val)
			return true;

		el = (*el).next;
	}

	return false;
}

// Przy³¹czenie elementu na koniec listy
void List::Add(int value)
{
	ListNode* node = new ListNode;
	(*node).value = value;

	(*node).next = nil;
	(*node).prev = (*nil).prev;
	(*((*nil).prev)).next = node;
	(*nil).prev = node;
}

// Przy³¹czanie na wskazan¹ pozycjê
void List::Add(int index, int value)
{
	ListNode* node = new ListNode;
	(*node).value = value;

	int i = 0;
	ListNode* el = (*nil).next;

	while (i < index)
	{
		el = (*el).next;
		i++;
	}

	(*node).next = el;
	(*node).prev = (*el).prev;
	(*((*el).prev)).next = node;
	(*el).prev = node;
}


void List::Delete(int value)
{
	ListNode* el = (*nil).next;

	while ((*el).value != value && el != nil)
		el = (*el).next;
	
	(*((*el).prev)).next = (*el).next;
	(*((*el).next)).prev = (*el).prev;

	delete el;
}

void List::Display()
{
	cout << endl;

	ListNode* el = (*nil).next;

	while (el != nil) {
		cout << (*el).value << " ";
		el = (*el).next;
	}

	cout << endl;
}

// Generuje tablicê wype³nion¹ liczbami z przedzia³u [min, max].
void List::Generate(int size, int min, int max)
{
	Clear();

	for(int i = 0; i < size; i++)
		Add(min + rand() % (max - min + 1));
}

void List::MenuDelete()
{
	int value;
	cout << " podaj wartosc:";
	cin >> value;
	Delete(value);
}

void List::MenuAdd()
{
	int index, value;
	cout << " podaj index:";
	cin >> index;
	cout << " podaj wartosc:";
	cin >> value;

	Add(index, value);
}