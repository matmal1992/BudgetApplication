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

public:
    ~BudgetApp()
    {
        delete operationManager;
        operationManager = NULL;
    }

    char chooseOptionFromUserMenu();
    char chooseOptionFromMainMenu();
    void goToMainMenu();
    void goToUserMenu();

};

#endif
