#include "UserManager.h"

void UserManager::registerUser()
{
    User user = insertDataForNewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "The user has been registered successfully" << endl << endl;
    system("pause");
}

User UserManager::insertDataForNewUser()
{
    User user;
    user.setId(getNewUserId());

    string login{}, password{};
    do
    {
        cout << "Insert login: ";
        login = AuxiliaryMethods::readLine();
        user.setLogin(login);
    } while (checkIfLoginExists(user.getLogin()));

    cout << "Insert password: ";
    password = AuxiliaryMethods::readLine();
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty())
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::checkIfLoginExists(string login)
{
    for(vector <User>::iterator itr = users.begin(); itr != users.end(); ++itr)
    {
        if(itr -> getLogin() == login)
        {
            cout << endl << "User with such login already exists." << endl;
            return true;
        }
    }

    if(login == "")
    {
        cout << "Nothing has been inserted." << endl;
        return true;
    }

    return false;
}

int UserManager::getLoggedUserId()
{
    return loggedUserId;
}

bool UserManager::checkIfUserIsLogged()
{
    if(getLoggedUserId() > 0)
        return true;
    else
        return false;
}

void UserManager::logInUser()
{
    User user;
    string login{}, password{};

    cout << endl << "Insert login: ";
    login = AuxiliaryMethods::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attempts = 3; attempts > 0; attempts--)
            {
                cout << "Insert password. Attempts remained: " << attempts << ": ";
                password = AuxiliaryMethods::readLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "You logged in." << endl << endl;
                    system("pause");
                    setLoggedUserId(itr -> getId());
                    return;
                }
            }
            cout << "You inserted invalid password three times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user with such login." << endl << endl;
    system("pause");
}

void UserManager::setLoggedUserId(int id)
{
    loggedUserId = id;
}

void UserManager::changePasswordOfLoggedUser()
{
    string newPassword{};
    cout << "Insert new password: ";
    newPassword = AuxiliaryMethods::readLine();

    for (auto itr = users.begin(); itr != users.end(); ++itr)
    {
        if (itr -> getId() == loggedUserId)
        {
            itr -> setPassword(newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.saveChangedPasswordToFile(users);
}

void UserManager::logOutUser()
{
    loggedUserId = 0;
}




