#include "menu.h"

using namespace std;

menu::menu() {
	totalPrice = 0;
	totalGrossProfit = 0;
}

menu::menu(vector<dish> dishList, inventory totalinventory)
{
	vector<string> materials;
	bool success = true;
	for (int i = 0; i < dishList.size(); i++)
	{
		success = true;
		materials = dishList[i].getmaterials();
		for (int j = 0; j < materials.size(); j++) {
			if (!(totalinventory.isExisted(materials[j])&&totalinventory.getInventory(materials[j])>0))
			{
				success = false;
				break;
			}
		}
		if (success) {
			menuList.push_back(dishList[i]);
			ordernumber.push_back(1);
		}
	}
}

void menu::addDish(dish newDish)
{
	for (int i = 0; i < menuList.size(); i++) {
		if ( menuList[i].getname() == newDish.getname())
		{
			ordernumber[i]++;
			newDish.isOrdered();
		}
		else if(i = menuList.size()-1)
		{
			menuList.push_back(newDish);
			ordernumber.push_back(1);
			newDish.isOrdered();
		}
	}
}

void menu::deleteDish(dish deletedDish)
{
	auto iter1 = ordernumber.begin();
	for (auto iter = menuList.begin();iter!=menuList.end();iter++)
	{
		if (iter->getname() == deletedDish.getname() )
		{
			if(ordernumber[distance(menuList.begin(), iter)]>1){
				menuList.erase(iter);
				deletedDish.cancelOrdered();
				return;
			}
			else {
				menuList.erase(iter);
				ordernumber.erase(iter1);
				return;
			}
		}
		iter1++;
	}
	throw NoDishException();
}

void menu::showmenu() {
	cout << "--------------------------------------\n";
	cout << "|No.|        name        |count|price|\n";
	for (int i = 0; i < menuList.size(); i++) {
		cout << "|" << setw(2) << i << ".|" << setw(20) << menuList[i].getname() << "|" << setw(5) << ordernumber[i] << "|" << setw(5) << menuList[i].getprice()<<"|" << endl;
	}
	cout << "--------------------------------------\n";
}

double menu::gettotalPrice() {
	totalPrice = 0;
	for (int i = 0; i < menuList.size(); i++) {
		totalPrice += menuList[i].getprice();
	}
	return totalPrice;
}

double menu::gettotalGrossProfit() {
	totalGrossProfit = 0;
	for (int i = 0; i < menuList.size(); i++)
	{
		totalGrossProfit += menuList[i].grossProfit();
	}
	return totalGrossProfit;
}

void menu::refresh(inventory totalinventory) {
	vector<string> materials;
	for (auto iter = menuList.begin(); iter != menuList.end(); iter++) {
		materials.clear();
		materials = iter->getmaterials();
		for (int j = 0; j < menuList.size(); j++) {
			if (!totalinventory.getInventory(materials[j])) {
				menuList.erase(iter);
			}
		}
	}
}

vector<dish> menu::getMenuList()
{
	return menuList;
}

void menu::clear() {
	menuList.clear();
	menuList.clear();
	totalPrice = 0;
	totalGrossProfit = 0;
}