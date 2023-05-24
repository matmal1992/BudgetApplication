#include "AuxiliaryMethods.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

string AuxiliaryMethods::intToStringConversion(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::stringToIntConversion(string number)
{
    int intigerNumber;
    istringstream iss(number);
    iss >> intigerNumber;

    return intigerNumber;
}

string AuxiliaryMethods::readLine()
{
    string input{};
    getline(cin, input);
    return input;
}

char AuxiliaryMethods::readChar()
{
    string input{};
    char character = {0};

    while (true)
    {
        input = readLine();

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "It's not a single character. Try again." << endl;
    }
    return character;
}

string AuxiliaryMethods::readNumber(string text, int charPosition)
{
    string number{};
    while(isdigit(text[charPosition]))
    {
        number += text[charPosition];
        charPosition ++;
    }
    return number;
}

string AuxiliaryMethods::makeFirstLetterCapital(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AuxiliaryMethods::readIntiger()
{
    string input{};
    int number = 0;

    while (true)
    {
        input = readLine();

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "It's not a number. Try again. " << endl;
    }
    return number;
}

string AuxiliaryMethods::readInsertedAmountOfMoney()
{
    string input{};
    input = readLine();

    for(size_t i = 0; i < input.size(); ++i)
    {
        if(input[i] == ',')
            input[i] = '.';

        if(!isdigit(input[i]) && input[i] != '.')
        {
            cout << "Invalid format. The correct format is: 1220.40" << endl;
            system("pause");
            return "";
        }
    }
    return input;
}

string AuxiliaryMethods::getActualDate()
{
    string actualDate{};
    string year{}, month{}, day{};

    time_t t = time(0);
    tm* now = localtime(&t);

    year = intToStringConversion(now -> tm_year + 1900);

    if((now -> tm_mon + 1) / 10 < 1)
        month = "0" + intToStringConversion(now -> tm_mon + 1);
    else
        month = intToStringConversion(now -> tm_mon + 1);

    if((now -> tm_mday) / 10 < 1)
        day = "0" + intToStringConversion(now -> tm_mday);
    else
        day = intToStringConversion(now -> tm_mday);

    actualDate = year + "-" + month + "-" + day;
    return actualDate;
}

string AuxiliaryMethods::getSpecifiedDate()
{
    int insertedYear{}, insertedMonth{}, insertedDay{};
    string insertedDate{};

    int actualYear = stringToIntConversion(getActualDate().substr(0, 4));

    cout << "Enter the year in the range from 2000 to actual: ";
    insertedYear = readIntiger();
    if(insertedYear < 2000 || insertedYear > actualYear)
        return "";

    cout << "Enter the month: ";
    insertedMonth = readIntiger();
    if(insertedMonth < 1 || insertedMonth > 12)
        return "";

    cout << "Enter the day: ";
    insertedDay = readIntiger();
    if(insertedDay < 1 || insertedDay > daysInGivenMonth(insertedMonth, insertedYear))
        return "";

    insertedDate = intToStringConversion(insertedYear) + '-' + addZeroIfNecessary(insertedMonth, insertedDay);
    return insertedDate;
}

string AuxiliaryMethods::addZeroIfNecessary(int insertedMonth, int insertedDay)
{
    string month{}, day{};

    if(insertedMonth < 10)
        month = '0' + intToStringConversion(insertedMonth);

    if(insertedDay < 10)
        day = '0' + intToStringConversion(insertedDay);

    return (month + '-' + day);
}

bool AuxiliaryMethods::isLeapYear(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

int AuxiliaryMethods::daysInGivenMonth(int numberOfMonth, int year)
{
    switch(numberOfMonth)
    {
    case 1: return 31; break;
    case 2:
        if(isLeapYear(year)) return 29;
        else return 28;
        break;
    case 3: return 31; break;
    case 4: return 30; break;
    case 5: return 31; break;
    case 6: return 30; break;
    case 7: return 31; break;
    case 8: return 31; break;
    case 9: return 30; break;
    case 10: return 31; break;
    case 11: return 30; break;
    case 12: return 31; break;
    default: cout << "Invalid data!" << endl;
    }
    return 0;
}



