/* Citation and Sources...
Final Project Milestone 5
Module: CovidPatient
Filename: CovidPatient.cpp
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
#include "CovidPatient.h"
using namespace std;
namespace sdds {
	//global variable 
	int nextCovidTicket = 1;

	CovidPatient::CovidPatient() :Patient(nextCovidTicket)
	{
		nextCovidTicket++;
	}

	char CovidPatient::type() const
	{
		return 'C';
	}

	std::ostream& CovidPatient::csvWrite(std::ostream& ostr) const
	{
		Patient::csvWrite(ostr);
		return ostr;
	}

	std::istream& CovidPatient::csvRead(std::istream& istr)
	{
		Patient::csvRead(istr);
		nextCovidTicket = number() + 1;
		return istr;
	}

	std::ostream& CovidPatient::write(std::ostream& ostr) const
	{
		if (Patient::fileIO() == true) {
			csvWrite(ostr);
		}
		else {
			ostr << "COVID TEST" << endl;
			Patient::write(ostr);
			ostr << endl;
		}
		return ostr;
	}

	std::istream& CovidPatient::read(std::istream& istr)
	{
		if (fileIO() == true) {
			csvRead(istr);
		}
		else {
			Patient::read(istr);
		}
		return istr;
	}

}