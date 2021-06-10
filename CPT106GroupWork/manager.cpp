#include "manager.h"

manager::manager() {
}

void manager::order(dish newDish)
{
	dishList.addDish(newDish);
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

void manager::canceldish(dish deletedish) {
	dishList.deleteDish(deletedish);
	deletedish.cancelOrdered();
}

void manager::deletedish(dish deletedish) {
	dishList.deleteDish(deletedish);
}

void manager::displaymenu() {
	if (dishList.getMenuList().size()) {
		dishList.showmenu();
	}
	else {
		throw NoDishException();
	}
}

double manager::check() {
	cout<<dishList.gettotalPrice();
	return dishList.gettotalGrossProfit();
	dishList.clear();
}

job manager::returnjob() {
	return man;
}