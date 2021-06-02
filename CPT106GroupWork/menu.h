#pragma once
#include <set>
#include "dish.h"

using namespace std;
class menu
{
private:
	// Use a set to store the dishes in menu to avoid repeat
	set<dish> menuList;
	double totalPrice;
	double totalGrossProfit;
public:
	menu(vector<dish>);

	void addDish(dish newDish);
	void deleteDish(dish deletedDish);

	set<dish> getMenuList();
};

