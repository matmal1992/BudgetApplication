#include "OperationManager.h"

void OperationManager::addIncome()
{
    Income income;
    char choice{};

    cout << "To add a current income - press 1." << endl;
    cout << "To add an income from past - press 2." << endl << endl;
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
        cout << "When was the income? Insert date in format YYYY-MM-DD: ";
        income.setDate(AuxiliaryMethods::readLine());
        //date validator. Max up to the last day of the current month
    }

    cout << "Specify type of income: ";
    income.setItem(AuxiliaryMethods::readLine());
    cout << "Insert income in PLN: ";
    income.setAmount(AuxiliaryMethods::readInsertedAmountOfMoney());
    income.setIncomeId(fileWithIncomes.getLastIncomeId());
    income.setUserId(LOGGED_USER_ID);

    fileWithIncomes.saveIncomeToFile(income);
}

void OperationManager::displayIncomesData()
{
    cout << "Vector size: " << incomes.size() << endl;

    for(vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); ++itr)
    {
        cout << "UserId: " << itr -> getUserId() << endl;
        cout << "IncomeId: " << itr -> getIncomeId() << endl;
        cout << "Date: " << itr -> getDate() << endl;
        cout << "Item: " << itr -> getItem() << endl;
        cout << "Amount: " << itr -> getAmount() << endl << endl;
    }
    system("pause");
}
