#include "OperationManager.h"

void OperationManager::addIncome()
{
    Operation income;

    cout << "To add a current income - press 1." << endl;
    cout << "To add an income with specified date - press 2." << endl << endl;

    income = executeOperation("Income");

    fileWithOperations.saveOperationToFile(income);
    incomes.push_back(income);
}

void OperationManager::addExpense()
{
    Operation expense;

    cout << "To add a current expense - press 1." << endl;
    cout << "To add an expense with specified date - press 2." << endl << endl;

    expense = executeOperation("Expense");

    fileWithOperations.saveOperationToFile(expense);
    expenses.push_back(expense);
}

Operation OperationManager::executeOperation(string&& typeOfOperation)
{
    Operation operation;
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
    operation.setTitle(AuxiliaryMethods::readLine());
    cout << "Insert amount in PLN: ";
    operation.setAmount(AuxiliaryMethods::readFloat());
    cout << "Money has been added" << endl;
    operation.setOperationId(fileWithOperations.getLastOperationId());
    operation.setUserId(LOGGED_USER_ID);
    operation.setType(typeOfOperation);

    return operation;
}

void OperationManager::displayBalance(string periodOfTime)
{
    vector <Operation> userIncomes;
    vector <Operation> userExpenses;

    userIncomes = displayIncomes(periodOfTime);
    userExpenses = displayExpenses(periodOfTime);

    incomesMinusExpenses(userIncomes, userExpenses);
    system("pause");
}

vector <Operation> OperationManager::getOperationsFromSpecifiedPeriod(vector <Operation> &operations, string periodOfTime)
{
    vector <Operation> tmpOperations;
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

vector <Operation> OperationManager::displayIncomes(string periodOfTime)
{
    vector <Operation> tmpIncomes;

    tmpIncomes = getOperationsFromSpecifiedPeriod(incomes, periodOfTime);
    sortByDate(tmpIncomes);

    cout << "INCOMES" << endl;
    cout << "==============================" << endl;
    displayOperations(tmpIncomes);

    return tmpIncomes;
}

vector <Operation> OperationManager::displayExpenses(string periodOfTime)
{
    vector <Operation> tmpExpenses;

    tmpExpenses = getOperationsFromSpecifiedPeriod(expenses, periodOfTime);
    sortByDate(tmpExpenses);

    cout << "EXPENSES:" << endl;
    cout << "==============================" << endl;
    displayOperations(tmpExpenses);

    return tmpExpenses;
}

void OperationManager::sortByDate(vector<Operation> &operations)
{
    sort(operations.begin(), operations.end(), [](Operation &lhs, Operation &rhs)
    {
        return lhs.getDate() < rhs.getDate();
    });
}

void OperationManager::displayOperations(vector <Operation> &operations)
{
    cout << "DATE\t\tITEM\tAmount" << endl << endl;
    for(auto it = operations.begin(); it < operations.end(); ++it)
    {
        if(it -> getUserId() == LOGGED_USER_ID)
        {
            cout << it -> getDate() << "\t";
            cout << it -> getTitle() << "\t";
            cout << it -> getAmount() << endl;;
        }
    }
    cout << endl;
}

void OperationManager::incomesMinusExpenses(vector <Operation> incomes, vector <Operation> expenses)
{
    float incomesTotal{}, expensesTotal{}, balance{};

    for(auto it = incomes.begin(); it < incomes.end(); ++it)
        incomesTotal += stof(it -> getAmount());


    for(auto it = expenses.begin(); it < expenses.end(); ++it)
        expensesTotal += stof(it -> getAmount());

    balance = incomesTotal - expensesTotal;
    cout << "BALANCE: " << balance << " PLN" << endl;
}

