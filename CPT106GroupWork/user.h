#pragma once
#include <string>

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
	void quit();
	virtual void order();
	virtual int searchMaterial();
	virtual void newDish();

};

