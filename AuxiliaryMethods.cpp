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

string AuxiliaryMethods::getSelectedMonthTimespan()
{
    int insertedYear{}, insertedMonth{}, dayInt{};
    string firstDay{}, lastDay{}, periodOfTime{};

    int actualYear = stringToIntConversion(getActualDate().substr(0, 4));
    int actualMonth = stringToIntConversion(getActualDate().substr(5, 2));

    cout << "Enter the year in the range from 2000 to actual: ";
    insertedYear = readIntiger();

    while(insertedYear < 2000 || insertedYear > actualYear)
    {
        cout << "You inserted invalid data! Try again: ";
        insertedYear = readIntiger();
    }

    cout << "Enter the month: ";
    insertedMonth = readIntiger();

    while( (insertedMonth < 1 || insertedMonth > 12) || (insertedYear == actualYear && insertedMonth > actualMonth))
    {
        cout << "You inserted invalid data! Try again: ";
        insertedMonth = readIntiger();
    }

    dayInt = daysInGivenMonth(insertedMonth, insertedYear);

    firstDay = intToStringConversion(insertedYear) + "-" + addZeroIfNecessary(insertedMonth) + "-" + "01";
    lastDay = firstDay.substr(0, 8) + intToStringConversion(dayInt);

    periodOfTime = firstDay + "_" + lastDay;

    return periodOfTime;
}

string AuxiliaryMethods::getPreviousMonthTimespan()
{
    string firstDay{}, lastDay{}, periodOfTime{};
    string actualYear = getActualDate().substr(0, 4);
    string actualMonth = getActualDate().substr(5, 2);

    int yearInt{}, monthInt{}, dayInt{};

    if(actualMonth == "01")
    {
        yearInt = stringToIntConversion(actualYear) - 1;
        monthInt = 12;
    }
    else
    {
        yearInt = stringToIntConversion(actualYear);
        monthInt = stringToIntConversion(actualMonth) - 1;
    }

    dayInt = daysInGivenMonth(monthInt, yearInt);

    firstDay = intToStringConversion(yearInt) + "-" + addZeroIfNecessary(monthInt) + "-" + "01";
    lastDay = firstDay.substr(0, 8) + intToStringConversion(dayInt);

    periodOfTime = firstDay + "_" + lastDay;

    return periodOfTime;
}

string AuxiliaryMethods::getActualMonthTimespan()
{
    string firstDay{}, lastDay{}, periodOfTime{};
    string actualYear = getActualDate().substr(0, 4);
    string actualMonth = getActualDate().substr(5, 2);

    int yearInt = stringToIntConversion(actualYear);
    int monthInt = stringToIntConversion(actualMonth);
    int dayInt = daysInGivenMonth(monthInt, yearInt);

    firstDay = actualYear + "-" + actualMonth + "-" + "01";
    lastDay = firstDay.substr(0, 8) + intToStringConversion(dayInt);

    periodOfTime = firstDay + "_" + lastDay;

    return periodOfTime;
}

string AuxiliaryMethods::getSpecifiedDate()
{
    int insertedYear{}, insertedMonth{}, insertedDay{};
    string insertedDate{};

    int actualYear = stringToIntConversion(getActualDate().substr(0, 4));
    int actualMonth = stringToIntConversion(getActualDate().substr(5, 2));

    cout << "Enter the year in the range from 2000 to actual: ";
    insertedYear = readIntiger();

    while(insertedYear < 2000 || insertedYear > actualYear)
    {
        cout << "You inserted invalid data! Try again: ";
        insertedYear = readIntiger();
    }

    cout << "Enter the month: ";
    insertedMonth = readIntiger();

    while( (insertedMonth < 1 || insertedMonth > 12) || (insertedYear == actualYear && insertedMonth > actualMonth))
    {
        cout << "You inserted invalid data! Try again: ";
        insertedMonth = readIntiger();
    }

    cout << "Enter the day: ";
    insertedDay = readIntiger();
    while(insertedDay < 1 || insertedDay > daysInGivenMonth(insertedMonth, insertedYear))  //try function templates
    {
        cout << "You inserted invalid data! Try again: ";
        insertedMonth = readIntiger();
    }

    insertedDate = intToStringConversion(insertedYear) + '-'
                 + addZeroIfNecessary(insertedMonth) + '-'
                 + addZeroIfNecessary(insertedDay);

    return insertedDate;
}

string AuxiliaryMethods::addZeroIfNecessary(int insertedDayOrMonth)
{
    string dayOrMonth{};

    if(insertedDayOrMonth < 10)
        dayOrMonth = '0' + intToStringConversion(insertedDayOrMonth);

    return dayOrMonth;
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

int AuxiliaryMethods::convertStringDateIntoInt(string date)
{
    int intDate{};
    string dateWithoutDashes{};

    dateWithoutDashes = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);
    intDate = stringToIntConversion(dateWithoutDashes);

    return intDate;
}


