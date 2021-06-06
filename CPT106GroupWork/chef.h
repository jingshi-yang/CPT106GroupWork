#pragma once
#include "user.h"
#include "menu.h"
class chef :
    public user
{
private:
public:
    chef(string username, string user_id);
    job Login(ifstream input);
    int searchMaterial(string material, inventory totalinventory);
    void newDish(dish newdish, vector<dish> totaldish, menu *currentmenu, inventory totalinventory);
};