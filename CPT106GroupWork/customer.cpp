#include "customer.h"

customer::customer()
{
}

void customer::order(dish newDish)
{
		dishList.addDish(newDish);
}

void customer::deletedish(dish deletedish) {
		dishList.deleteDish(deletedish);
		deletedish.cancelOrdered();
}

void customer::displaymenu() {
	if (dishList.getMenuList().size()) {
		dishList.showmenu();
	}
	else {
		throw NoDishException();
	}
 }

double customer::check() {
	 cout << dishList.gettotalPrice();
	 return dishList.gettotalGrossProfit();
	 dishList.clear();
}

job customer::returnjob() {
	return cus;
}