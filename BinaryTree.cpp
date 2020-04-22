#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
	size = 0;
	arr = (int*) malloc(sizeof(*arr));
}

BinaryTree::~BinaryTree()
{
	free(arr);
}

void BinaryTree::PrintBT(string sp, string sn, int v)
{
	string s;

	if (v < size)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		PrintBT(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << arr[v] << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		PrintBT(s + cp, cl, 2 * v + 1);
	}
}

void BinaryTree::Display()
{
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	PrintBT("", "", 0);
}