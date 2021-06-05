#include "user.h"

user::user(string username, string user_id) {
	this->username = username;
	this->user_id = user_id;
}

user::user()
{
}

user::job user::Login(ifstream input)
{
	string uid;
	string pw;
	cout << "Please enter your user id." << endl;
	cin >> uid;
	cout << "Please enter your user password." << endl;
	cin >> pw;
	map<string, string> users;
	map<string, user::job> usergroup;
	string tempName, tempPW, tempUsergroup;
	while (input.get() != EOF)
	{
		input >> tempName >> tempPW >> tempUsergroup;
		users[tempName] = tempPW;
		if (tempUsergroup == "manager")
		{
			usergroup[uid] = manager;
		}
		else
		{
			usergroup[uid] = chef;
		}
	}
	if (users[uid] == pw)
	{
		return usergroup[uid];
	}

	return customer;
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
