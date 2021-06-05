#include "FileIO.h"

FileIO::FileIO(string name)
{
	this->filename = name;
}

ifstream FileIO::readAllStream()
{
	ifstream fin;
	fin.unsetf(ios::skipws);
	fin.open(filename, ios::in);
	fin.close();
	return fin;
}

vector<dish> FileIO::readdish(inventory totalinventory) {
	ifstream fin;
	vector<dish> readdish;
	vector<string> materials;
	string name, material;
	double price;
	fin.open(filename);
	fin._Seekbeg();
	while (fin >> name >> price) {
		while (fin.get() != '\n') {
			fin >> material;
			materials.push_back(material);
		}
		dish newdish(name, materials, totalinventory, price);
		readdish.push_back(newdish);
	}
	return readdish;
}

void FileIO::writeinventoryToFile(vector<string> material, inventory Inventory) {
	ofstream fout;
	fout.open(filename);
	fout << "materials " << "Inventory " << "price " << endl;
	for (int i = 0; i < material.size(); i++) {
		fout << material[i] << " " << Inventory.getInventory(material[i]) << " " << Inventory.getPrice(material[i]) <<"\t\n";
	}
	fout.close();
}

void FileIO::writedishToFile(vector<dish> dishlist) {
	ofstream fout;
	fout.open(filename);
	fout << "Dish price materials\n";
	for (int i = 0; i < dishlist.size(); i++) {
		vector<string> materials = dishlist[i].getmaterials();
		fout << dishlist[i].getname() << dishlist[i].getprice();
		for(int j = 0;j<materials.size();j++){
			fout << materials[i] << " ";
		}
		fout << endl;
	}
	fout.close();
}