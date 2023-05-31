#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include "AuxiliaryMethods.h"

#include <iostream>
#include <ctime>

using namespace std;

class DateMethods : public AuxiliaryMethods
{
    static string addZeroIfNecessary(int insertedMonthOrDay);
    static bool isLeapYear(int year);
    static int daysInGivenMonth(int numberOfMonth, int year);
    static int insertYear();
    static int insertMonth(int insertedYear);
    static int insertDay(int insertedMonth, int insertedYear);

public:
    static string getActualDate();
    static string getActualMonthTimespan();
    static string getPreviousMonthTimespan();
    static string getSelectedMonthTimespan();
    static string getSelectedTimePeriod();
    static string specifyExactDate();
};

#endif
