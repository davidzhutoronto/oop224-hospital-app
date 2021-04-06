/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
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
#include "PreTriage.h"
#include "utils.h"
#include <fstream>
#include <iostream>
//#include "IOAble.h"
//#include "Patient.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include <cstring>
using namespace std;

namespace sdds {
	void PreTriage::reg() {
		if (m_lineupSize >= maxNoOfPatients) {
			cout << "Line up full!" << endl;
		}
		else {
			int selection = -1;
			m_pMenu >> selection;
			switch (selection) {
			case 1:
				m_lineup[m_lineupSize] = new CovidPatient();
				break;
			case 2:
				m_lineup[m_lineupSize] = new TriagePatient();
				break;
			}
			if (selection == 1 || selection == 2) {
				m_lineup[m_lineupSize]->setArrivalTime();
				cout << "Please enter patient information: " << endl;
				m_lineup[m_lineupSize]->fileIO(false);
				cin >> *m_lineup[m_lineupSize];
				cout << endl;
				cout << "******************************************" << endl;
				cout << *m_lineup[m_lineupSize];
				cout << "Estimated Wait Time: ";
				m_lineupSize++;
				cout << getWaitTime(*m_lineup[m_lineupSize - 1]);
				cout << endl;
				cout << "******************************************";
				cout << endl << endl;
			}
		}
	}

	void PreTriage::admit() {
		if (m_lineupSize == 0) {
			cout << "No Patient!" << endl;
		}

		else if (m_lineupSize > 0) {
			int selection = -1;
			int index = -1;
			m_pMenu >> selection;
			switch (selection) {
			case 1:
				index = indexOfFirstInLine('C');
				if (index != -1) {
					cout << endl;
					cout << "******************************************";
					cout << endl;
					m_lineup[index]->fileIO(false);
					cout << "Calling for ";
					cout << *m_lineup[index];
					cout << "******************************************" << endl << endl;
					setAverageWaitTime(*m_lineup[index]);
					removePatientFromLineup(index);
				}
				break;

			case 2:
				index = indexOfFirstInLine('T');
				if (index != -1) {
					cout << endl;
					cout << "******************************************";
					cout << endl;
					m_lineup[index]->fileIO(false);
					cout << "Calling for ";
					cout << *m_lineup[index];
					cout << "******************************************" << endl << endl;
					setAverageWaitTime(*m_lineup[index]);
					removePatientFromLineup(index);
				}
				break;
			}
		}
	}

	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		int numC = 0;
		int numT = 0;
		int time = 0;
		for(int i = 0; i < m_lineupSize; i++) {
			if (m_lineup[i]->type() == 'C') {
				time = m_averCovidWait * numC;
				numC++;
			}
			else if (m_lineup[i]->type() == 'T') {
				time = m_averTriageWait * numT;
				numT++;
			}
		}
		return time;
	}

	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		Time CT;
		CT.reset();
		if (p.type() == 'C') {
			m_averCovidWait = ((CT - Time(p)) + m_averCovidWait * (p.number() - 1)) / p.number();
		}
		else if(p.type() == 'T'){
			m_averTriageWait = ((CT - Time(p)) + m_averTriageWait * (p.number() - 1)) / p.number();
		}
	}

	void PreTriage::removePatientFromLineup(int index) {
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}
	
	int PreTriage::indexOfFirstInLine(char type) const {
		int index = 0;
		bool flag = true;
		for (int i = 0; (i < m_lineupSize) & flag; i++) {
			if (m_lineup[i]->type() == type) {
				index = i;
				flag = false;
			}
			else {
				index = -1;
			}
		}
		return index;
	}

	void PreTriage::load(){
		cout << "Loading data..." << endl;
		ifstream csvfile(m_dataFilename);
		//Patient* W;
		if (csvfile) {
			csvfile >> m_averCovidWait;
			csvfile.ignore(2000, ',');
			csvfile >> m_averTriageWait;
			csvfile.ignore(2000, '\n');
		}
		while (csvfile && m_lineupSize < maxNoOfPatients) {
			char x = 'x';
			csvfile >> x;
			csvfile.ignore(2000, ',');
			if (x == 'C') {
				Patient* W;
				W = new CovidPatient();
				W->fileIO(true);
				csvfile >> *W;
				W->fileIO(false);
				m_lineup[m_lineupSize] = W;
				m_lineupSize++;
			}
			else if (x == 'T') {
				Patient* W;
				W = new TriagePatient();
				W->fileIO(true);
				csvfile >> *W;
				W->fileIO(false);
				m_lineup[m_lineupSize] = W;
				m_lineupSize++;
			}
		}
		if (csvfile) {
			cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
		}
		if (m_lineupSize <= 0) {
			cout << "No data or bad data file!" << endl << endl;
		}
		else {
			cout << m_lineupSize << " Records imported..." << endl << endl;
		}
	}

	PreTriage::PreTriage(const char* dataFilename) :m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{
		delete[] m_dataFilename;
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		m_averCovidWait = 15;
		m_averTriageWait = 5;
		load();
	}

	PreTriage::~PreTriage()
	{
		ofstream csvoutfile(m_dataFilename);
		csvoutfile << m_averCovidWait;
		csvoutfile << ',';
		csvoutfile << m_averTriageWait << endl;

		cout << "Saving Average Wait Times," << endl;
		cout << "   COVID Test: " << m_averCovidWait << endl;
		cout << "   Triage: " << m_averTriageWait << endl;
		cout << "Saving m_lineup..." << endl;

		for (int i = 0; i < m_lineupSize; i++) {
			m_lineup[i]->fileIO(true);
			csvoutfile << *m_lineup[i] << endl;
			cout << i + 1 << "- ";
			cout << *m_lineup[i] << endl;
		}

		for (int i = 0; i < m_lineupSize; i++) {
			delete m_lineup[i];
		}
		delete[] m_dataFilename;
		std::cout << "done!" << endl;
	}

	void PreTriage::run(void) {
		int selection;
		while (m_appMenu >> selection) {
			switch (selection) {
			case 1:
				reg();
				break;
			case 2:
				admit();
				break;
			}
		}
	}
}