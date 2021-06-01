#pragma once
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class FileIO
{
private:
	string filename;
public:
	FileIO(string name);
	ifstream readAllStream();
	void writeToFile();
};

