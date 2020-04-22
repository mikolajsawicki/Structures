#pragma once

#include "MenuStructure.h"
#include "BinaryTree.h"
#include <string>

class Heap
	: public MenuStructure
	, public BinaryTree
{
	public:
		Heap();

		Heap(int* arr, int length);

		~Heap();

		int Parent(int index);

		int Left(int index);

		int Right(int index);

		void Heapify(int index);

		void Exchange(int index_1, int index_2);

		void Add(int value);

		void Delete(int index);

		void Build();

		int LoadFromFile(std::string file_name);

		int Find(int value);

		bool Contains(int val);

		void Display();

		void Generate(int size, int min, int max);

		void Clear();

		void MenuDelete();

		void MenuAdd();
};

