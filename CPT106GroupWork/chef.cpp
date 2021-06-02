#include "chef.h"

int chef::searchMaterial(string material,inventory searchinventory) {
	int returninventory;
	returninventory = searchinventory.getInventory(material);
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