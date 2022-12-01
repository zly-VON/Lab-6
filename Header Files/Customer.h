#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CustomerData.h"
#include <fstream>
#include <unistd.h>
#include <iostream>
using namespace std;

class Customer : public CustomerData
{
    public:
        void Intro();
        void addSum(double price);
        void payHotDrink(double price);
        double receiveDiscount();
        void Payment();
};

#endif