#pragma once
#include "user.h"

class customer :
    public user
{
private:
    map<dish, int> orderList;
public:
    void order(dish newDish);
};

