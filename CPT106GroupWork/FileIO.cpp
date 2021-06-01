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
