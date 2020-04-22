#include<conio.h>
#include<string>
#include<iostream>
#include <ctime>
#include "Array.h"
#include "List.h"
#include "Heap.h"

using namespace std;

void displayMenu(string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1. Wczytaj z pliku" << endl;
	cout << "2. Usun" << endl;
	cout << "3. Dodaj" << endl;
	cout << "4. Znajdz" << endl;
	cout << "5. Utworz losowo" << endl;
	cout << "6. Wyswietl" << endl;
	cout << "7. Test (pomiary)" << endl;
	cout << "0. Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

template <class _structure>
void menu(_structure structure, string info)
{
	char opt;
	string fileName;
	int index, value;

	do {
		displayMenu(info);
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': // wczytytwanie z pliku
			cout << " Podaj nazwe zbioru:";
			cin >> fileName;
			structure.LoadFromFile(fileName);
			structure.Display();
			break;

		case '2': // usuwanie elementu
			if (typeid(_structure) == typeid(Array))
			{
				cout << " podaj index:";
				cin >> index;
				structure.Delete(index);
			}
			else if (typeid(_structure) == typeid(List) || typeid(_structure) == typeid(Heap))
			{
				cout << " podaj wartosc:";
				cin >> value;
				structure.Delete(value);
			}
			
			structure.Display();
			break;

		case '3': // dodawanie elemetu
			if (typeid(_structure) == typeid(Array) || typeid(_structure) == typeid(List) || typeid(_structure) == typeid(Heap))
			{
				cout << " podaj index:";
				cin >> index;
				cout << " podaj wartosc:";
				cin >> value;

				structure.Add(index, value);
			}
			
			structure.Display();
			break;

		case '4': // znajdowanie elemetu
			cout << " podaj wartosc:";
			cin >> value;
			if (structure.Contains(value))
				cout << "Podana wartosc jest w strukturze.";
			else
				cout << "Podanej wartości NIE ma w strukturze.";

			cout << endl;
			break;

		case '5':  // generowanie  tablicy
			cout << "Podaj ilosc elementow struktury: ";
			cin >> value;
			structure.Generate(value, 0, 5000);
			structure.Display();
			break;
		case '6': 
			structure.Display();

		case '7': // nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego 
				  // można sobie tu dodać własne case'y
			break;
		}

	} while (opt != '0');
}


int main(int argc, char* argv[])
{
	srand(time(NULL));

	Array array;
	List list;
	Heap heap;

	char option;
	do {
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
		cout << "0.Wyjscie" << endl << endl;
		cout << "Podaj opcje:";
		option = _getche();
		cout << endl;

		switch (option) {
		case '1':
			menu(array, "--- TABLICA ---");
			break;

		case '2':
			menu(list, "--- LISTA ---");
			break;

		case '3':
			menu(heap, "--- KOPIEC ---");
			break;
		}

	} while (option != '0');


	return 0;
}