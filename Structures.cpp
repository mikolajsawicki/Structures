#include<conio.h>
#include<string>
#include<iostream>
#include <ctime>
#include "MenuStructure.h"
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


void menu(MenuStructure* structure, string info)
{
	char opt;
	string fileName;
	int index, value;

	do {
		displayMenu(info);
		opt = _getche();
		cout << endl;
		(*structure).Display();
		cout << endl;
		switch (opt) {
		case '1':
			(*structure).MenuLoadFromFile();
			break;
		case '2':
			(*structure).MenuDelete();
			break;

		case '3':
			(*structure).MenuAdd();
			break;

		case '4':
			(*structure).MenuFind();
			break;

		case '5':
			(*structure).MenuGenerate();
			break;

		case '6': 
			(*structure).Display();
			break;

		case '7': // nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego 
				  // można sobie tu dodać własne case'y
			break;
		}

	} while (opt != '0');
}


int main(int argc, char* argv[])
{
	srand(time(NULL));

	MenuStructure* array = new Array;
	MenuStructure* list = new List;
	MenuStructure* heap = new Heap;

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