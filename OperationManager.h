#ifndef _OPERATIONMANAGER_H_
#define _OPERATIONMANAGER_H_

#include "Income.h"
#include "Expense.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"

#include <vector>

using namespace std;

class OperationManager
{
    vector <Income> incomes;
    vector <Expense> expenses;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    const int LOGGED_USER_ID;

    Income insertDataForNewIncome();
    Expense insertDataForNewExpense();

public:
    OperationManager(int loggedUserId): LOGGED_USER_ID(loggedUserId)
    {
        //incomes = fileWithIncomes.load...
        //expenses = fileWithExpenses.load...
    }

    void addIncome();
    void addExpense();
    void displayBalanceOfCurrentMonth();
    void displayBalanceOfPreviousMonth();
    void displayBalanceOfSelectedMonth();
    void displayBalanceOfSelectedPeriod();









};

#endif
