#include "FileWithExpenses.h"

void FileWithExpenses::saveExpenseToFile(Expense expense)
{
    CMarkup xml;

    if(!xml.Load(FILE_NAME))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
        xml.IntoElem();
        xml.AddElem("Expense");
        xml.IntoElem();
        xml.AddElem("ExpenseId", 1);
    }
    else
    {
        xml.FindElem("Expenses");
        xml.IntoElem();
        while(xml.FindElem());
        xml.AddElem("Expense");
        xml.IntoElem();
        xml.AddElem("ExpenseId", AuxiliaryMethods::intToStringConversion(getLastExpenseId() + 1));
    }

    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", expense.getAmount());

    xml.Save(FILE_NAME);
}

vector <Expense> FileWithExpenses::loadExpensesFromFile()
{
    vector <Expense> expenses;
    CMarkup xml;
    Expense expense;

    if(!xml.Load(FILE_NAME))
        cout << "The file is empty!" << endl;
    else
    {
        xml.FindElem("Expenses");
        xml.IntoElem();

        while(xml.FindElem("Expense"))
        {
            xml.IntoElem();

            xml.FindElem("ExpenseId");
            expense.setOperationId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));
            xml.FindElem("UserId");
            expense.setUserId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));
            xml.FindElem("Date");
            expense.setDate(xml.GetData());
            xml.FindElem("Item");
            expense.setItem(xml.GetData());
            xml.FindElem("Amount");
            expense.setAmount(xml.GetData());

            xml.OutOfElem();
            expenses.push_back(expense);
        }
        setLastExpenseId(expenses);
    }
    return expenses;
}

int FileWithExpenses::getLastExpenseId()
{
    return lastExpenseId;
}

void FileWithExpenses::setLastExpenseId(vector <Expense> expenses)
{
    if (expenses.empty())
        lastExpenseId = 1;
    else
        lastExpenseId = expenses.back().getOperationId();
}
