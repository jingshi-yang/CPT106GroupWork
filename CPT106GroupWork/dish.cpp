#include "dish.h"


dish::dish(string dishname, vector<string> materialsInput, inventory inventory, double inputprice)
{
	name = dishname;
	materials = materialsInput;
	currentInventory = &inventory;
	price = inputprice;
}


double dish::grossProfit()
{
	double grossProfit = 0.0;
	double cost = 0;
	for (int i = 0; i < materials.size(); i++)
	{
		cost += currentInventory->getPrice(materials[i]);
	}
	grossProfit = price - cost;
	return grossProfit;
}

void dish::isOrdered()
{
	for (size_t i = 0; i < materials.size(); i++)
	{
		currentInventory->consume(materials[i], 1);
	}
}

void dish::cancelOrdered() {
	for (size_t i = 0; i < materials.size(); i++) {
		currentInventory->purchase(materials[i], 1);
	}
}

string dish::getname() {
	return name;
}

vector<string> dish::getmaterials() {
	return materials;
}

double dish::getprice() {
	return price;
}