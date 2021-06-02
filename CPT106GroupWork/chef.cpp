#include "chef.h"

int chef::searchMaterial(string material,inventory searchinventory) {
	int returninventory;
	returninventory = searchinventory.getInventory(material);
	return returninventory;
}

void chef::newDish(menu *currentmenu,inventory totalinventory) {
	string dishname, meterial;
	vector<string> totalmeterial;
	inventory currentinventory;
	cout << "Please input dish name" << endl;
	cin >> dishname;
	int success = 1;
	while (success)
	{
		cout << "Please input dish metrials(If over, please input 0)" << endl;
		cin >> meterial;
		if (totalinventory.isExisted(meterial)) { 
			currentinventory.add(meterial, totalinventory.getInventory(meterial), totalinventory.getPrice(meterial)); 
		}
		else {
			cout << "Meterial " << meterial << "is not exist. Please input 1 to retry or 0 to exit" << endl;
		}
		cin >> success;
	}
	if (success) {
		dish dishname(meterial, currentinventory); // The constructer is not finished;
		currentmenu->addDish(dishname);
	}
}