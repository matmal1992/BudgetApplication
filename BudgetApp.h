#ifndef _BUDGETAPP_H_
#define _BUDGETAPP_H_

#include "UserManager.h"
#include"OperationManager.h"

#include <string>

using namespace std;

class BudgetApp
{
    UserManager userManager;
    OperationManager *operationManager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;

public:
    //BudgetApp();
    //~BudgetApp();
    char chooseOptionFromUserMenu();
    char chooseOptionFromMainMenu();
    void goToMainMenu();
    void goToUserMenu();

};

#endif
