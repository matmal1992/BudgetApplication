#include "Operation.h"

void Operation::setOperationId(int newId)
{
    if(newId >= 0)
        operationId = newId;
}

void Operation::setUserId(int newUserId) {userId = newUserId;}
void Operation::setType(string newType) {type = newType;}
void Operation::setDate(string newDate) {date = newDate;}
void Operation::setTitle(string newTitle) {title = newTitle;}
void Operation::setAmount(string newAmount) {amount = newAmount;}

int Operation::getOperationId() {return operationId;}
int Operation::getUserId() {return userId;}
string Operation::getType() {return type;}
string Operation::getDate() {return date;}
string Operation::getTitle() {return title;}
string Operation::getAmount() {return amount;}

