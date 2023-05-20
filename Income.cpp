#include "Income.h"

void Income::setId(int newId)
{
    if(id >= 0)
        id = newId;
}

void Income::setDate(string newDate) {date = newDate;}
void Income::setItem(string newItem) {item = newItem;}
void Income::setAmount(float newAmount) {amount = newAmount;}

int Income::getId() {return id;}
string Income::getDate() {return date;}
string Income::getItem() {return item;}
float Income::getAmount() {return amount;}
