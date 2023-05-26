#ifndef _OPERATIONMANAGER_H_
#define _OPERATIONMANAGER_H_

#include "Income.h"
#include "Expense.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"

#include <vector>
#include <algorithm>

using namespace std;

class OperationManager
{
    vector <Income> incomes;
    vector <Expense> expenses;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    const int LOGGED_USER_ID;

    vector <Income> displayIncomes(string periodOfTime);
    vector <Expense> displayExpenses(string periodOfTime);
    void incomesMinusExpenses(vector <Income> incomes, vector <Expense> expenses);
    template <typename T> void sortByDate(vector <T> &operations);
    template <typename T> void displayOperations(vector <T> &operations);
    template <typename T> vector <T> getOperationsFromSpecifiedPeriod(vector <T> &operations, string periodOfTime);

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
