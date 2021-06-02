#include "manager.h"

void manager::order(dish newDish)
{
	if (dishList->getMenuList().count(newDish) == 0) {
		throw NoDishException();
	}
	orderList[newDish]++;
}
