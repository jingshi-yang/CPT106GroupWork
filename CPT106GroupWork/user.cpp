#include "user.h"

string user::getPassword()
{
	string pw;
	char ch;
	ch = _getch();
	while (ch != '\n' && ch != '\r')
	{
		if (ch == 8) {
			_putch('\b');
			_putch(' ');
			_putch('\b');
			pw.erase(pw.end() - 1);
			ch = _getch();
			continue;
		}
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
			_putch('*');
			pw += ch;
			ch = _getch();
		}
	}
	_putch('\n');
	return pw;
}

user::user() {
}

job user::Login(map<string, string> users, map<string, job> usergroup)
{
	string uid;
	string pw;
	cout << "Please enter your user id." << endl;
	cin >> uid;
	if (uid == "customer" || uid == "Customer" || uid == "CUSTOMER")
	{
		return cus;
	}
	cout << "Please enter your user password." << endl;
	pw = getPassword();
	user_id = uid;
	if (users[uid] == pw)
	{
		return usergroup[uid];
	}
	throw WrongUserException();
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
	throw NoPermissionException();
}

void user::canceldish(dish deletedish)
{
	throw NoPermissionException();
}

void user::deletedish(dish deletedish)
{
	throw NoPermissionException();
}

void user::displaymenu()
{
	throw NoPermissionException();
}

double user::check()
{
	return 0.0;
}
job user::returnjob()
{
	return job();
}