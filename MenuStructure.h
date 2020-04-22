// Klasa abstrakcyjna Structure pe�ni funkcj� interfejsu. Je�li dana klasa go implementuje, to mo�e by� wy�wietlona w menu.

#pragma once
#include <string>

class MenuStructure
{
	public:

		virtual void MenuDelete() = 0;

		virtual void MenuAdd() = 0;

		void MenuLoadFromFile();

		virtual void Display() = 0;

		virtual int LoadFromFile(std::string file_name) = 0;

		void MenuFind();

		virtual bool Contains(int value) = 0;

		void MenuGenerate();

		virtual void Generate(int count, int min, int max) = 0;
};

