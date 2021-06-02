#pragma once
#include "user.h"
class manager :
    public user
{
private:
    map<dish, int> orderList;
    menu* dishList;
public:
    manager(string username, string user_id);
    bool Login(ifstream input);
    void order(dish newDish);
    int searchMaterial(string material, inventory totalinventory);
    void newDish(menu* currentmenu, inventory totalinventory);
};

