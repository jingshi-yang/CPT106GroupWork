#include "menu.h"

using namespace std;

menu::menu(vector<dish> dishList)
{
	for (int i = 0; i < dishList.size(); i++)
	{

	}
}

void menu::addDish(dish newDish)
{
	menuList.insert(newDish);
}

void menu::deleteDish(dish deletedDish)
{
	menuList.erase(deletedDish);
}

set<dish> menu::getMenuList()
{
	return menuList;
}

