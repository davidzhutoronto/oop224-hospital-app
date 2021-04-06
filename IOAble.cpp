/* Citation and Sources...
Final Project Milestone 5
Module: IOAble
Filename: IOAble.cpp
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
#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& os, const IOAble& IOAble)
	{
		IOAble.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, IOAble& IOAble)
	{
		IOAble.read(is);
		return is;
	}

}