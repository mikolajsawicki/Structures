#pragma once
class Heap
{
	private:
		int* arr;
		int arrLength;
		int heapSize; 

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

		int LoadFromFile(string file_name);

		int Find(int value);

		bool Contains(int val);

		void Display();

		void Generate(int size, int min, int max);

		void Clear();
};

