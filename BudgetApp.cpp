#include "BudgetApp.h"
#include "AuxiliaryMethods.h"

using namespace std;

char BudgetApp::chooseOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register user" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::readChar();

    return choice;
}

void BudgetApp::goToMainMenu()
{
    while (true)
    {
        if (userManager.getLoggedUserId() == 0)
        {
            switch (chooseOptionFromMainMenu())
            {
            case '1':
                userManager.registerUser();
                break;
            case '2':
                userManager.logInUser();

                if(userManager.checkIfUserIsLogged())
                {
                    operationManager = new OperationManager(userManager.getLoggedUserId());
                    goToUserMenu();
                }
                break;
            case '9':
                exit(0); break;
            default:
                cout << endl << "There is no such option in menu!" << endl << endl;
                system("pause");
                break;
            }
        }
    }
}

char BudgetApp::chooseOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Show balance of actual month" << endl;
    cout << "4. Show balance of previous month" << endl;
    cout << "5. Show balance of selected month" << endl;
    cout << "6. Show balance of selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::readChar();

    return choice;
}

void BudgetApp::goToUserMenu()
{
    while(userManager.getLoggedUserId() != 0)
    {
        switch (chooseOptionFromUserMenu())
        {
        case '1': operationManager -> addIncome();
            break;
        case '2': //operationManager -> addExpense();
            break;
        case '3': //operationManager -> displayBalanceOfCurrentMonth();
            break;
        case '4': //operationManager -> displayBalanceOfPreviousMonth();
            break;
        case '5': //operationManager -> displayBalanceOfSelectedMonth();
            break;
        case '6': //operationManager -> displayBalanceOfSelectedPeriod();
            break;
        case '7': userManager.changePasswordOfLoggedUser();
            break;
        case '8':
            userManager.logOutUser();
            delete operationManager;
            operationManager = NULL;
            break;
        default:
            cout << "You inserted invalid data!" << endl;
        }
    }
}
