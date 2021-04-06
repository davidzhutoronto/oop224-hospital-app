/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.cpp
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
#include "TriagePatient.h"
#include<cstring>
using namespace std;
namespace sdds {
	int nextTriageTicket = 1;


	TriagePatient::TriagePatient() :Patient(nextTriageTicket)
	{
		// delete[] m_symptom;
		m_symptom = nullptr;
		nextTriageTicket++;
	}

	char TriagePatient::type() const
	{
		return 'T';
	}

	std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
	{
		Patient::csvWrite(ostr);
		ostr << ',';
		ostr << m_symptom;
		return ostr;
	}

	std::istream& TriagePatient::csvRead(std::istream& istr)
	{
		char temp[512];
		temp[0] = '\0';

		Patient::csvRead(istr);
		istr.ignore(1000, ',');
		istr.get(temp, 511, '\n');
		delete[] m_symptom;
		//m_symptom = nullptr;
		m_symptom = new char[strlen(temp) + 1];
		strcpy(m_symptom, temp);
		nextTriageTicket = Patient::number() + 1;

		return istr;
	}

	std::ostream& TriagePatient::write(std::ostream& ostr) const
	{
		if (fileIO()) {
			csvWrite(ostr);
		}
		else {
			ostr << "TRIAGE" << endl;
			Patient::write(ostr);
			ostr << endl;
			ostr << "Symptoms: ";
			ostr << m_symptom << endl;
		}
		return ostr;
	}

	std::istream& TriagePatient::read(std::istream& istr)
	{
		char temp[512];
		temp[0] = '\0';

		if (fileIO()) {
			csvRead(istr);
		}
		else {
			delete[] m_symptom;
			//m_symptom = nullptr;
			Patient::read(istr);
			std::cout << "Symptoms: ";
			istr.get(temp, 511, '\n');
			istr.ignore(2000, '\n');
			m_symptom = new char[strlen(temp) + 1];
			strcpy(m_symptom, temp);
		}
		return istr;
	}

	TriagePatient::~TriagePatient()
	{
		delete[] m_symptom;
		m_symptom = nullptr;
	}

}