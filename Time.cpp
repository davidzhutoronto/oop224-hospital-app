/* Citation and Sources...
Final Project Milestone 5
Module: Time
Filename: Time.cpp
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
#include "Time.h"
#include "utils.h"
#include <iostream>
using namespace std;

namespace sdds {

	Time& Time::reset() {
		m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min) {
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const {
		int hr = 0, min = 0;
		hr = int(m_min / 60);
		min = int(m_min % 60);

		ostr.fill('0');
		ostr.width(2);
		ostr << hr;
		ostr << ':';
		ostr.fill('0');
		ostr.width(2);
		ostr << min;
		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int hr = 0, min = 0;
		char c = 'x';
		if (m_min >= 0) {
			istr >> hr;
			istr >> c;
			if (c != ':') {
				istr.setstate(ios::failbit);
			}
			istr >> min;
			m_min = 60 * hr + min;
		}
		return istr;
	}

	Time::operator int() const
	{
		return m_min;
	}

	Time& Time::operator*=(int val)
	{
		m_min *= val;
		return *this;
	}

	Time& Time::operator-=(const Time& D)
	{
		if (m_min >= D.m_min) {
			m_min -= D.m_min;
		}
		else {
			m_min += 1440;
			m_min -= D.m_min;
		}
		return *this;
	}

	Time Time::operator-(const Time& ROperand)
	{
		Time LOperand = *this;
		LOperand -= ROperand;
		return LOperand;
	}

	ostream& operator<<(ostream& os, const Time& t)
	{
		t.write(os);
		return os;
	}

	istream& operator>>(istream& is, Time& t) {
		t.read(is);
		return is;
	}
}