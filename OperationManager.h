#ifndef _OPERATIONMANAGER_H_
#define _OPERATIONMANAGER_H_

#include "Operation.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "DateOperations.h"

#include <vector>
#include <algorithm>

using namespace std;

class OperationManager
{
    vector <Operation> incomes;
    vector <Operation> expenses;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    const int LOGGED_USER_ID;

    vector <Operation> displayIncomes(string periodOfTime);
    vector <Operation> displayExpenses(string periodOfTime);
    void incomesMinusExpenses(vector <Operation> incomes, vector <Operation> expenses);
    void sortByDate(vector <Operation> &operations);
    void displayOperations(vector <Operation> &operations);
    vector <Operation> getOperationsFromSpecifiedPeriod(vector <Operation> &operations, string periodOfTime);
    Operation executeOperation();

public:
    OperationManager(int loggedUserId): LOGGED_USER_ID(loggedUserId)
    {
        incomes = fileWithIncomes.loadIncomesFromFile();
        expenses = fileWithExpenses.loadExpensesFromFile();
    }

    void addIncome();
    void addExpense();
    void displayBalance(string periodOfTime);
};

#endif
