#pragma once
#include "user.h"
class manager :
    public user
{
private:
    map<dish, int> orderList;
public:
    void order(dish newDish);

};

