#ifndef _FILEWITHUSERS_H_
#define _FILEWITHUSERS_H_

#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class FileWithUsers
{
    const string FILE_NAME = "Users.xml";

    void removeFile(string fileNameWithExtension);

public:
    vector <User> loadUsersFromFile();
    void addUserToFile(User user);
    void saveAllUsersToFile(vector <User> users);
};

#endif
