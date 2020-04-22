#include "Array.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

Array::Array()
{
	size = 0;
	ptr = (int*)malloc(sizeof(*ptr));
}

Array::~Array()
{
	free(ptr);
}

// Wczytuje tablicê z pliku i zwraca jej rozmiar.
// Plik powinien byæ postaci [rozmiar][znak pojedynczego odstêpu][liczby rozdzielone znakiem pojedynczego odstêpu].
int Array::LoadFromFile(string file_name)
{
	ifstream file;

	file.open(file_name);

	if (file.good())
	{
		if (!file.eof())
			file >> size;

		free(ptr);
		ptr = (int*)malloc(size * sizeof(*ptr));

		int index = 0;

		for (int i = 0; i < size; i++)
		{
			if (!file.eof())
				file >> ptr[i];
		}
	}

	return 0;
}

bool Array::Contains(int val)
{
	for (int i = 0; i < size; i++)
		if (ptr[i] == val)
			return true;

	return false;
}

void Array::Add(int index, int value)
{
	if (index > size)
		return;

	size++;
	ptr = (int*) realloc(ptr, size * sizeof(*ptr));

	if (ptr)
	{
		for (int i = size - 2; i >= index; i--)
			ptr[i + 1] = ptr[i];

		ptr[index] = value;
	}
}

// Szybsza metoda dodaj¹ca element na koniec tablicy.
void Array::Add(int value)
{
	size++;
	ptr = (int*) realloc(ptr, size * sizeof(*ptr));

	if(ptr)
		ptr[size - 1] = value;
}

void Array::Delete(int index)
{
	if (index >= size)
		return;

	for (int i = index; i < size - 1; i++)
		ptr[i] = ptr[i + 1];

	size--;
	ptr = (int*) realloc(ptr, size * sizeof(*ptr));
}

void Array::Display()
{
	cout << endl;

	for (int i = 0; i < size; i++)
		cout << ptr[i] << " ";

	cout << endl;
}

// Generuje tablicê wype³nion¹ liczbami z przedzia³u [min, max].
void Array::Generate(int size, int min, int max)
{
	this->size = size;

	ptr = (int*)realloc(ptr, size * sizeof(*ptr));

	for (int i = 0; i < size; i++)
		ptr[i] = min + rand() % (max - min + 1);
}

void Array::MenuDelete()
{
	int index;
	cout << " podaj index:";
	cin >> index;
	Delete(index);
}

void Array::MenuAdd()
{
	int index, value;
	cout << " podaj index:";
	cin >> index;
	cout << " podaj wartosc:";
	cin >> value;

	Add(index, value);
}