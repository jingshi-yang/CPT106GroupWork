#pragma once
#include "user.h"

class customer :
    public user
{
private:
 //   map<dish, int> orderList;
    menu dishList;
public:
    customer();
    void order(dish newDish);
    void deletedish(dish deletedish);
    void displaymenu();
    double check();
    job Login();
    job returnjob();
};

