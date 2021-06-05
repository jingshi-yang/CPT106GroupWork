#pragma once
#include "user.h"

class customer :
    public user
{
private:
 //   map<dish, int> orderList;
    menu* dishList;
public:
    customer(menu& dishlist);
    void order(dish newDish);
    void deletedish(dish deletedish);
    void displaymenu();
    double check();
    job Login();
};

