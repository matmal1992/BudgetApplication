#ifndef _FILEWITHEXPENSES_H_
#define _FILEWITHEXPENSES_H_

#include "Operation.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class FileWithExpenses
{
    const string FILE_NAME = "Expenses.xml";
    int lastExpenseId;

public:
    FileWithExpenses()
    {
        lastExpenseId = 0;
    }

    vector <Operation> loadExpensesFromFile();
    void saveExpenseToFile(Operation expense);
    void setLastExpenseId(vector <Operation> expense);
    int getLastExpenseId();
};

#endif
