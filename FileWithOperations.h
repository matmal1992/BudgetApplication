#ifndef _FILEWITHOPERATIONS_H_
#define _FILEWITHOPERATIONS_H_

#include "Operation.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class FileWithOperations : public XmlFile
{
    int lastOperationId;
    void setLastOperationId(vector <Operation> operations);

public:
    FileWithOperations(): XmlFile("Operations.xml")
    {
        lastOperationId = 0;
    }

    vector <Operation> loadOperationsFromFile(string&& typeOfOperation);
    void saveOperationToFile(Operation operation);
    int getLastOperationId();
};

#endif
