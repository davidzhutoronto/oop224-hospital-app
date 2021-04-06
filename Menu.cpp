/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
Version 1.0
Author    David Zhu
Revision History
-----------------------------------------------------------
Date      Reason
2020/12/3  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "utils.h"
#include "Menu.h"
#include <cstring>
using namespace std;
namespace sdds {

	Menu::Menu(const char* text, int NoOfSelections)
	{
		m_text = new char[strlen(text) + 1];
		strcpy(m_text, text);
		m_noOfSel = NoOfSelections;
	}

	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}

	std::ostream& Menu::display(std::ostream& ostr) const
	{
		ostr << m_text << endl;
		ostr << "0- Exit" << endl;
		ostr << "> ";
		return ostr;
	}

	int& Menu::operator>>(int& Selection)
	{
		int s = -1;
		display();
		s = getInt();
		while (s < 0 || s>2) {
			cout << "Invalid value enterd, retry[0 <= value <= 2]: ";
			s = getInt();
		}
		Selection = s;
		return Selection;
	}

}