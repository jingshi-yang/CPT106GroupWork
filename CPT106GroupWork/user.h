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

enum job
{
	man, che, cus
};

class user

{
protected:
	string user_id;
	job user_job;

public:
	//user(string username, string user_id, job user_job);
	user();
	virtual job Login(ifstream input);
	virtual void order(dish newDish);
	virtual int searchMaterial(string material, inventory totalinventory);
	virtual void newDish(dish newdish, vector<dish> totaldish, menu* currentmenu, inventory totalinventory);
	virtual void deletedish(dish deletedish);
	virtual void displaymenu();
	virtual double check();
	virtual job returnjob();
};

