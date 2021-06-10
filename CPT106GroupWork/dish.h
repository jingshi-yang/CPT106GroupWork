#pragma once
#include <vector>
#include <string>
#include "inventory.h"
#include "Exceptions.h"

using namespace std;

class dish
{
private:
	string name;
	vector<string> materials;
	double price = 0;
	inventory *currentInventory;
public:
	dish(string dishname, vector<string> materialsInput, inventory *inventory, double price);
	double grossProfit();
	void isOrdered();
	void cancelOrdered();
	string getname();
	vector<string> getmaterials();
	double getprice();
};
