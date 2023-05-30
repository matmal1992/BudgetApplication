#ifndef _FILEWITHINCOMES_H_
#define _FILEWITHINCOMES_H_

#include "Operation.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

#include <iostream>
#include <vector>
#include <fstream>

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

    vector <Operation> loadIncomesFromFile();
    void saveIncomeToFile(Operation income);
    void setLastIncomeId(vector <Operation> incomes);
    int getLastIncomeId();
};

#endif
