#ifndef TRACKER_H
#define TRACKER_H

#include <iostream>
using namespace std;

class Tracker
{
    public:

        void enterStore(string name, double balance);
        void goMainStore(string name);
        void goFishmonger(string name);
        void goButcher(string name);
        void goDrinkSection(string name);
        void goVendingMachine(string name);
        void goCashier(string name);
        int workerBreak(int randNum);
        void leaveStore(string name);
        void announceRestock();
        int SuccessfulRestock();
};

#endif