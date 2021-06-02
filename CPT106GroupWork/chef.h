#pragma once
#include "user.h"
#include "menu.h"
class chef :
    public user
{
private:
public:
    int searchMaterial(string material, inventory inventory);
    void newDish(menu *currentmenu, inventory currentinventory);
};

