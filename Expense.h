#ifndef _EXPENSE_H_
#define _EXPENSE_H_

#include <string>

using namespace std;

class Expense
{
    int userId;
    int expenseId;
    string date;
    string item;
    string amount;

public:
    void setExpenseId(int newId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getExpenseId();
    int getUserId();
    string getDate();
    string getItem();
    string getAmount();
};

#endif
