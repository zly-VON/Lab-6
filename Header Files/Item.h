#ifndef ITEM_H
#define ITEM_H

#include <fstream>
#include <unistd.h>
#include <iostream>
using namespace std;

class Item
{
    private:
        string Name;
        string Date;
        double Price;
        double ShopPrice;
        int Quantity;

    public:
        virtual void wantedItemDescription() = 0;

        void setName(string name);
        string getName();
        void setDate(string date);
        string getDate();
        void setPrice(double price);
        double getPrice();
        void setShopPrice(double shopPrice);
        double getShopPrice();
        void setQuantity(int quantity);
        int getQuantity();

        void readItemData(ifstream &file);

        int checkQuantity();
        void noItem();
        void takeItem();
        void Restock(int quant);
        int putItem(string itemCustomer);
};

#endif