#include "inventory.h"

bool inventory::isExisted(string key)
{
	if (materials.find(key) == materials.end())
	{
		return false;
	}
	return true;
}

void inventory::add(string key, int value, double price)
{
	if (!isExisted(key)) throw NoMaterialsException();
	materials.insert(pair<string, int>(key, value));
	prices.insert(pair<string, double>(key, price));
}

void inventory::consume(string key, int consume_value)
{
	if (!isExisted(key)) throw NoMaterialsException();
	if (consume_value > materials[key])
	{
		throw QuantityIllegalException();
	}
	materials[key] -= consume_value;
}

void inventory::purchase(string key, int purchase_value)
{
	if (!isExisted(key)) throw NoMaterialsException();
	materials[key] += purchase_value;
}

void inventory::changePrice(string key, double newPrice)
{
	if (!isExisted(key)) throw NoMaterialsException();
	prices[key] = newPrice;
}

int inventory::getInventory(string key)
{
	if (!isExisted(key)) throw NoMaterialsException();
	return materials[key];
}

double inventory::getPrice(string key)
{
	if (!isExisted(key)) throw NoMaterialsException();
	return prices[key];
}
