/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.h
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
#ifndef SDDS_TRIAGE_H
#define SDDS_TIRAGE_H
#include <iostream>
#include "Patient.h"
namespace sdds {
	class TriagePatient :public Patient {
		char* m_symptom;

	public:
		TriagePatient();
		char type()const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);

		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);

		~TriagePatient();


	};

}
#endif // !SDDS_


