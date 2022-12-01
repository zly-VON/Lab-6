#include "Tracker.h"
#include "Store.h"
#include "Customer.h"
#include "Employee.h"
#include "Food.h"
#include "Drink.h"
#include <ctime>
#include <signal.h>
#include <iostream>
using namespace std;

int temp = 0;
int customerNr = 0;
int employeeNr = 5;
int foodNr = 70;
int drinkNr = 21;
int restock = 0;
int quantityRestock = 30;
int allergicPeopleNr = 0;
int vegPeopleNr = 0;
int peopleNotPaidNr = 0;
int discountsNr = 0;
int discountSum = 0;
Store store;
string NutsList[6] = {"Almonds", "Cashew Nuts", "Walnuts", "Coconut", "Pistachios", "Hazelnut"};
string MilkList[5] = {"Milk", "Yogurt", "Cheese", "Butter", "Cacao Butter"};
int nutListSize = sizeof(NutsList)/sizeof(NutsList[0]);
int milkListSize = sizeof(MilkList)/sizeof(MilkList[0]);

void handler(int signum);
int randNumber(int min, int max);
int updateCustomerList(string name, string List[], int nr);
int itemToBuy(Customer c, Food fs[], int start, int stop, string list[], int prodNr);
int fishMeatToGet(Food fs[], int start, int stop, string list[], int prodNr);
int drinkToGet(Drink ds[], Customer c, int start, int stop, string list[], int prodNr);

int main(void)
{
    srand(time(NULL));
    system("clear");

    store.setName("Random Store");
    store.setDate("12.03.1998");
    store.setOutcome(0);
    store.setIncome(0);
    store.setBoughtItems(0);
    store.setSoldItems(0);
    store.setStolenItems(0);
    store.Welcome();

    signal(SIGINT, handler);

    Employee employees[employeeNr];
    for (int i = 0; i < employeeNr; i++)
    {
        employees[i].readEmployeeData(i);
        store.setOutcome(store.getOutcome() + employees[i].getSalary());
    }

    Food foods[foodNr];
    for (int i = 0; i < foodNr; i++)
    {
        foods[i].readFoodData(i);
        foods[i].setShopPrice(0.7 * foods[i].getPrice());

        store.addOutcome(foods[i].getShopPrice(), foods[i].getQuantity());
    }
    
    Drink drinks[drinkNr];
    for (int i = 0; i < drinkNr; i++)
    {
        drinks[i].readDrinkData(i);
        drinks[i].setShopPrice(0.7 * drinks[i].getPrice());

        store.addOutcome(drinks[i].getShopPrice(), drinks[i].getQuantity());
    }

    // what a customer does
    for (int i = 0; i < INT64_MAX; i++)
    {
        Tracker track;
        Customer customer;
        customer.readCustomerData(randNumber(0, 99), randNumber(55, 1000), randNumber(1, 100));

        if (customer.getParticularity() != "Nothing")
        if (customer.getParticularity() == "Vegetarian") vegPeopleNr++;
        else allergicPeopleNr++;

        customerNr = i + 1;

        cout << endl;
        track.enterStore(customer.getName(), customer.getBalance());
        int productNr = 0, times = randNumber(2, 12);
        string productList[12];

        while (times--)
        {
            int nr = 0, option = randNumber(1, 5);
            if (customer.getParticularity() == "Vegetarian")
            {
                while (option == 3)
                    option = randNumber(1, 5);
            }

            switch (option)
            {   // main section
                case 1:
                    track.goMainStore(customer.getName());
                    nr = itemToBuy(customer, foods, 28, foodNr-1, productList, productNr);
                    foods[nr].wantedItemDescription();
                    if (foods[nr].checkQuantity())
                    {
                        foods[nr].takeItem();
                        productNr = updateCustomerList(foods[nr].getName(), productList, productNr);
                        customer.addSum(foods[nr].getPrice());
                    }
                    else foods[nr].noItem();
                break;
                // fish section
                case 2:
                    track.goFishmonger(customer.getName());
                    if (track.workerBreak(randNumber(1, 100)))
                    {
                        nr = fishMeatToGet(foods, 12, 27, productList, productNr);
                        foods[nr].wantedItemDescription();
                        if (foods[nr].checkQuantity())
                        {
                            foods[nr].takeItem();
                            productNr = updateCustomerList(foods[nr].getName(), productList, productNr);
                            customer.addSum(foods[nr].getPrice());
                        }
                        else foods[nr].noItem();
                    }
                break;
                // meat section
                case 3:
                    track.goButcher(customer.getName());
                    if (track.workerBreak(randNumber(1, 100)))
                    {
                        nr = fishMeatToGet(foods, 0, 11, productList, productNr);
                        foods[nr].wantedItemDescription();
                        if (foods[nr].checkQuantity())
                        {
                            foods[nr].takeItem();
                            productNr = updateCustomerList(foods[nr].getName(), productList, productNr);
                            customer.addSum(foods[nr].getPrice());
                        }
                        else foods[nr].noItem();
                    }
                break;
                // drink section
                case 4:
                    track.goDrinkSection(customer.getName());
                    nr = drinkToGet(drinks, customer, 5, drinkNr-1, productList, productNr);
                    drinks[nr].wantedItemDescription();
                    if (drinks[nr].checkQuantity())
                    {
                        drinks[nr].takeItem();
                        productNr = updateCustomerList(drinks[nr].getName(), productList, productNr);
                        customer.addSum(drinks[nr].getPrice());
                    }
                    else drinks[nr].noItem();
                break;
                // hot drink section
                case 5:
                    track.goVendingMachine(customer.getName());
                    nr = randNumber(0, 4);
                    drinks[nr].wantedItemDescription();
                    if (drinks[nr].checkQuantity())
                    {   // buy hot drink
                        if (customer.getBalance() > drinks[nr].getPrice())
                        {
                            drinks[nr].takeItem();
                            customer.payHotDrink(drinks[nr].getPrice());
                            store.addIncome(drinks[nr].getPrice(), customer.getNrItems());
                        }
                        else cout << "The customer does not have enough money " << endl;
                    }
                    else drinks[nr].noItem();
                break;

                default:
                    cout << "ERROR! Closing Simulation" << endl;
                    return 0;
                break;
            }
        }
        // cashier
        if (randNumber(1, 100) < 95 && customer.getSum() != 0)
        {
            track.goCashier(customer.getName());
            employees[0].Intro();
            employees[0].sayTotalSum(customer.getSum());
            if (employees[0].checkDiscount(customer.getNrItems()))
            {
                discountSum += customer.receiveDiscount();
                discountsNr++;
                employees[0].sayTotalSum(customer.getSum());
            }
            store.addIncome(customer.getSum(), customer.getNrItems());
            customer.Payment();
        }
        else store.setStolenItems(store.getStolenItems() + customer.getNrItems());
        
        // security guard
        if (randNumber(1, 100) < 30)
        {
            employees[3].Intro();
            employees[3].chequeRequest(customer.getCheque());
            
            if (!employees[3].checkCheque(customer.getSum(), customer.getCheque()))
            {
                peopleNotPaidNr++;
                store.addIncome(customer.getSum(), customer.getNrItems());
                store.setStolenItems(store.getStolenItems() - customer.getNrItems());
                customer.Payment();
            }
        }
        // customer leaves store
        track.leaveStore(customer.getName());
        // restock
        if (customerNr % 1000 == 0) temp = 0;
        if (temp == 0 && randNumber(1, 100) < 30)
        {
            employees[4].Intro();
            track.announceRestock();
            for (int i = 0; i < foodNr; i++)
            {
                foods[i].Restock(quantityRestock);
                store.addOutcome(foods[i].getShopPrice(), quantityRestock);
            }
            for (int i = 0; i < drinkNr; i++)
            {
                drinks[i].Restock(quantityRestock);
                store.addOutcome(drinks[i].getShopPrice(), quantityRestock);
            }
            store.setOutcome(store.getOutcome() + track.SuccessfulRestock());
            restock++;
            temp = 1;
        }
    }
    return EXIT_SUCCESS;
}

int randNumber(int min, int max)
{
    int randomNumber;
    randomNumber = (rand() % (max - min + 1)) + min;
    return randomNumber;
}

int itemToBuy(Customer c, Food fs[], int start, int stop, string list[], int prodNr)
{
    int nr;
    int flag = -1;
    while(flag != prodNr)
    {
        flag = 0;
        nr = randNumber(start, stop);
        if (c.getParticularity() == "Milk Allergy")
        {
            for (int j = 0; j < milkListSize; j++)
            {
                while (fs[nr].getName() == MilkList[j])
                    nr = randNumber(28, foodNr-1);
            }
        }
        if (c.getParticularity() == "Nuts Allergy")
        {
            for (int j = 0; j < nutListSize; j++)
            {
                while (fs[nr].getName() == NutsList[j])
                    nr = randNumber(28, foodNr-1);
            }
        }
        for (int i = 0; i < prodNr; i++)
            if (fs[nr].getName() != list[i]) flag++;
    }
    return nr;
}

int fishMeatToGet(Food fs[], int start, int stop, string list[], int prodNr)
{
    int nr;
    int flag = -1;
    while(flag != prodNr)
    {
        flag = 0;
        nr = randNumber(start, stop);
        for (int i = 0; i < prodNr; i++)
            if (fs[nr].getName() != list[i]) flag++;
    }
    return nr;
}

int drinkToGet(Drink ds[], Customer c, int start, int stop, string list[], int prodNr)
{
    int nr;
    int flag = -1;
    while(flag != prodNr)
    {
        flag = 0;
        nr = randNumber(start, stop);
        
        if (c.getParticularity() == "Milk Allergy" )
        {
            while (ds[nr].getName() == MilkList[0])
                nr = randNumber(28, foodNr-1);
        }
        for (int i = 0; i < prodNr; i++)
            if (ds[nr].getName() != list[i]) flag++;
    }
    return nr;
}

int updateCustomerList(string name, string List[], int nr)
{
    List[nr] = name;
    nr++;
    return nr;
}

void handler(int signum) 
{
    cout << endl;
    cout << "Statistics" << endl;
    cout << endl;
    cout << "Store exepenses: " << store.getOutcome() << " $" << endl;
    cout << "Store income: " << store.getIncome() << " $" << endl;
    cout << "Store revenue: " << store.getIncome() - store.getOutcome() << " $" << endl;
    cout << "Discount given: " << discountsNr << " - " << discountSum << " $" << endl;
    cout << "Bought Products: " << store.getSoldItems() << endl;
    cout << "Sold products: " << store.getBoughtItems() << endl;
    cout << "Stolen products: " << store.getStolenItems() << endl;
    cout << "Remainig products: " << store.getSoldItems() - store.getBoughtItems() - store.getStolenItems() << endl;
    cout << "Nr of restocks: " << restock << endl;
    cout << "Restock quantity per item: " << quantityRestock << endl;
    cout << endl;
    cout << "Based on " << endl;
    cout << "Total customers: " << customerNr << endl;
    cout << "Vegetarian People: " << vegPeopleNr << endl;
    cout << "Allergic People: " << allergicPeopleNr << endl;
    cout << "People caught to stole: " << peopleNotPaidNr << endl;
    exit(signum);
}