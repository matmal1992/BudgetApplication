#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static string intToStringConversion(int number);
    static string readLine();
    static string makeFirstLetterCapital(string text);
    static int stringToIntConversion(string number);
    static char readChar();
    static int getUserIdFromDataSeparatedByDashes(string addresseeDataSeparatedByDashes);
    static int getAddresseeIdFromDataSeparatedByDashes(string addresseeDataSeparatedByDashes);
    static string readNumber(string text, int charPosition);
    static int readIntiger();
    static int insertIdOfSelectedAddressee();
    static void displayAmountOfFoundAddressees(int amountOfAddressees);
};

#endif
