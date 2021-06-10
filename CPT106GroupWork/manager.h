#pragma once
#include "user.h"
class manager :
    public user
{
private:
    map<dish, int> orderList;
    menu dishList;
public:
    manager();
    void order(dish newDish);
    int searchMaterial(string material, inventory totalinventory);
    void newDish(dish newdish, vector<dish> totaldish, menu* currentmenu, inventory totalinventory);
    void canceldish(dish deletedish);
    void deletedish(dish deletedish);
    void displaymenu();
    double check();
    job returnjob();
};

