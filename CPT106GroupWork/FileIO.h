#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "dish.h"

using namespace std;

class FileIO
{
private:
	string filename;
public:
	FileIO(string name);
	ifstream readAllStream();
	vector<dish> readMenu();
	void writeToFile();
};

