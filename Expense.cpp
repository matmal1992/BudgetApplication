#include "Expense.h"

void Expense::setExpenseId(int newId)
{
    if(newId >= 0)
        expenseId = newId;
}

void Expense::setUserId(int newUserId) {userId = newUserId;}
void Expense::setDate(string newDate) {date = newDate;}
void Expense::setItem(string newItem) {item = newItem;}
void Expense::setAmount(string newAmount) {amount = newAmount;}

int Expense::getExpenseId() {return expenseId;}
int Expense::getUserId() {return userId;}
string Expense::getDate() {return date;}
string Expense::getItem() {return item;}
string Expense::getAmount() {return amount;}

