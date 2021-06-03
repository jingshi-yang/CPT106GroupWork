#include "user.h"

user::user(string username, string user_id) {
	this->username = username;
	this->user_id = user_id;
}

void user::order(dish newDish)
{
	throw NoPermissionException();
}

int user::searchMaterial(string material, inventory totalinventory) 
{
	throw NoPermissionException();
}

void user::newDish(menu* currentmenu, inventory totalinventory) 
{
	throw NoPermissionException();
}
