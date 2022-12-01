#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "EmployeeData.h"
#include <fstream>
#include <unistd.h>
#include <iostream>
using namespace std;

class Employee : public EmployeeData
{   
    public:
        void Intro();
        void sayTotalSum(double sum);
        void chequeRequest(string cheque);
        int checkCheque(double sum, string cheque);
        int checkDiscount(int num);
};

#endif