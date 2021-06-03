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
	string name;
	vector<string> materials;
	double price = 0;
	inventory *currentInventory;
public:
	dish(string dishname, vector<string> materialsInput, inventory inventory, double price);
	dish(ifstream input, inventory inventory);
	double grossProfit();
	void isOrdered();
	string getname();
	vector<string> getmaterials();
	double getprice();
};
