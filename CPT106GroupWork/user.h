#pragma once
#include <string>
#include "dish.h"
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
private:
	string user_id;
	string username;

public:
	user(string username, string user_id);
	virtual void order();
	virtual int searchMaterial();
	virtual void newDish();

};

