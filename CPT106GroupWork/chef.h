#pragma once
#include "user.h"
class chef :
    public user
{
private:
public:
    int searchMaterial(string material);
    void newDish(string input);
};

