#include "Expense.h"

void Expense::setId(int newId)
{
    if(id >= 0)
        id = newId;
}

void Expense::setDate(string newDate) {date = newDate;}
void Expense::setItem(string newItem) {item = newItem;}
void Expense::setAmount(float newAmount) {amount = newAmount;}

int Expense::getId() {return id;}
string Expense::getDate() {return date;}
string Expense::getItem() {return item;}
float Expense::getAmount() {return amount;}
