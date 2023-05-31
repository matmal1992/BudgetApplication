#ifndef _BUDGETAPP_H_
#define _BUDGETAPP_H_

#include "UserManager.h"
#include"OperationManager.h"
#include "AuxiliaryMethods.h"
#include "DateMethods.h"

using namespace std;

class BudgetApp
{
    UserManager userManager;
    OperationManager *operationManager;

    char chooseOptionFromUserMenu();
    char chooseOptionFromMainMenu();
    void goToUserMenu();

public:
    ~BudgetApp()
    {
        delete operationManager;
        operationManager = NULL;
    }

    void goToMainMenu();
};

#endif
