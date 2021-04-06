/* Citation and Sources...
Final Project Milestone 5
Module: IOAble
Filename: IOAble.h
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
#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
namespace sdds {
	class IOAble {
	public:
		virtual std::ostream& csvWrite(std::ostream&)const = 0;
		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& write(std::ostream&)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual ~IOAble() {};
	};
	std::ostream& operator<<(std::ostream& os, const IOAble& IOAble);
	std::istream& operator>>(std::istream& is, IOAble& IOAble);
}
#endif // !SDDS_IOABLE_H_