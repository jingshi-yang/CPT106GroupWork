#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include<iomanip>
#include"menu.h"
using namespace std;

class FileIO
{
private:
	string filename;
public:
	FileIO(string name);
	ifstream readAllStream();
	vector<dish> readdish(inventory totalinventory);
	void writeinventoryToFile(vector<string> material, inventory Inventory);
	void writedishToFile(vector<dish> dishlist);
};

