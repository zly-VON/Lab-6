#include "Customer.h"

void Customer::Intro()
{
    cout << "Hi. I am " << getName() << endl;
}
void Customer::addSum(double price) 
{ 
    Sum = Sum + price; 
    NrItems = NrItems + 1;
}
void Customer::payHotDrink(double price)
{
    Balance = Balance - price;
    NrItems = NrItems + 1;
    cout << "\nNotification: " << price;
    cout << "$ have been substracted from the balance of the customer." << endl;
    cout << "Remaining balance: " << getBalance() << "$." << endl; 
}
double Customer::receiveDiscount()
{
    double discount = Sum * 10 / 100;
    Sum = Sum * 90 / 100;
    return discount;
}
void Customer::Payment() 
{ 
    Balance = Balance - Sum; 
    cout << "\nNotification: " << Sum;
    cout << "$ have been substracted from the balance of the customer." << endl;
    cout << "Remaining balance: " << getBalance() << "$." << endl; 
    if (Cheque == "Paid") Cheque = "NotPaid";
    else Cheque = "Paid";
    Sum = 0;
}
