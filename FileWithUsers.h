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
public:
    void addUserToFile(User user);
    string getFileName();
    vector <User> loadUsersFromFile();





};

#endif
