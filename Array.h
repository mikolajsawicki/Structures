#pragma once
#include <string>

using namespace std;

class Array
{
private:
	int size;
	int* ptr;

public:
	Array();

	~Array();

	int LoadFromFile(string file_name);

	bool Contains(int val);

	void Add(int index, int value);

	void Add(int value);

	void Delete(int index);

	void Display();

	void Generate(int size, int min, int max);
};