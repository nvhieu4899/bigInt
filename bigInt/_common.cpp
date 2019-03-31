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
	string res;
	//2 so duong
	if (a[0]!='-'&&b[0]!='-') {
		int lenA = a.length() - 1;
		int lenB = b.length() - 1;
		int nho = 0;
		while (lenA >= 0 && lenB >= 0)
		{
			int temp = a[lenA] - 48 + b[lenB] - 48 + nho;
			res.insert(res.begin(), (char)(temp % 10 + 48));
			nho = temp / 10;
			lenA--;
			lenB--;
		}
		while (lenA < 0 && lenB >= 0)
		{
			int temp = b[lenB] - 48 + nho;
			res.insert(res.begin(), (char)(temp % 10 + 48));
			nho = temp / 10;
			lenB--;
		}
		while (lenB < 0 && lenA >= 0)
		{
			int temp = a[lenA] - 48 + nho;
			res.insert(res.begin(), (char)(temp % 10 + 48));
			nho = temp / 10;
			lenA--;
		}
		if (lenA < 0 && lenB < 0 && nho != 0)
		{
			res.insert(res.begin(), (char)(nho + 48));
		}
	}
	//2 so am
	if (a[0] == '-'&&b[0] == '-')
	{
		
		int nho = 0;
		a.erase(0, 1);
		b.erase(0, 1);
		int lenA = a.length() - 1;
		int lenB = b.length() - 1;
		while (lenA >= 0 && lenB >= 0)
		{
			int temp = a[lenA] - 48 + b[lenB] - 48 + nho;
			res.insert(res.begin(), (char)(temp % 10 + 48));
			nho = temp / 10;
			lenA--;
			lenB--;
		}
		while (lenA < 0 && lenB >= 0)
		{
			int temp = b[lenB] - 48 + nho;
			res.insert(res.begin(), (char)(temp % 10 + 48));
			nho = temp / 10;
			lenB--;
		}
		while (lenB < 0 && lenA >= 0)
		{
			int temp = a[lenA] - 48 + nho;
			res.insert(res.begin(), (char)(temp % 10 + 48));
			nho = temp / 10;
			lenA--;
		}
		if (lenA < 0 && lenB < 0 && nho != 0)
		{
			res.insert(res.begin(), (char)(nho + 48));
		}
		res.insert(res.begin(), '-');
	}
	//1 so am, mot so duong
	{
		if (_common::compareStr10(a, "0") == 1 && _common::compareStr10(b, "0") == -1)
		{
			b.erase(0, 1);
			return _common::subStr10(a, b);
		}
		if (_common::compareStr10(a, "0") == -1 && _common::compareStr10(b, "0") == 1)
		{
			a.erase(0, 1);
			return _common::subStr10(b, a);
		}
	}
	return res;
}
string _common::absStr10(string a)
{
	string res = a;
	if (a[0] == '-')
		res.erase(0, 1);
	return res;
}
string _common::subStr10(string a, string b)
{
	string res;
	int muon = 0;
	if (_common::compareStr10(a, b) == 0) return "0";
	if (_common::compareStr10(a,b) == 1 && _common::compareStr10(b, "0") == 1)
	{
		int lenA = a.length() - 1;
		int lenB = b.length() - 1;
		while (lenA >= 0&&lenB>=0)
		{
			int temp = a[lenA] - 48 + muon;
			muon = 0;
			if (temp - (b[lenB]-48) < 0)
			{
				muon = -1;
				temp += 10;
			}
			res.insert(res.begin(), (char)(temp - (b[lenB]-48) + 48));
			lenB--;
			lenA--;
		}
		while (lenA >= 0)
		{
			int temp = a[lenA] - 48 + muon;
			muon = 0;
			if (temp < 0)
			{
				muon = -1;
				temp += 10;
			}
			res.insert(res.begin(), (char)(temp % 10 + 48));
			lenA--;
		}
		while (res[0] == '0') res.erase(0, 1);
	}
	if (_common::compareStr10(a, b) == -1 && _common::compareStr10(a, "0") == -1)
	{
		a.erase(0, 1);
		b.erase(0, 1);
		return "-" + subStr10(a, b);
	}
	if (_common::compareStr10(a, "0") == 1 && _common::compareStr10(b, "0") == -1)
	{
		b.erase(0, 1);
		return _common::addStr10(a, b);
	}
	if (_common::compareStr10(a, "0") == -1 && _common::compareStr10(b, "0") == 1)
	{
		a.erase(0, 1);
		return "-"+_common::addStr10(a, b);
	}
	if (_common::compareStr10(a, b) == -1 && _common::compareStr10(a, "0") == 1)
	{
		return "-" + subStr10(b, a);
	}
	return res;
}
int _common::compareStr10(string a, string b)
{
	if (a[0] == '-'&&b[0] != '-')
	{
		return -1;
	}
	if (a == b) return 0;
	if (a[0] != '-' && b[0] == '-')
		return 1;
	if (a[0] != '-'&&b[0] != '-')
	{
		if (a.length() > b.length()) return 1;
		else if (a.length() < b.length()) return -1;
		else
		{
			for (int i = 0; i < a.length(); i++)
			{
				if (a[i] < b[i]) return -1;
				else if (a[i] > b[i]) return 1;
			}
		}
	}
	if (a[0] == '-'&&b[0] == '-')
	{
		a.erase(0, 1);
		b.erase(0, 1);
		return -_common::compareStr10(a, b);
	}
	return 0;
}
string _common::mult2Str10(string a)
{
	return _common::addStr10(a, a);
}
string _common::pow2(int exp)
{
	string res = "1";
	for (int i = 0; i < exp; i++)
	{
		res = _common::mult2Str10(res);
	}
	return res;
}