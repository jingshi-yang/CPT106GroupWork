#pragma once
#include "user.h"

class customer :
    public user
{
private:
    menu dishList;
public:
    customer();
    void order(dish newDish);
    void canceldish(dish deletedish);
    void displaymenu();
    double check();
    job returnjob();
};

