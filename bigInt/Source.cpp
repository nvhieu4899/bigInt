#include <iostream>
#include "QInt.h"
#include "_file.h"
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	fstream fin((const char*)argv[1], ios::in);
	fstream fout((const char*)argv[2], ios::out);
	string temp;
	while (!fin.eof())
	{
		getline(fin, temp);
		fout << _file::lineProcess(temp) << endl;
	}
	fin.close();
	fout.close();
}