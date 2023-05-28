#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;

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

void FileWithUsers::saveAllUsersToFile(vector <User> users)
{
    CMarkup xml;

    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem("Users");
    xml.IntoElem();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); ++itr)
    {
        xml.AddElem(itr -> getLogin());
        xml.IntoElem();
        xml.AddElem("Id", itr -> getId());
        xml.AddElem("Login", itr -> getLogin());
        xml.AddElem("Password", itr -> getPassword());
        xml.OutOfElem();
    }

    removeFile(FILE_NAME);
    xml.Save(FILE_NAME);
}

void FileWithUsers::removeFile(string fileNameWithExtension)
{
    if (remove(fileNameWithExtension.c_str()) == 0) {}
    else
        cout << "Removing of the file failed. " << fileNameWithExtension << endl;
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    vector <User> users;
    CMarkup xml;
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
