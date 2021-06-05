#include "manager.h"

manager::manager(string username, string user_id) {
	this->username = username;
	this->user_id = user_id;
}

bool manager::Login(ifstream input) {
	bool success = true;
	string name, id;
	while (input >> name >> id) {
		if (name == username && id == user_id)
		{
			return success;
		}
	}
	success = false;
	return success;
}

void manager::order(dish newDish)
{
	dishList->addDish(newDish);
}

int manager::searchMaterial(string material, inventory totalinventory) {
	int returninventory;
	returninventory = totalinventory.getInventory(material);
	return returninventory;
}

void manager::newDish(dish newdish, vector<dish> totaldish, menu* currentmenu, inventory totalinventory){
	for (int i = 0; i < totaldish.size(); i++) {
		if (newdish.getname() == totaldish[i].getname())
		{
			throw DishexistException();
		}
	}
	if (newdish.getname().size() < 2 && newdish.getname().size() > 20) {
		throw DishnameException();
	}
	else if (newdish.getprice() < newdish.grossProfit()) {
		throw PriceIllegalException();
	}
	for (int i = 0; i < newdish.getmaterials().size(); i++) {
		if (totalinventory.isExisted(newdish.getmaterials()[i])) {
			cout << newdish.getmaterials()[i] << " ";
			throw NoMaterialsException();
		}
	}
	currentmenu->addDish(newdish);
	currentmenu->refresh(totalinventory);
}

void manager::deletedish(dish deletedish) {
	dishList->deleteDish(deletedish);
}

void manager::displaymenu() {
	if (dishList->getMenuList().size()) {
		dishList->showmenu();
	}
	else {
		throw NoDishException();
	}
}

double manager::check() {
	dishList->gettotalPrice();
	return dishList->gettotalGrossProfit();
	dishList->clear();
}