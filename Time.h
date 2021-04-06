/* Citation and Sources...
Final Project Milestone 5
Module: Time
Filename: Time.h
Version 1.0
Author    David Zhu
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/30  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>
namespace sdds {
    class Time {
        unsigned int m_min;
    public:
        Time& reset();
        Time(unsigned int min = 0);
        std::ostream& write(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);
        operator int()const;
        Time& operator *= (int val);
        Time& operator-=(const Time& D);
        
        //MS5 added:
        Time operator-(const Time& ROperand);

    };
    // helper operator << and >> prototypes
    std::ostream& operator<<(std::ostream& os, const Time& t);
    std::istream& operator>>(std::istream& is, Time& t);
}

#endif // !SDDS_TIME_H

