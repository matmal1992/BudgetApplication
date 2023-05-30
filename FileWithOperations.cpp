#include "FileWithOperations.h"

void FileWithOperations::saveOperationToFile(Operation expense)
{
    CMarkup xml;

    if(!xml.Load(FILE_NAME))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Operations");
        xml.IntoElem();
        xml.AddElem("Operation");
        xml.IntoElem();
        xml.AddElem("OperationId", 1);
    }
    else
    {
        xml.FindElem("Operations");
        xml.IntoElem();
        while(xml.FindElem());
        xml.AddElem("Operation");
        xml.IntoElem();
        xml.AddElem("OperationId", AuxiliaryMethods::intToStringConversion(getLastOperationId() + 1));
    }

    xml.AddElem("Type", expense.getType());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Title", expense.getTitle());
    xml.AddElem("Amount", expense.getAmount());

    xml.Save(FILE_NAME);
}

vector <Operation> FileWithOperations::loadOperationsFromFile(string&& typeOfOperation)
{
    vector <Operation> operations;
    CMarkup xml;
    Operation operation;

    if(!xml.Load(FILE_NAME))
    {
        cout << "The file is empty!" << endl;
        setLastOperationId(1);
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
        }
        xml.OutOfElem();
        cout << "Actual node 0: " << xml.GetTagName() << endl;
        system("pause");
        xml.IntoElem();
        xml.FindElem("OperationId");
        xml.IntoElem();
        cout << "LastOpId: " << xml.GetData() << endl;
        cout << "Actual node: " << xml.GetTagName() << endl;
        system("pause");
        setLastOperationId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));
    }
    return operations;
}

int FileWithOperations::getLastOperationId()
{
    return lastOperationId;
}

void FileWithOperations::setLastOperationId(int lastId)
{
    lastOperationId = lastId;
}
