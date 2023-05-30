#include "AuxiliaryMethods.h"

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

string AuxiliaryMethods::readFloat()
{
    string input{};
    int amountOfDots{};

    do
    {
        input = readLine();

        if(!isdigit(input[0]))
        {
            cout << "Invalid format. The correct format is: 1220.40. Try again: " << endl;
            input = "";
        }

        for(size_t i = 0; i < input.size(); ++i)
        {
            if(input[i] == ',')
                input[i] = '.';

            if(input[i] == '.')
                amountOfDots++;

            if(amountOfDots > 1)
            {
                cout << "Invalid format. The correct format is: 1220.40. Try again: " << endl;
                input = "";
                amountOfDots = 0;
                break;
            }

            if(!isdigit(input[i]) && input[i] != '.')
            {
                cout << "Invalid format. The correct format is: 1220.40. Try again: " << endl;
                input = "";
                break;
            }
        }
    }while(input == "");

    return input;
}

