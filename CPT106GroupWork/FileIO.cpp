#include "FileIO.h"
#include "user.h"

FileIO::FileIO(string name)
{
	this->filename = name;
}

ifstream FileIO::readAllStream()
{
	ifstream fin;
	fin.unsetf(ios::skipws);
	fin.open(filename, ios::in);
//	fin.close();
	return fin;
}

vector<dish> FileIO::readdish(inventory *totalinventory) {
	ifstream fin;
	vector<dish> readdish;
	vector<string> materials;
	string name, material;
	double price;
	fin.open(filename);
	fin.seekg(0,ios::beg);
	while (fin >> name >> price) {
		while (fin.get() != '\n') {
			fin >> material;
			materials.push_back(material);
		}
		dish newdish(name, materials, totalinventory, price);
		readdish.push_back(newdish);
		materials.clear();
	}
	return readdish;
}

map<string, int> FileIO::readInventoryMaterials()
{
	ifstream fin;
	map<string, int> materials;
	string tempName;
	int materialAmount;
	double price;
	fin.open(filename);
	while (fin >> tempName >> materialAmount >> price) {
		materials[tempName] = materialAmount;
	}
	fin.close();
	return materials;
}

map<string, double> FileIO::readInventoryPrices()
{
	ifstream fin;
	map<string, double> prices;
	string tempName;
	int materialAmount;
	double price;
	fin.open(filename);
	while (fin >> tempName >> materialAmount >> price) {
		prices[tempName] = price;
	}
	fin.close();
	return prices;
}

map<string, string> FileIO::readUsersPw()
{
	map<string, string> userPw;
	string userName, userpw, userJob;
	ifstream fin;
	fin.open(filename);
	while (fin >> userName >> userpw >> userJob)
	{
		userPw[userName] = userpw;
	}
	return userPw;
}

map<string, job> FileIO::readUsersJob()
{
	map<string, job> jobs;
	string userName, userpw, userJob;
	ifstream fin;
	fin.open(filename);
	while (fin >> userName >> userpw >> userJob)
	{
		if (userJob == "che")
		{
			jobs[userName] = che;
		}
		else if (userJob == "man")
		{
			jobs[userName] = man;
		}
	}
	fin.close();
	return jobs;
}

void FileIO::writeinventoryToFile(vector<string> material, inventory Inventory) {
	ofstream fout;
	fout.open(filename);
	for (int i = 0; i < material.size(); i++) {
		fout << " " << material[i] << " " << Inventory.getInventory(material[i]) << " " << Inventory.getPrice(material[i]) << "\t\n";
	}
	fout.close();
}

void FileIO::writedishToFile(vector<dish> dishlist) {
	ofstream fout;
	fout.open(filename);
	for (int i = 0; i < dishlist.size(); i++) {
		vector<string> materials = dishlist[i].getmaterials();
		fout << dishlist[i].getname() << " " << dishlist[i].getprice();
		for(int j = 0;j<materials.size();j++){
			fout << " " << materials[j];
		}
		fout << endl;
	}
	fout.close();
}
