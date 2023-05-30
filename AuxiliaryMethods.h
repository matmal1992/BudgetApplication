#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class AuxiliaryMethods
{
public:
    static string readFloat();
    static string readLine();
    static char readChar();
    static int readIntiger();
    static int stringToIntConversion(string number);
    static string intToStringConversion(int number);
};

#endif
