#ifndef _OPERATIONMANAGER_H_
#define _OPERATIONMANAGER_H_

#include "Operation.h"
#include "FileWithOperations.h"
#include "DateMethods.h"

#include <vector>
#include <algorithm>

using namespace std;

class OperationManager
{
    vector <Operation> incomes;
    vector <Operation> expenses;
    FileWithOperations fileWithOperations;
    const int LOGGED_USER_ID;

    vector <Operation> displayIncomes(string periodOfTime);
    vector <Operation> displayExpenses(string periodOfTime);
    void incomesMinusExpenses(const vector <Operation> &incomes, const vector <Operation> &expenses);
    void sortByDate(vector <Operation> &operations);
    void displayOperations(const vector <Operation> &operations);
    vector <Operation> getOperationsFromSpecifiedPeriod(const vector <Operation> &operations, string periodOfTime);
    Operation executeOperation(string&& typeOfOperation);

public:
    OperationManager(int loggedUserId): LOGGED_USER_ID(loggedUserId)
    {
        incomes = fileWithOperations.loadOperationsFromFile("Income");
        expenses = fileWithOperations.loadOperationsFromFile("Expense");
    }

    void addIncome();
    void addExpense();
    void displayBalance(string periodOfTime);
};

#endif
