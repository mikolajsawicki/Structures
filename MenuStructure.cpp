#include "MenuStructure.h"
#include <iostream>

using namespace std;

void MenuStructure::MenuLoadFromFile()
{
	string file_name;

	cout << " Podaj nazwe zbioru:";
	cin >> file_name;
	LoadFromFile(file_name);
	Display();
}

void MenuStructure::MenuFind()
{
	int value;
	cout << " podaj wartosc:";
	cin >> value;
	if (Contains(value))
		cout << "Podana wartosc jest w strukturze.";
	else
		cout << "Podanej wartoœci NIE ma w strukturze.";

	cout << endl;
}

void MenuStructure::MenuGenerate()
{
	int value;
	cout << "Podaj ilosc elementow struktury: ";
	cin >> value;
	Generate(value, 0, 5000);
	Display();
}