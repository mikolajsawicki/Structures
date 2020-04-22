#pragma once
#include "MenuStructure.h"
#include <string>

class Array
	: public MenuStructure
{
private:
	int size;
	int* ptr;

public:
	Array();

	~Array();

	int LoadFromFile(std::string file_name);

	bool Contains(int val);

	void Add(int index, int value);

	void Add(int value);

	void Delete(int index);

	void Display();

	void Generate(int size, int min, int max);

	void MenuDelete();

	void MenuAdd();
};