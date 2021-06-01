#include "customer.h"

void customer::order(dish newDish)
{
	orderList[newDish]++;
}
