#include "_file.h"



_file::_file()
{
}


_file::~_file()
{
}
string _file::lineProcess(string line)
{
	stringstream s(line, ios::in);

	if (line.find("-") != line.npos && line[line.find("-") - 1] == ' ' && line[line.find("-") + 1] == ' ')//Dieu kien - vai tro la toan tu
	{
		int radix;
		s >> radix;
		string t1, t2;
		s >> t1;
		s.ignore(2);
		s >> t2;
		QInt x(t1, radix);
		QInt y(t2, radix);
		return (x - y).toString(radix);
	}
	if (line.find("~") != line.npos)
	{
		int radix;
		s >> radix;
		s.ignore(2);
		string t1;
		s >> t1;
		QInt x(t1, radix);
		return x.NOT().toString(radix);
	}
	if (line.find("+") != line.npos)
	{
		int radix;
		s >> radix;
		string t1, t2;
		s >> t1;
		s.ignore(2);
		s >> t2;
		QInt x(t1, radix);
		QInt y(t2, radix);
		return (x + y).toString(radix);
	}

	if (line.find("*") != line.npos)
	{
		return "nhan";
	}
	if (line.find("/") != line.npos)
	{
		return "chia";
	}

	if (line.find(">>") != line.npos)
	{
		int radix;
		s >> radix;
		string t1;
		s >> t1;
		s.ignore(3);
		int y;
		s >> y;
		QInt x(t1, radix);
		return (x >> y).toString(radix);
	}
	if (line.find("<<") != line.npos)
	{
		int radix;
		s >> radix;
		string t1;
		s >> t1;
		s.ignore(3);
		int y;
		s >> y;
		QInt x(t1, radix);
		return (x << y).toString(radix);
	}
	if (line.find("ror") != line.npos)
	{
		int radix;
		s >> radix;
		s.ignore(4);
		string t1;
		s >> t1;
		QInt x(t1, radix);
		return x.ror().toString(radix);
	}
	if (line.find("rol") != line.npos)
	{
		int radix;
		s >> radix;
		s.ignore(4);
		string t1;
		s >> t1;
		QInt x(t1, radix);
		return x.rol().toString(radix);
	}
	if (line.find("^") != line.npos)
	{
		int radix;
		s >> radix;
		string t1, t2;
		s >> t1;
		s.ignore(2);
		s >> t2;
		QInt x(t1, radix);
		QInt y(t2, radix);
		return (x ^ y).toString(radix);
	}	
	if (line.find("&") != line.npos)
	{
		int radix;
		s >> radix;
		string t1, t2;
		s >> t1;
		s.ignore(2);
		s >> t2;
		QInt x(t1, radix);
		QInt y(t2, radix);
		return (x & y).toString(radix);
	}
	if (line.find("|") != line.npos)
	{
		int radix;
		s >> radix;
		string t1, t2;
		s >> t1;
		s.ignore(2);
		s >> t2;
		QInt x(t1, radix);
		QInt y(t2, radix);
		return (x | y).toString(radix);
	}

	//Truong hop yeu cau chuyen co so
	string temp1;
	int radix1, radix2;
	s >> radix1 >> radix2 >> temp1;
	QInt x(temp1, radix1);
	return x.toString(radix2);
}