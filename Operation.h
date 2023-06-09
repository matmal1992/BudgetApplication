#ifndef _OPERATION_H_
#define _OPERATION_H_

#include <string>

using namespace std;

class Operation
{
    int userId;
    int operationId;
    string type;
    string date;
    string title;
    string amount;

public:
    void setOperationId(int newId);
    void setUserId(int newUserId);
    void setType(string newType);
    void setDate(string newDate);
    void setTitle(string newTitle);
    void setAmount(string newAmount);

    int getOperationId() const;
    int getUserId() const;
    string getType() const;
    string getDate() const;
    string getTitle() const;
    string getAmount() const;
};

#endif
