#include "User.h"

void User::setId(int newId)
{
    if(id >= 0)
        id = newId;
}

void User::setLogin(string newLogin) {login = newLogin;}
void User::setPassword(string newPassword) {password = newPassword;}
void User::setName(string newName) {name = newName;}
void User::setSurname(string newSurname) {surname = newSurname;}

int User::getId() const {return id;}
string User::getLogin() const {return login;}
string User::getPassword() const {return password;}
string User::getName() const {return name;}
string User::getSurname() const {return surname;}
