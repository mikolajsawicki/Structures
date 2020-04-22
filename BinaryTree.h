#pragma once
#include <string>

class BinaryTree
{
	private:
		std::string cr, cl, cp; // Wykorzystywane w PrintBT.
	
	public:
		BinaryTree();
		~BinaryTree();
		int* arr;
		int size;
		void PrintBT(std::string sp, std::string sn, int v);
		void Display();
};

