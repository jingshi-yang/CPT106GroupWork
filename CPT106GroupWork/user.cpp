#include "user.h"

user::user() {
}


job user::Login(ifstream input)
{
	string uid;
	string pw;
	cout << "Please enter your user id." << endl;
	cin >> uid;
	cout << "Please enter your user password." << endl;
	cin >> pw;
	map<string, string> users;
	map<string, job> usergroup;
	string tempName, tempPW, tempUsergroup;
	while (input.get() != EOF)
	{
		input >> tempName >> tempPW >> tempUsergroup;
		users[tempName] = tempPW;
		if (tempUsergroup == "manager")
		{
			usergroup[uid] = man;
		}
		else
		{
			usergroup[uid] = che;
		}
	}
	user_id = uid;
	if (users[uid] == pw)
	{
		return usergroup[uid];
	}

	return cus;
}

void user::order(dish newDish)
{
	throw NoPermissionException();
}

int user::searchMaterial(string material, inventory totalinventory) 
{
	throw NoPermissionException();
}

void user::newDish(dish newdish, vector<dish> totaldish, menu* currentmenu, inventory totalinventory)
{
}

void user::deletedish(dish deletedish)
{
}

void user::displaymenu()
{
}

double user::check()
{
	return 0.0;
}
job user::returnjob()
{
	return job();
}