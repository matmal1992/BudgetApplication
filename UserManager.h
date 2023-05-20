#ifndef _USERMANAGER_H_
#define _USERMANAGER_H_

#include "FileWithUsers.h"
#include "User.h"

#include <iostream>
#include <vector>

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User insertDataForNewUser();


public:
    UserManager(): loggedUserId(0)
    {
        users = fileWithUsers.loadUsersFromFile();
    }

    void registerUser();
    int getNewUserId();
    bool checkIfLoginExists(string login);
    int getLoggedUserId();
    void displayUsersData();





};

#endif
