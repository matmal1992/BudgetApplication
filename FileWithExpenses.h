#ifndef _FILEWITHEXPENSES_H_
#define _FILEWITHEXPENSES_H_

#include "Expense.h"
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

    vector <Expense> loadExpensesFromFile();
    void saveExpenseToFile(Expense expense);
    void setLastExpenseId(vector <Expense> expense);
    int getLastExpenseId();
};

#endif
