#ifndef _FILEWITHOPERATIONS_H_
#define _FILEWITHOPERATIONS_H_

#include "Operation.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class FileWithOperations
{
    const string FILE_NAME = "Operations.xml";
    int lastOperationId;

public:
    FileWithOperations()
    {
        lastOperationId = 0;
    }

    vector <Operation> loadOperationsFromFile(string&& typeOfOperation);
    void saveOperationToFile(Operation operation);
    void setLastOperationId(int lastId);
    int getLastOperationId();
};

#endif
