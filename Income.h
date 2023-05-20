#ifndef _INCOME_H_
#define _INCOME_H_

#include <string>

using namespace std;

class Income
{
    int userId;
    int id;
    string date;
    string item;
    float amount;

public:
    void setId(int newId);
    //void setUserId(int userId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getId();
    int getUserId();
    string getDate();
    string getItem();
    float getAmount();
};

#endif
