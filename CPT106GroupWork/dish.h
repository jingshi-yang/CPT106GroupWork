#pragma once
#include <vector>
#include <string>

using namespace std;
class dish
{
private:
	vector<string> materials;
	double price;
public:
	dish(string materialsInput);
	double grossProfit();
	void isOrdered();
};

