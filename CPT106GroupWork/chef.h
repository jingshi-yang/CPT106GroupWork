#pragma once
#include "user.h"
#include "menu.h"
class chef :
    public user
{
private:
public:
    chef();
    job Login(ifstream input);
    job returnjob();
    int searchMaterial(string material, inventory totalinventory);
    void newDish(dish newdish, vector<dish> totaldish, menu *currentmenu, inventory totalinventory);
};