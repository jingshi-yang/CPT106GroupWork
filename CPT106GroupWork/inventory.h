#pragma once
#include <string>
#include<iomanip>
#include<iostream>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

struct QuantityIllegalException:
	public exception
{
	const char* what() const throw() {
		return "The quantity is illegal.";
	}
};

struct PriceIllegalException :
	public exception
{
	const char* what() const throw() {
		return "The price is illegal.";
	}
};

struct NoMaterialsException:
	public exception
{
	const char* what() const throw() {
		return "Material doesn't exist in inventory.";
	}
};

class inventory
{
private:
	map<string, int> materials;		// Stores the quantity of raw materials
	map<string, double> prices;		// Stores the prices of raw materials

public:
	inventory();
	inventory(ifstream input);

	void add(string key, int value, double price);		// Add a new raw material
	void consume(string key, int consume_value);		// Reduce the quantity of given raw material
	void purchase(string key, int purchase_value);		// Induce the quantity of given raw material
	void changePrice(string key, double newPrice);		// Change the price of given raw material
	bool isExisted(string key);

	int getInventory(string key);	// Return the quantity of given material
	double getPrice(string key);	// Return the price of given material
	
};

