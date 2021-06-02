#pragma once
#include "user.h"
#include "menu.h"
class chef :
    public user
{
private:
public:
    chef(string username, string user_id);
    bool Login(ifstream input);
    int searchMaterial(string material, inventory totalinventory);
    void newDish(menu *currentmenu, inventory totalinventory);
};

