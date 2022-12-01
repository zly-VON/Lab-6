#include "Tracker.h"

void Tracker::enterStore(string name, double balance)
{
    cout << "Customer " << name << " has entered the store." << endl;
    cout << name << " is checking the balance. Total = ";
    cout << balance << "$." << endl;
}
void Tracker::goMainStore(string name)
{
    cout << name << " is in the Main Section.\n" << endl;
}
void Tracker::goFishmonger(string name)
{
    cout << name << " is going to the fishmonger.\n" << endl;
}
void Tracker::goButcher(string name)
{
    cout << name << " is going to the butcher.\n" << endl;
}
void Tracker::goDrinkSection(string name)
{
    cout << name << " is going to the Beverage Section.\n" << endl;
}
void Tracker::goVendingMachine(string name)
{
    cout << name << " is going to the Vending Machine.\n" << endl;
}
void Tracker::goCashier(string name)
{
    cout << name << " is going to the cashier.\n" << endl;
}
int Tracker::workerBreak(int randNum)
{
    if (randNum <= 15)
    {
        cout << "\nWe are really sorry, the employee in charge of this section is temporary on break" << endl;
        cout << "Come back later" << endl;
        return 0;
    }
    else return 1;
}
void Tracker::leaveStore(string name)
{
    cout << endl;
    cout << name << " goes out of the store.\n" << endl;
}
void Tracker::announceRestock()
{
    cout << "I am here to restock all the item of the store" << endl;
}
int Tracker::SuccessfulRestock() 
{
    cout << "\nAll items were restored" << endl;
    return 50;
}