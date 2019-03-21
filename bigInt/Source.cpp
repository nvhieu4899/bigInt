#include <iostream>
#include "QInt.h"
using namespace std;


int main(int argc, char* argv[])
{
	QInt a("-1", 10);
	cout << a.toBinaryString()<<endl;
	
	system("pause");
}