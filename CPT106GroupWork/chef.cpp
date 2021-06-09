#include "chef.h"
chef::chef()
{
}

int chef::searchMaterial(string material,inventory totalinventory) {
	int returninventory;
	returninventory = totalinventory.getInventory(material);
	return returninventory;
}

void chef::newDish(dish newdish, vector<dish> totaldish, menu *currentmenu,inventory totalinventory) {
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

job chef::returnjob() {
	return che;
}