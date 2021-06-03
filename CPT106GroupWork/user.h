#pragma once
#include <string>
#include "menu.h"

using namespace std;

struct NoPermissionException :
	public exception
{
	const char* what() const throw() {
		return "You do not have permission.";
	}
};

class user

{
protected:
	string user_id;
	string username;


public:
	virtual bool Login(ifstream input);
	virtual void order(dish newDish);
	virtual int searchMaterial(string material, inventory totalinventory);
	virtual void newDish(menu* currentmenu, inventory totalinventory);

};

