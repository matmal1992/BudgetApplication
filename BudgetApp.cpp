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
               /* userManager.logInUser();

                if(userManager.checkIfUserIsLogged())
                {
                    addresseeManager = new AddresseeManager(FILE_NAME_WITH_ADDRESSEES, userManager.getLoggedUserId());
                    goToUserMenu();
                }
                break;*/
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
