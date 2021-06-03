#include "chef.h"

chef::chef(string username, string user_id) {
	this->username = username;
	this->user_id = user_id;
}

bool chef::Login(ifstream input) {
	bool success = true;
	string name, id;
	while (input >> name >> id) {
		if (name == username&&id == user_id)
		{
			return success;
		}
	}
	success = false;
	return success;
}

int chef::searchMaterial(string material,inventory totalinventory) {
	int returninventory;
	returninventory = totalinventory.getInventory(material);
	return returninventory;
}

void chef::newDish(menu *currentmenu,inventory totalinventory) {
	string dishname, material;
	double price;
	vector<string> totalmaterial;
	cout << "Please input dish name" << endl;
	cin >> dishname;
	int success = 1;
	while (success)
	{
		cout << "Please input dish matrials" << endl;
		cin >> material;
		if (totalinventory.isExisted(material)) { 
			totalmaterial.push_back(material);
			cout << "If that is all materials, please input 0 to exit, if not, input 1 to continue";
			cin >> success;
			if (success) { continue; }
		}
		else {
			cout << "Material " << material << "is not exist. Please input 1 to retry or 0 to exit" << endl;
			cin >> success;
		}
	}
	cout << "Please input price:" << endl;
	cin >> price;
	if (success) {
		dish newdish(dishname, totalmaterial, totalinventory, price);
		currentmenu->addDish(newdish);
	}
}