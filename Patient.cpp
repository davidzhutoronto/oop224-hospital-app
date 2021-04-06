/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.cpp
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
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Patient::Patient(int number, bool ioFlag) :m_ticket(number)
	{
		//m_ticket = number;
		m_ioFlag = ioFlag;
	}

	Patient::~Patient()
	{
		delete[] m_name;
		m_name = nullptr;
	}
	bool Patient::fileIO() const
	{
		return m_ioFlag;
	}

	void Patient::fileIO(bool ioFlag)
	{
		m_ioFlag = ioFlag;
	}

	bool Patient::operator==(char c) const
	{
		return type() == c;
	}

	bool Patient::operator==(const Patient& p) const
	{
		return operator==(p.type());
	}

	void Patient::setArrivalTime()
	{
		m_ticket.resetTime();
	}

	Patient::operator Time() const
	{
		return Time(m_ticket);
	}

	int Patient::number()const
	{
		return m_ticket.number();
	}

	std::ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << type();
		ostr << ',';
		ostr << m_name;
		ostr << ',';
		ostr << m_ohip;
		ostr << ',';

		m_ticket.csvWrite(ostr);

		return ostr;
	}

	std::istream& Patient::csvRead(std::istream& istr)
	{
		char name[51];

		istr.get(name, 51, ',');

		if (strlen(name) > 0) {
			delete[] m_name;
			m_name = nullptr;
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			istr.ignore(2000, ',');
			istr >> m_ohip;
			istr.ignore(2000, ',');
			m_ticket.csvRead(istr);
		}
		return istr;
	}

	std::ostream& Patient::write(std::ostream& ostr) const
	{
		ostr << m_ticket;
		ostr << endl;
		ostr << m_name;
		ostr << ", OHIP: ";
		ostr << m_ohip;

		return ostr;
	}

	std::istream& Patient::read(std::istream& istr)
	{
		char name[51];
		delete[] m_name;
		m_name = nullptr;

		std::cout << "Name: ";
		istr.get(name, 51, '\n');

		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
		istr.ignore(2000, '\n');
		std::cout << "OHIP: ";
		m_ohip = getInt();
		while (m_ohip < 100000000 || m_ohip > 999999999) {
			std::cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
			m_ohip = getInt();
		}
		return istr;
	}

}