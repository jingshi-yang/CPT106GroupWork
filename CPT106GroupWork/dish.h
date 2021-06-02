#pragma once
#include <vector>
#include <string>
#include "inventory.h"

using namespace std;

struct NoDishException :
	public exception
{
	const char* what() const throw() {
		return "Your chosen dish does not exist.";
	}
};

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

