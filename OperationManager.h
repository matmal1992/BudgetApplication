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
    template <typename T> void sortByDate(vector <T> &operations);
    template <typename T> void displayOperations(vector <T> &operations);
    template <typename T> vector <T> getOperationsFromSpecifiedPeriod(vector <T> &operations, string periodOfTime);
    template <typename T> T executeOperation(T incomeOrExpense);

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
