#include "Heap.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

Heap::Heap()
{
	heapSize = 0;
	arrLength = 0;
	arr = (int*) malloc(sizeof(*arr));
}

Heap::Heap(int* arr, int length)
{
	heapSize = 0;
	arrLength = length;
	(*this).arr = arr;
	Build();
}

Heap::~Heap()
{
	free(arr);
}

void Heap::Clear()
{
	free(arr);
	arr = (int*)malloc(sizeof(*arr));
	arrLength = 0;
	heapSize = 0;
}

int Heap::Parent(int index)
{
	return index/2 - 1;
}

int Heap::Left(int index)
{
	return 2 * index - 1;
}

int Heap::Right(int index)
{
	return 2 * index;
}

void Heap::Heapify(int index)
{
	int l = Left(index);
	int r = Right(index);

	int largest;

	if (l < heapSize && arr[l] > arr[index])
		largest = l;
	else
		largest = arr[index];

	if (r < heapSize && arr[r] > arr[index])
		largest = r;

	if (largest != index)
	{
		Exchange(largest, index);
		Heapify(largest);
	}
}

void Heap::Build()
{
	heapSize = arrLength;

	for (int i = arrLength / 2 - 1; i >= 0; i--)
	{
		Heapify(i);
	}
}

void Heap::Add(int val)
{
	int i = heapSize;

	heapSize++;
	arrLength++;

	while (i > 0 && arr[Parent(i)] < val)
	{
		arr[i] = arr[Parent(i)];
		i = Parent(i);
	}

	arr[i] = val;
}


void Heap::Delete(int value)
{
	int index = Find(value);
	if (index < 0)
		return;

	arr[index] = arr[heapSize - 1];

	heapSize--;
	arrLength--;

	Heapify(index);
}

int Heap::Find(int value)
{
	for (int i = 0; i < heapSize; i++)
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
	/*
	ifstream file;

	file.open(file_name);

	if (file.good())
	{
		int null_stream;

		Clear();

		// chcemy pomin¹æ pierwsz¹ liczbê - jest to niepotrzebna dla nas wielkoœæ
		if (!file.eof())
			file >> null_stream;

		int value;

		while (!file.eof())
		{
			file >> value;
			Add(value);
		}

		return 1;
	}
	*/
	return 0;
}

bool Heap::Contains(int val)
{
	/*
	HeapNode* el = (*nil).next;

	while (el != nil)
	{
		if ((*el).value == val)
			return true;

		el = (*el).next;
	}
	*/
	return false;
}

void Heap::Display()
{
	/*
	cout << endl;

	HeapNode* el = (*nil).next;

	while (el != nil) {
		cout << (*el).value << " ";
		el = (*el).next;
	}

	cout << endl;
	*/
}

// Generuje tablicê wype³nion¹ liczbami z przedzia³u [min, max].
void Heap::Generate(int size, int min, int max)
{
	/*
	Clear();

	for (int i = 0; i < size; i++)
		Add(min + rand() % (max - min + 1));
	*/
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

void Heap::MenuFind()
{

}