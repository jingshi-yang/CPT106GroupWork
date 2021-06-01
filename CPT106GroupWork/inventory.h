#pragma once
#include <string>
#include <map>
using namespace std;
class inventory
{
private:
	map<string, int> materials;		// Stores the quantity of raw materials
	map<string, double> price;		// Stores the prices of raw materials

public:
	inventory();

	void add(string key, int value, double price);		// Add a new raw material
	void consume(string key, int consume_value);		// Reduce the quantity of given raw material
	void purchase(string key, int purchase_value);		// Induce the quantity of given raw material
	void changePrice(string key, double newPrice);		// Change the price of given raw material

	int getInventory(string key);	// Return the quantity of given material
	double getPrice(string key);	// Return the price of given material

};

