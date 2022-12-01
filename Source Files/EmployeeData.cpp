#include "EmployeeData.h"

void EmployeeData::setName(string name) { Name = name; }
string EmployeeData::getName() { return Name; }
void EmployeeData::setWorkAges(int workAges) { WorkAges = workAges; }
int EmployeeData::getWorkAges() { return WorkAges; }
void EmployeeData::setRole(string role) { Role = role; }
string EmployeeData::getRole() { return Role; }
void EmployeeData::setSalary(double salary) { Salary = salary; }
double EmployeeData::getSalary() { return Salary; }

void EmployeeData::readEmployeeData(int i)
{
    ifstream fileEmployee;
    fileEmployee.open("Data List/employeeData.txt", ios::in);

    string ignore;
    int j = i * 4;
    while(j--) getline(fileEmployee, ignore);

    string name, workAges, role, salary;
    getline(fileEmployee, name);
    setName(name);
    getline(fileEmployee, workAges);
    setWorkAges(atof(workAges.c_str()));
    getline(fileEmployee, role);
    setRole(role);
    getline(fileEmployee, salary);
    setSalary(atof(salary.c_str()));

    fileEmployee.close();
}