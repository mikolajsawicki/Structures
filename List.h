#pragma once

#include "MenuStructure.h"
#include <string>

typedef struct ListNode {
	int value;
	ListNode* next;
	ListNode* prev;
} ListNode_t;

class List
	: public MenuStructure
{
	private:
		ListNode* nil; // Wykorzystujemy model z wartownikiem. (Cormen)

	public:
		List();

		~List();

		int LoadFromFile(std::string file_name);

		bool Contains(int val);

		void Add(int value);

		void Add(int index, int value);

		void Delete(int index);

		void Display();

		void Generate(int size, int min, int max);

		void Clear();

		void MenuDelete();

		void MenuAdd();
};