#include "Store.h"

void Store::setName(string name) { Name = name; }
string Store::getName() { return Name; }
void Store::setDate(string date) { Date = date; }
string Store::getDate() { return Date; }
void Store::setOutcome(double outcome) { Outcome = outcome; }
double Store::getOutcome() { return Outcome; }
void Store::setIncome(double income) { Income = income; }
double Store::getIncome() { return Income; }
void Store::setBoughtItems(int boughtItems) { BoughtItems = boughtItems; }
int Store::getBoughtItems() { return BoughtItems; }
void Store::setSoldItems(int soldItems) { SoldItems = soldItems; }
int Store::getSoldItems() { return SoldItems; }
void Store::setStolenItems(int stolenItems) { StolenItems = stolenItems; }
int Store::getStolenItems() { return StolenItems; }

void Store::Welcome()
{
    cout << "Hello. Welcome at " << getName() << endl;
}
void Store::addOutcome(double price, int quantity)
{
    Outcome += price * quantity;
    BoughtItems += quantity;
}
void Store::addIncome(double price, int nr)
{
    Income += price;
    SoldItems += nr;
}