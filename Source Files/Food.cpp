#include "Food.h"

void Food::setMass(double mass) { Mass = mass; }
double Food::getMass() { return Mass; }    

void Food::readFoodData(int i)
{
    ifstream fileFood;
    fileFood.open("Data List/foodData.txt", ios::in);

    string ignore;
    int j = i * 5;
    while(j--) getline(fileFood, ignore);

    readItemData(fileFood);
    
    string mass;
    getline(fileFood, mass);
    setMass(atof(mass.c_str()));

    fileFood.close();
}

void Food::wantedItemDescription()
{
    cout << "The customer wants to take " << getName() << endl;
    cout << "Price: " << Mass << " kg of " << getName();
    cout << " for " << getPrice() << "$." << endl;
}