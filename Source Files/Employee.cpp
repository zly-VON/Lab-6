#include "Employee.h"

void Employee::Intro()
{
    cout << "Hi. I am " << getName() << endl;
    cout << "I am the " << getRole() << " that works today" << endl;
}
void Employee::sayTotalSum(double sum)
{
    cout << "The total comes to " << sum << "$." << endl;
}
void Employee::chequeRequest(string cheque)
{
    cout << "I will control the cheque of the customer" << endl;
    cout << endl;
    cout << getName() << " shows the cheque" << endl;
    cout << "+-------------+" << endl;
    if (cheque == "Paid") cout << "|    " << cheque << "     |" << endl;
    else cout << "|   " << cheque << "   |" << endl;
    cout << "+-------------+" << endl;
    
}
int Employee::checkCheque(double sum, string cheque)
{
    if (sum == 0 && cheque == "NotPaid")
    { 
        cout << "The customer did not buy anything. He is free to leave." << endl;
        return 1;
    }
    else if (cheque == "NotPaid") 
    {
        cout << "The customer have not paid! He cannot leave. \n" << endl;
        return 0;
    }
    else 
    {
        cout << "It is all right.\n" << endl;
        return 1;
    }
}
int Employee::checkDiscount(int num)
{
    if (num == 12) 
    {
        cout << "\nOh, you bought 12 items. You won a discount of 10%, congrats!" << endl;
        return 1;
    }
    else return 0;
}