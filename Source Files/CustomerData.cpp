#include "CustomerData.h"

void CustomerData::setName(string name) { Name = name; }
string CustomerData::getName() { return Name; }
void CustomerData::setCheque(string cheque) { Cheque = cheque; }
string CustomerData::getCheque() { return Cheque; }
void CustomerData::setBalance(double balance) { Balance = balance; }
double CustomerData::getBalance() { return Balance; }
void CustomerData::setSum(double sum) { Sum = sum; }
double CustomerData::getSum() { return Sum; }
void CustomerData::setNrItems(int nrItems) { NrItems = nrItems; }
int CustomerData::getNrItems() { return NrItems; }
void CustomerData::setParticularity(string particularity) { Particularity = particularity; }
string CustomerData::getParticularity() { return Particularity; }

void CustomerData::readCustomerData(int i, int money, int particularity)
{
    ifstream fileCustomer;
    fileCustomer.open("Data List/customerData.txt", ios::in);

    string ignore;
    while(i--) getline(fileCustomer, ignore);

    string name;
    getline(fileCustomer, name);
    setName(name);

    Cheque = "NotPaid";
    Balance = money;
    Sum = 0;
    NrItems = 0;
    if (particularity < 1) Particularity = "Nuts Allergy";
    else if (particularity < 6) Particularity = "Milk Allergy";
    else if (particularity < 21) Particularity = "Vegetarian";
    else Particularity = "Nothing";
    
    fileCustomer.close();
}