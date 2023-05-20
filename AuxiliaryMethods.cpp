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

int AuxiliaryMethods::getAddresseeIdFromDataSeparatedByDashes(string addresseeDataSeparatedByDashes)
{
    int positionOfBeginingAddresseeId = 0;
    int addresseeId = stringToIntConversion(readNumber(addresseeDataSeparatedByDashes, positionOfBeginingAddresseeId));
    return addresseeId;
}

int AuxiliaryMethods::getUserIdFromDataSeparatedByDashes(string addresseeDataSeparatedByDashes)
{
    int positionOfBeginingUserId = addresseeDataSeparatedByDashes.find_first_of('|') + 1;
    int userId = stringToIntConversion(readNumber(addresseeDataSeparatedByDashes, positionOfBeginingUserId));

    return userId;
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
int AuxiliaryMethods::insertIdOfSelectedAddressee()
{
    int idOfSelectedAddressee = 0;
    cout << "Insert addressee ID: ";
    idOfSelectedAddressee  = readIntiger();
    return idOfSelectedAddressee;
}

void AuxiliaryMethods::displayAmountOfFoundAddressees(int numberOfAddressees)
{
    if (numberOfAddressees == 0)
        cout << endl << "There are no addressees in your book with such data." << endl;
    else
        cout << endl << "Amount of addressees in the book: " << numberOfAddressees << endl << endl;
}




