#pragma once
#include "user.h"
class manager :
    public user
{
private:
    map<dish, int> orderList;
    menu* dishList;
public:
    void order(dish newDish);
};

