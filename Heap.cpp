#include "Heap.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

Heap::Heap()
	:BinaryTree()
{
	
}

Heap::Heap(int* arr, int length)
{
	size = length;
	(*this).arr = arr;
	Build();
}

Heap::~Heap()
{
	
}

void Heap::Clear()
{
	free(arr);
	arr = (int*) malloc(sizeof(*arr));
	size = 0;
}

int Heap::Parent(int index)
{
	return index/2;
}

int Heap::Left(int index)
{
	return 2 * index + 1;
}

int Heap::Right(int index)
{
	return 2 * index + 2;
}

void Heap::Heapify(int index)
{
	int l = Left(index);
	int r = Right(index);

	int largest;

	if (l < size && arr[l] > arr[index])
		largest = l;
	else
		largest = index;

	if (r < size && arr[r] > arr[largest])
		largest = r;

	if (largest != index)
	{
		Exchange(largest, index);
		Heapify(largest);
	}
}

void Heap::Build()
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		Heapify(i);
	}
}

void Heap::Add(int val)
{
	int i = size;

	size++;
	arr = (int*) realloc(arr, size * sizeof(*arr));

	if (arr)
	{
		while (i > 0 && arr[Parent(i)] < val)
		{
			arr[i] = arr[Parent(i)];
			i = Parent(i);
		}

		arr[i] = val;
	}
}


void Heap::Delete(int value)
{
	int index = Find(value);
	if (index < 0)
		return;

	arr[index] = arr[size - 1];

	size--;
	arr = (int*)realloc(arr, size * sizeof(*arr));

	Heapify(index);
}

int Heap::Find(int value)
{
	for (int i = 0; i < size; i++)
		if (arr[i] == value)
			return i;

	return -1;
}

void Heap::Exchange(int index_1, int index_2)
{
	int aux = arr[index_1];
	arr[index_1] = arr[index_2];
	arr[index_2] = aux;
}

// Wczytuje tablicê z pliku
int Heap::LoadFromFile(string file_name)
{
	ifstream file;

	file.open(file_name);

	if (file.good())
	{
		int null_stream;

		Clear();
		
		// Nie chcemy wczytywaæ rozmiaru z góry - ustalimy go na podstawie rzeczywistej liczby elementów.
		// (Dodano dla zgodnoœci z za³o¿eniami projektowymi)
		if (!file.eof())
			file >> null_stream;

		int value;
		int i = 0;

		while (!file.eof())
		{
			file >> value;
			Add(value);
			i++;
		}

		return 1;
	}
	
	return 0;
}

bool Heap::Contains(int val)
{
	for (int i = 0; i < size; i++)
		if (arr[i] == val)
			return true;

	return false;
}

void Heap::Display()
{
	BinaryTree::Display();
}

// Generuje tablicê wype³nion¹ liczbami z przedzia³u [min, max].
void Heap::Generate(int size, int min, int max)
{
	for (int i = 0; i < size; i++)
		Add(min + rand() % (max - min + 1));
}

void Heap::MenuDelete()
{
	int value;
	cout << " podaj wartosc:";
	cin >> value;
	Delete(value);
}

void Heap::MenuAdd()
{
	int value;

	cout << " podaj wartosc:";
	cin >> value;

	Add(value);
}