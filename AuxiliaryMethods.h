#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>

using namespace std;

class AuxiliaryMethods
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

    static string readFloat();
    static string readLine();
    static char readChar();
    static int readIntiger();
    static int stringToIntConversion(string number);
    static string intToStringConversion(int number);

};

#endif
