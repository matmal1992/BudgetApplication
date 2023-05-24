#ifndef _FILEWITHINCOMES_H_
#define _FILEWITHINCOMES_H_

#include "Income.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class FileWithIncomes
{
    const string FILE_NAME = "Incomes.xml";
    int lastIncomeId;
public:
    FileWithIncomes()
    {
        lastIncomeId = 0;
    }

    vector <Income> loadIncomesFromFile();
    void saveIncomeToFile(Income income);
    void setLastIncomeId(vector <Income> incomes);
    int getLastIncomeId();
};

#endif
