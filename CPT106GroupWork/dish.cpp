#include "dish.h"


dish::dish(string materialsInput, inventory inventory)
{
	currentInventory = &inventory;
}

double dish::grossProfit()
{
	double grossProfit = 0.0;
	double cost = 0;
	for (size_t i = 0; i < materials.size(); i++)
	{
		cost += currentInventory->getPrice(materials[i]);
	}
	grossProfit = this->price - cost;
	return grossProfit;
}

void dish::isOrdered()
{
	for (size_t i = 0; i < materials.size(); i++)
	{
		currentInventory->consume(materials[i], 1);
	}
}
