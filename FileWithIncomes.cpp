#include "FileWithIncomes.h"

void FileWithIncomes::saveIncomeToFile(Income income)
{
    CMarkup xml;

    if(!xml.Load(FILE_NAME))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
        xml.IntoElem();
        xml.AddElem("Income");
        xml.IntoElem();
        xml.AddElem("IncomeId", 1);
    }
    else
    {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while(xml.FindElem());
        xml.AddElem("Income");
        xml.IntoElem();
        xml.AddElem("IncomeId", AuxiliaryMethods::intToStringConversion(getLastIncomeId() + 1));
    }

    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());

    xml.Save(FILE_NAME);
}

vector <Income> FileWithIncomes::loadIncomesFromFile()
{
    vector <Income> incomes;
    CMarkup xml;
    Income income;

    if(!xml.Load(FILE_NAME))
        cout << "The file is empty!" << endl;
    else
    {
        xml.FindElem("Incomes");
        xml.IntoElem();

        while(xml.FindElem("Income"))
        {
            xml.IntoElem();

            xml.FindElem("IncomeId");
            income.setIncomeId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));
            xml.FindElem("UserId");
            income.setUserId(AuxiliaryMethods::stringToIntConversion(xml.GetData()));
            xml.FindElem("Date");
            income.setDate(xml.GetData());
            xml.FindElem("Item");
            income.setItem(xml.GetData());
            xml.FindElem("Amount");
            income.setAmount(xml.GetData());

            xml.OutOfElem();
            incomes.push_back(income);
        }
        setLastIncomeId(incomes);
    }
    return incomes;
}

int FileWithIncomes::getLastIncomeId()
{
    return lastIncomeId;
}

void FileWithIncomes::setLastIncomeId(vector <Income> incomes)
{
    if (incomes.empty())
        lastIncomeId = 1;
    else
        lastIncomeId = incomes.back().getIncomeId();
}
