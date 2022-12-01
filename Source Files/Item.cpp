#include "Item.h"

void Item::setName(string name) { Name = name; }
string Item::getName() { return Name; }
void Item::setDate(string date) { Date = date; }
string Item::getDate() { return Date; }
void Item::setPrice(double price) { Price = price; }
double Item::getPrice() { return Price; }
void Item::setShopPrice(double shopPrice) { ShopPrice = shopPrice; }
double Item::getShopPrice() { return ShopPrice; }
void Item::setQuantity(int quantity) { Quantity = quantity; }
int Item::getQuantity() { return Quantity; }  

void Item::readItemData(ifstream &file)
{
    string name, date, price, quantity;
    getline(file, name);
    setName(name);
    getline(file, date);
    setDate(date);
    getline(file, price);
    setPrice(atof(price.c_str()));
    getline(file, quantity);
    setQuantity(atof(quantity.c_str()));
}

int Item::checkQuantity()
{
    if (Quantity <= 0) return 0;
    else return 1;
}
void Item::noItem()
{
    cout << "We are really sorry, there is no more " << Name << endl;
}
void Item::takeItem()
{
    cout << "\nThe customer took " << Name << endl;
    Quantity--;
}
void Item::Restock(int quant)
{
    Quantity = Quantity + quant;
}
int Item::putItem(string itemCustomer)
{
    if (itemCustomer == Name) 
    { 
        Quantity++; 
        return 1;
    }
    else return 0;
}