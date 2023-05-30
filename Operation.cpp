#include "Operation.h"

void Operation::setOperationId(int newId)
{
    if(newId >= 0)
        operationId = newId;
}

void Operation::setUserId(int newUserId) {userId = newUserId;}
void Operation::setDate(string newDate) {date = newDate;}
void Operation::setItem(string newItem) {item = newItem;}
void Operation::setAmount(string newAmount) {amount = newAmount;}

int Operation::getOperationId() {return operationId;}
int Operation::getUserId() {return userId;}
string Operation::getDate() {return date;}
string Operation::getItem() {return item;}
string Operation::getAmount() {return amount;}

