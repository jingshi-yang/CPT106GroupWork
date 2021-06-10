#pragma once
#include <string>
#include <conio.h>
#include "Exceptions.h"
#include "menu.h"

using namespace std;

enum job
{
	man, che, cus
};

class user

{
protected:
	string user_id;
	job user_job;
	virtual string getPassword();

public:
	user();
	virtual job Login(map<string,string> users, map<string, job> userGroup);
	virtual void order(dish newDish);
	virtual int searchMaterial(string material, inventory totalinventory);
	virtual void newDish(dish newdish, vector<dish> totaldish, menu* currentmenu, inventory totalinventory);
	virtual void canceldish(dish deletedish);
	virtual void deletedish(dish deletedish);
	virtual void displaymenu();
	virtual double check();
	virtual job returnjob();
};

