#ifndef _XMLFILE_H_
#define _XMLFILE_H_

#include "Markup.h"

using namespace std;

class XmlFile
{
    const string FILE_NAME;

protected:
    CMarkup xml;

public:
    XmlFile(string fileName): FILE_NAME(fileName) {}

    string getFileName();
};

#endif

