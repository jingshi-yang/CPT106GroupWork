#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "menu.h"
#include "user.h"
using namespace std;

class FileIO
{
private:
	string filename;
public:
	FileIO(string name);
	ifstream readAllStream();
	vector<dish> readdish(inventory totalinventory);
	map<string, int> readInventoryMaterials();
	map<string, double> readInventoryPrices();
	map<string, string> readUsersPw();
	map<string, job> readUsersJob();
	void writeinventoryToFile(vector<string> material, inventory Inventory);
	void writedishToFile(vector<dish> dishlist);
};