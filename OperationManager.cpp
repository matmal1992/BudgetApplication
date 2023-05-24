#include "OperationManager.h"

void OperationManager::addIncome()
{
    Income income;
    char choice{};

    cout << "To add a current income - press 1." << endl;
    cout << "To add an income with specified date - press 2." << endl << endl;
    choice = AuxiliaryMethods::readChar();

    if(choice != '1' && choice != '2')
    {
        cout << "There is no such option!" << endl;
        system("pause");
        return;
    }

    if(choice == '1')
        income.setDate(AuxiliaryMethods::getActualDate());

    if(choice == '2')
    {
        income.setDate(AuxiliaryMethods::getSpecifiedDate());
        if(income.getDate() == "")
        {
            cout << "Inserted data is incorrect." << endl;
            system("pause");
            return;
        }
    }

    cout << "Specify type of income: ";
    income.setItem(AuxiliaryMethods::readLine());
    cout << "Insert income in PLN: ";
    income.setAmount(AuxiliaryMethods::readInsertedAmountOfMoney());
    income.setIncomeId(fileWithIncomes.getLastIncomeId());
    income.setUserId(LOGGED_USER_ID);

    fileWithIncomes.saveIncomeToFile(income);
}

void OperationManager::addExpense()
{
    Expense expense;
    char choice{};

    cout << "To add a current expense - press 1." << endl;
    cout << "To add an expense with specified date - press 2." << endl << endl;
    choice = AuxiliaryMethods::readChar();

    if(choice != '1' && choice != '2')
    {
        cout << "There is no such option!" << endl;
        system("pause");
        return;
    }

    if(choice == '1')
        expense.setDate(AuxiliaryMethods::getActualDate());

    if(choice == '2')
    {
        expense.setDate(AuxiliaryMethods::getSpecifiedDate());
        if(expense.getDate() == "")
        {
            cout << "Inserted data is incorrect." << endl;
            system("pause");
            return;
        }
    }

    cout << "Specify type of expense: ";
    expense.setItem(AuxiliaryMethods::readLine());
    cout << "Insert expense in PLN: ";
    expense.setAmount(AuxiliaryMethods::readInsertedAmountOfMoney());
    expense.setExpenseId(fileWithExpenses.getLastExpenseId());
    expense.setUserId(LOGGED_USER_ID);

    fileWithExpenses.saveExpenseToFile(expense);
}
