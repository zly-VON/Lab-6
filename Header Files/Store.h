#ifndef STORE_H
#define STORE_H

#include <fstream>
#include <unistd.h>
#include <iostream>
using namespace std;


class Store
{
    private:
        string Name;
        string Date;
        double Outcome;
        double Income;
        int BoughtItems;
        int SoldItems;
        int StolenItems;

    public:
        void setName(string name);
        string getName();
        void setDate(string date);
        string getDate();
        void setOutcome(double outcome);
        double getOutcome();
        void setIncome(double income);
        double getIncome();
        void setBoughtItems(int boughtItems);
        int getBoughtItems();
        void setSoldItems(int soldItems);
        int getSoldItems();
        void setStolenItems(int stolenItems);
        int getStolenItems();

        void Welcome();
        void addOutcome(double price, int quantity);
        void addIncome(double price, int nr);
};

#endif