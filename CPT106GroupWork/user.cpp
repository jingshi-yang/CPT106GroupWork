#include "user.h"

void user::order()
{
	throw NoPermissionException();
}

int user::searchMaterial()
{
	throw NoPermissionException();
}

void user::newDish()
{
	throw NoPermissionException();
}
