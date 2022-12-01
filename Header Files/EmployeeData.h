#ifndef EMPLOYEEDATA_H
#define EMPLOYEEDATA_H

#include <fstream>
#include <unistd.h>
#include <iostream>
using namespace std;

class EmployeeData
{
    protected:
        string Name;
        int WorkAges;
        string Role;
        double Salary;
    
    public:
        virtual void Intro() = 0;
        virtual void sayTotalSum(double sum) = 0;
        virtual void chequeRequest(string cheque) = 0;
        virtual int checkCheque(double sum, string cheque) = 0;
        virtual int checkDiscount(int num) = 0;

        void setName(string name);
        string getName();
        void setWorkAges(int workAges);
        int getWorkAges();
        void setRole(string role);
        string getRole();
        void setSalary(double salary);
        double getSalary();

        void readEmployeeData(int i);
};

#endif