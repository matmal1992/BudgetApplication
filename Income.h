#ifndef _INCOME_H_
#define _INCOME_H_

#include <string>

using namespace std;

class Income
{
    int userId;
    int incomeId;
    string date;
    string item;
    string amount;

public:
    void setIncomeId(int newId);
    void setUserId(int userId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getIncomeId();
    int getUserId();
    string getDate();
    string getItem();
    string getAmount();
};

#endif
