#include "FileWithOperations.h"

void FileWithOperations::saveOperationToFile(const Operation &operation)
{
    if(!xml.Load(getFileName()))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Operations");
        xml.IntoElem();
        xml.AddElem("Operation");
        xml.IntoElem();
        xml.AddElem("Type", operation.getType());
        xml.AddElem("OperationId", 1);
    }
    else
    {
        xml.FindElem("Operations");
        xml.IntoElem();
        while(xml.FindElem());
        xml.AddElem("Operation");
        xml.IntoElem();
        xml.AddElem("Type", operation.getType());
        xml.AddElem("OperationId", AuxiliaryMethods::intToStringConversion(getLastOperationId() + 1));
    }

    xml.AddElem("UserId", operation.getUserId());
    xml.AddElem("Date", operation.getDate());
    xml.AddElem("Title", operation.getTitle());
    xml.AddElem("Amount", operation.getAmount());

    lastOperationId++;

    xml.Save(getFileName());
}

vector <Operation> FileWithOperations::loadOperationsFromFile(string&& typeOfOperation)
{
    vector <Operation> operations;
    Operation operation;

    if(!xml.Load(getFileName()))
    {
        cout << "The file with operations is empty!" << endl;
    }
    else
    {
        xml.FindElem("Operations");
        xml.IntoElem();

        while(xml.FindElem("Operation"))
        {
            xml.IntoElem();
            xml.FindElem("Type");

            if(xml.GetData() == typeOfOperation)
            {
                operation.setType(xml.GetData());
                xml.FindElem("OperationId");
                operation.setOperationId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));
                xml.FindElem("UserId");
                operation.setUserId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));
                xml.FindElem("Date");
                operation.setDate(xml.GetData());
                xml.FindElem("Title");
                operation.setTitle(xml.GetData());
                xml.FindElem("Amount");
                operation.setAmount(xml.GetData());

                xml.OutOfElem();
                operations.push_back(operation);
            }
            else
                xml.OutOfElem();
        }

        setLastOperationId(operations);
    }
    return operations;
}

int FileWithOperations::getLastOperationId()
{
    return lastOperationId;
}

void FileWithOperations::setLastOperationId(const vector <Operation> &operations)
{
    if(operations.empty() && getLastOperationId() == 0)
        lastOperationId = 1;

    if(!operations.empty() && getLastOperationId() == 0)
        lastOperationId = operations.back().getOperationId();

    if(!operations.empty() && getLastOperationId() != 0)
    {
        if(operations.back().getOperationId() > getLastOperationId())
            lastOperationId = operations.back().getOperationId();
    }
}
