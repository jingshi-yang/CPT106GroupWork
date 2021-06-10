#pragma once
#include <string>
#include<iomanip>
#include<iostream>
#include <map>
#include <vector>
#include <fstream>
#include "Exceptions.h"

using namespace std;

class inventory
{
private:
	map<string, int> materials;		// Stores the quantity of raw materials
	map<string, double> prices;		// Stores the prices of raw materials

public:
	inventory(map<string, int> newMaterials, map<string, double> newPrices);

	void add(string key, int value, double price);		// Add a new raw material
	void consume(string key, int consume_value);		// Reduce the quantity of given raw material
	void purchase(string key, int purchase_value);		// Induce the quantity of given raw material
	void changePrice(string key, double newPrice);		// Change the price of given raw material
	void deleteMaterial(string key);					// Delete a material
	bool isExisted(string key);

	vector<string> getmaterials(); // Return all materials
	int getInventory(string key);	// Return the quantity of given material
	double getPrice(string key);	// Return the price of given material
	void showMaterials();			// Display all materials
	
};

