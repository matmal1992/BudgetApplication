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
public:
    static string getActualDate();
    static string getActualMonthTimespan();
    static string getPreviousMonthTimespan();
    static string getSpecifiedDate();

    static string readInsertedAmountOfMoney();
    static string readLine();
    static char readChar();
    static int readIntiger();
    static string readNumber(string text, int charPosition);

    static string makeFirstLetterCapital(string text);
    static int stringToIntConversion(string number);
    static string intToStringConversion(int number);
    static int convertStringDateIntoInt(string date);
};

#endif
