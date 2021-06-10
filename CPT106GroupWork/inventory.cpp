#include "inventory.h"

bool inventory::isExisted(string key)
{
	if (materials.find(key) == materials.end())
	{
		return false;
	}
	return true;
}

inventory::inventory(map<string, int> newMaterials, map<string, double> newPrices)
{
	materials = newMaterials;
	prices = newPrices;
}

void inventory::add(string key, int value, double price)
{
	if (isExisted(key)) throw MaterialExistException();
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

void inventory::deleteMaterial(string key)
{
	if (materials.find(key) == materials.end())
	{
		throw NoMaterialsException();
	}
	materials.erase(key);
	prices.erase(key);
}

vector<string> inventory::getmaterials() {
	vector<string> returnmaterials;
	for (auto iter = materials.begin(); iter != materials.end(); iter++) {
		returnmaterials.push_back(iter->first);
	}
	return returnmaterials;
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

void inventory::showMaterials()
{
	map<string, int>::iterator it;
	int count = 0;
	it = materials.begin();
	cout << "--------------------------------------\n";
	cout << "|No.|        name        |count|price|\n";
	while (it != materials.end()) {
		cout << "|" << setw(2) << count << ".|" << setw(20) << it->first << "|" << setw(5) << it->second << "|" << setw(5) << prices[it->first] << "|" << endl;
		count++;
		it++;
	}
	cout << "--------------------------------------\n";
}
