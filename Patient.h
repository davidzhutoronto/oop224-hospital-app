/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.h
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
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
namespace sdds {
	class Patient :public IOAble {
		char* m_name = nullptr;
		int m_ohip = 0;
		Ticket m_ticket;
		//Ticket m_ticket = 0;
		bool m_ioFlag = false;

	public:
		Patient(int number = 0, bool ioFlag = false);

		//copying and assignment is not allowed:
		Patient(const Patient&) = delete;
		Patient& operator=(const Patient&) = delete;

		~Patient();

		//Member functions
		//Pure Virtual Function type()
		virtual char type()const = 0;
		bool fileIO()const;
		void fileIO(bool ioFlag);

		bool operator==(char c)const;
		bool operator==(const Patient& p)const;

		void setArrivalTime();

		operator Time()const;

		int number()const;

		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);

		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);

	};
}
#endif // !SDDS_PATIENT_H_


