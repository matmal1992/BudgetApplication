#include "OperationManager.h"

void OperationManager::addIncome()
{
    Income income;

    cout << "To add a current income - press 1." << endl;
    cout << "To add an income with specified date - press 2." << endl << endl;

    income = executeOperation(income);

    fileWithIncomes.saveIncomeToFile(income);
}

void OperationManager::addExpense()
{
    Expense expense;

    cout << "To add a current expense - press 1." << endl;
    cout << "To add an expense with specified date - press 2." << endl << endl;

    expense = executeOperation(expense);

    fileWithExpenses.saveExpenseToFile(expense);
}

template <typename T> T OperationManager::executeOperation(T incomeOrExpense)
{
    T operation;
    char choice{};

    choice = AuxiliaryMethods::readChar();

    while(choice != '1' && choice != '2')
    {
        cout << "There is no such option! Try again: " << endl;
        choice = AuxiliaryMethods::readChar();
    }

    if(choice == '1')
        operation.setDate(DateOperations::getActualDate());

    if(choice == '2')
        operation.setDate(DateOperations::specifyExactDate());

    cout << "Specify type (RTV, media, salary, etc.): ";
    operation.setItem(AuxiliaryMethods::readLine());
    cout << "Insert amount in PLN: ";
    operation.setAmount(AuxiliaryMethods::readFloat());
    cout << "Money has been added" << endl;
    operation.setOperationId(fileWithExpenses.getLastExpenseId());
    operation.setUserId(LOGGED_USER_ID);

    return operation;
}

void OperationManager::displayBalance(string periodOfTime)
{
    vector <Income> userIncomes;
    vector <Expense> userExpenses;

    userIncomes = displayIncomes(periodOfTime);
    userExpenses = displayExpenses(periodOfTime);

    incomesMinusExpenses(userIncomes, userExpenses);
    system("pause");
}

template <typename T> vector <T> OperationManager::getOperationsFromSpecifiedPeriod(vector <T> &operations, string periodOfTime)
{
    vector <T> tmpOperations;
    string firstDay{}, lastDay{};

    //periodOfTime has a following format: YYYY-MM-DD_YYYY-MM-DD

    firstDay = periodOfTime.substr(0, 10);
    lastDay = periodOfTime.substr(11, 10);

    for(auto it = operations.begin(); it < operations.end(); ++it)
    {
        if(it -> getUserId() == LOGGED_USER_ID)
        {
            if( (it -> getDate() >= firstDay) && (it -> getDate() <= lastDay) )
                tmpOperations.push_back(*it);
        }
    }

    return tmpOperations;
}

vector <Income> OperationManager::displayIncomes(string periodOfTime)
{
    vector <Income> tmpIncomes;

    tmpIncomes = getOperationsFromSpecifiedPeriod(incomes, periodOfTime);
    sortByDate(tmpIncomes);

    cout << "INCOMES" << endl;
    cout << "==============================" << endl;
    displayOperations(tmpIncomes);

    return tmpIncomes;
}

vector <Expense> OperationManager::displayExpenses(string periodOfTime)
{
    vector <Expense> tmpExpenses;

    tmpExpenses = getOperationsFromSpecifiedPeriod(expenses, periodOfTime);
    sortByDate(tmpExpenses);

    cout << "EXPENSES:" << endl;
    cout << "==============================" << endl;
    displayOperations(tmpExpenses);

    return tmpExpenses;
}

template <typename T> void OperationManager::sortByDate(vector<T> &operations)
{
    sort(operations.begin(), operations.end(), [](T &lhs, T &rhs)
    {
        return lhs.getDate() < rhs.getDate();
    });
}

template <typename T> void OperationManager::displayOperations(vector <T> &operations)
{
    cout << "DATE\t\tITEM\tAmount" << endl << endl;
    for(auto it = operations.begin(); it < operations.end(); ++it)
    {
        if(it -> getUserId() == LOGGED_USER_ID)
        {
            cout << it -> getDate() << "\t";
            cout << it -> getItem() << "\t";
            cout << it -> getAmount() << endl;;
        }
    }
    cout << endl;
}

void OperationManager::incomesMinusExpenses(vector <Income> incomes, vector <Expense> expenses)
{
    float incomesTotal{}, expensesTotal{}, balance{};

    for(auto it = incomes.begin(); it < incomes.end(); ++it)
        incomesTotal += stof(it -> getAmount());


    for(auto it = expenses.begin(); it < expenses.end(); ++it)
        expensesTotal += stof(it -> getAmount());

    balance = incomesTotal - expensesTotal;
    cout << "BALANCE: " << balance << " PLN" << endl;
}

