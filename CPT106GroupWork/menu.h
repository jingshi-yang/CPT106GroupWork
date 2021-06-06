#pragma once
#include <set>
#include "dish.h"

using namespace std;
class menu
{
private:
	// Use a set to store the dishes in menu to avoid repeat
	vector<dish> menuList;
	vector<int> ordernumber;
	double totalPrice = 0;
	double totalGrossProfit = 0;
public:
	menu();
	menu(vector<dish> dishlist, inventory totalinventory);

	void addDish(dish newDish);
	void deleteDish(dish deletedDish);
	void showmenu();
	double gettotalPrice();
	double gettotalGrossProfit();
	void refresh(inventory totalinventory);
	void clear();
	vector<dish> getMenuList();
};

