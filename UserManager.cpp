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
        cin >> login;
        user.setLogin(login);
    } while (checkIfLoginExists(user.getLogin()));

    cout << "Insert password: ";
    cin >> password;
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
    return false;
}

int UserManager::getLoggedUserId()
{
    return loggedUserId;
}

void UserManager::displayUsersData()
{
    cout << "Vector size: " << users.size() << endl;

    for(vector <User>::iterator itr = users.begin(); itr != users.end(); ++itr)
    {
        cout << "Login: " << itr -> getLogin() << endl;
        cout << "Password: " << itr -> getPassword() << endl;
        cout << "ID: " << itr -> getId() << endl << endl;
    }
}
