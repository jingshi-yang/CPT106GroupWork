#pragma once
#include <vector>
#include <string>
#include "inventory.h"

using namespace std;
class dish
{
private:
	vector<string> materials;
	double price;
	inventory *currentInventory;
public:
	dish(string materialsInput, inventory inventory);
	double grossProfit();
	void isOrdered();
};

