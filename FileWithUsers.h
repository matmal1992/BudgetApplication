#ifndef _FILEWITHUSERS_H_
#define _FILEWITHUSERS_H_

#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class FileWithUsers : public XmlFile
{
public:
    FileWithUsers() : XmlFile("Users.xml") {}

    vector <User> loadUsersFromFile();
    void addUserToFile(User user);
    void saveChangedPasswordToFile(vector <User> &users);
};

#endif
