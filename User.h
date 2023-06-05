#ifndef _USER_H_
#define _USER_H_

#include <string>

using namespace std;

class User
{
    int id;
    string name;
    string surname;
    string login;
    string password;

public:
    void setId(int newId);
    void setName(string newName);
    void setSurname(string newSurname);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getId() const;
    string getName() const;
    string getSurname() const;
    string getLogin() const;
    string getPassword() const;
};

#endif
