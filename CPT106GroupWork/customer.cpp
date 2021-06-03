#include "customer.h"

void customer::order(dish newDish)
{
	if (dishList->getMenuList().count(newDish) == 0) {
		throw NoDishException();
	}
	orderList[newDish]++;
}
