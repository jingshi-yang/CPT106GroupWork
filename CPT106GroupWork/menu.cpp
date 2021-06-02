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

vector<dish> menu::getMenuList()
{
	vector<dish> dishList;
	auto iter = menuList.begin();
	for (; iter != menuList.end(); iter++)
	{
		dishList.push_back(*iter);
	}
	return dishList;
}

