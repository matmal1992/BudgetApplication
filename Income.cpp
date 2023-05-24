#include "Income.h"

void Income::setIncomeId(int newId)
{
    if(newId >= 0)
        incomeId = newId;
}

void Income::setDate(string newDate) {date = newDate;}
void Income::setItem(string newItem) {item = newItem;}
void Income::setAmount(string newAmount) {amount = newAmount;}
void Income::setUserId(int newId) {userId = newId;}

int Income::getIncomeId() {return incomeId;}
int Income::getUserId() {return userId;}
string Income::getDate() {return date;}
string Income::getItem() {return item;}
string Income::getAmount() {return amount;}
