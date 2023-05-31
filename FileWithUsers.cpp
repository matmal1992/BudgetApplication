#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    if(!xml.Load(FILE_NAME))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
        xml.IntoElem();
    }
    else
    {
        xml.FindElem("Users");
        xml.IntoElem();
        while(xml.FindElem());
    }

    xml.AddElem(user.getLogin());
    xml.IntoElem();
    xml.AddElem("Id", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save(FILE_NAME);
}

void FileWithUsers::saveChangedPasswordToFile(vector <User> users)
{
    vector <User>::iterator it = users.begin();

    xml.Load(FILE_NAME);

    xml.FindElem("Users");
    xml.IntoElem();
    while(xml.FindElem())
    {
        xml.IntoElem();
        xml.FindElem("Password");

        if(xml.GetData() != it -> getPassword())
        {
            xml.RemoveElem();
            xml.AddElem("Password", it -> getPassword());
        }

        it++;
        xml.OutOfElem();
    }

    xml.Save(FILE_NAME);
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    vector <User> users;
    User user;

    if(!xml.Load(FILE_NAME))
    {
        cout << "The file is empty!" << endl;
        system("pause");
    }
    else
    {
        xml.FindElem("Users");
        xml.IntoElem();
        while(xml.FindElem())
        {
            xml.IntoElem();
            xml.FindElem("Id");
            user.setId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));
            xml.FindElem("Login");
            user.setLogin(xml.GetData());
            xml.FindElem("Password");
            user.setPassword(xml.GetData());
            xml.OutOfElem();

            users.push_back(user);
        }
    }

    return users;
}
