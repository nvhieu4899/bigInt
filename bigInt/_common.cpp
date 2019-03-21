#include "_common.h"



_common::_common()
{

}


_common::~_common()
{
}
string _common::div2(string str)
{
	string res;
	unsigned short int i = 0, j = 0, k = 0;
	if (str == "1") return "0";
	res.resize(str.length());
	if (str[0] - 48 < 2)
	{
		i = 1; j = 10;
	}
	for (; i < str.length(); i++)
	{
		res[k++] = ((str[i] - 48 + j) / 2 + 48);
		j = ((str[i] - 48 + j) % 2) * 10;
	}
	res.resize(k);
	return res;
}
string _common::addStr10(string a, string b)
{
	int lenA = a.length() - 1;
	int lenB = b.length() - 1;
	string res;
}