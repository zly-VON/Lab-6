#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include <fstream>
#include <unistd.h>
#include <iostream>
using namespace std;

class CustomerData
{
    protected:
        string Name;
        string Cheque;
        double Balance;
        double Sum;
        int NrItems;
        string Particularity;

    public:
        virtual void Intro() = 0;
        virtual void addSum(double price) = 0;
        virtual void payHotDrink(double price) = 0;
        virtual double receiveDiscount() = 0;
        virtual void Payment() = 0;
        
        void setName(string name);
        string getName();
        void setCheque(string cheque);
        string getCheque();
        void setBalance(double balance);
        double getBalance();
        void setSum(double sum);
        double getSum();
        void setNrItems(int nrItems);
        int getNrItems();
        void setParticularity(string particularity);
        string getParticularity();

        void readCustomerData(int i, int money, int particularity);
};

#endif