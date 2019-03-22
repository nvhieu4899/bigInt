#include "QInt.h"

QInt::QInt()
{
	for (int i = 0; i < 128; i++)
	{
		arrayBits[i] = 0;
	}
}


QInt::~QInt()
{
}
QInt::QInt(string value,int radix)
{
	for (int i = 0; i < 128; i++)
	{
		arrayBits[i] = 0;
	}
	if (radix == 10) {
		int len = value.length() - 1;
		int i = 127;
		if (value[0] != '-')
		{
			while (!value.empty())
			{
				char bit = (value[value.length()-1] - 48) % 2;
				this->setBit(i, bit);
				value = _common::div2(value);
				i--;
			}
		}
		else
		{
			value.erase(0, 1);
			while (!value.empty())
			{
				char bit = (value[value.length()-1] - 48) % 2;
				this->setBit(i, bit);
				value = _common::div2(value);
				i--;
			}
			//CHuyen sang dang bu 1
			for (int i = 0; i < 128; i++)
			{
				this->setBit(i, 1 - arrayBits[i]);
			}
			//Chuyen tu bu 1 sang bu 2
			int nho = 1;
			for (int i = 127; i >= 0; i--)
			{
				int res = arrayBits[i] + nho;
				arrayBits[i] = res % 2;
				nho = res / 2;
			}
		}
	}
	if (radix == 2)
	{
		int j = 127;
		for (int i = value.length() - 1; i >= 0; i--)
		{
			arrayBits[j--] = value[i] - 48;
		}
	}
	if (radix == 16)
	{
		int j = 127;
		for (int i = value.length() - 1; i >= 0; i--)
		{
			switch (value[i])
			{
			case '0':
				arrayBits[j--] = 0;
				arrayBits[j--] = 0;
				arrayBits[j--] = 0;
				arrayBits[j--] = 0;
				break;
			case '1':
				arrayBits[j--] = 1;
				arrayBits[j--] = 0;
				arrayBits[j--] = 0;
				arrayBits[j--] = 0;
				break;
			case '2':
				arrayBits[j--] = 0;
				arrayBits[j--] = 1;
				arrayBits[j--] = 0;
				arrayBits[j--] = 0;
				break;
			case '3':
				arrayBits[j--] = 1;
				arrayBits[j--] = 1;
				arrayBits[j--] = 0;
				arrayBits[j--] = 0;
				break;
			case '4':
				arrayBits[j--] = 0;
				arrayBits[j--] = 0;
				arrayBits[j--] = 1;
				arrayBits[j--] = 0;
				break;
			case '5':
				arrayBits[j--] = 1;
				arrayBits[j--] = 0;
				arrayBits[j--] = 1;
				arrayBits[j--] = 0;
				break;
			case '6':
				arrayBits[j--] = 0;
				arrayBits[j--] = 1;
				arrayBits[j--] = 1;
				arrayBits[j--] = 0;
				break;
			case '7':
				arrayBits[j--] = 1;
				arrayBits[j--] = 1;
				arrayBits[j--] = 1;
				arrayBits[j--] = 0;
				break;
			case '8':
				arrayBits[j--] = 0;
				arrayBits[j--] = 0;
				arrayBits[j--] = 0;
				arrayBits[j--] = 1;
				break;
			case '9':
				arrayBits[j--] = 1;
				arrayBits[j--] = 0;
				arrayBits[j--] = 0;
				arrayBits[j--] = 1;
				break;
			case 'A':
				arrayBits[j--] = 0;
				arrayBits[j--] = 1;
				arrayBits[j--] = 0;
				arrayBits[j--] = 1;
				break;
			case 'B':
				arrayBits[j--] = 1;
				arrayBits[j--] = 1;
				arrayBits[j--] = 0;
				arrayBits[j--] = 1;
				break;
			case 'C':
				arrayBits[j--] = 0;
				arrayBits[j--] = 0;
				arrayBits[j--] = 1;
				arrayBits[j--] = 1;
				break;
			case 'D':
				arrayBits[j--] = 1;
				arrayBits[j--] = 0;
				arrayBits[j--] = 1;
				arrayBits[j--] = 1;
				break;
			case 'E':
				arrayBits[j--] = 0;
				arrayBits[j--] = 1;
				arrayBits[j--] = 1;
				arrayBits[j--] = 1;
				break;
			case 'F':
				arrayBits[j--] = 1;
				arrayBits[j--] = 1;
				arrayBits[j--] = 1;
				arrayBits[j--] = 1;
				break;

			}
		}
	}
}
void QInt::setBit(int pos, char bit)
{
	arrayBits[pos] = bit;
}
QInt QInt::operator^(QInt a)
{
	QInt res;
	for (int i = 0; i < 128; i++)
	{
		res.arrayBits[i] = this->arrayBits[i] ^ a.arrayBits[i];
	}
	return res;
}
QInt QInt::operator|(QInt a)
{
	QInt res;
	for (int i = 0; i < 128; i++)
	{
		res.arrayBits[i] = this->arrayBits[i] | a.arrayBits[i];
	}
	return res;
}
QInt QInt::operator&(QInt a)
{
	QInt res;
	for (int i = 0; i < 128; i++)
	{
		res.arrayBits[i] = this->arrayBits[i] & a.arrayBits[i];
	}
	return res;
}
QInt& QInt::operator=(const QInt& a)
{
	for (int i = 0; i < 128; i++)
	{
		this->arrayBits[i] = a.arrayBits[i];
	}
	return *this;
}
string QInt::toBinaryString()
{
	stringstream res;
	if (arrayBits[0] == 1)
	{
		for (int i = 0; i < 128; i++)
		{
			res << (char)(arrayBits[i] + 48);
		}
	}
	else
	{
		int i = 0;
		for (; i < 128; i++)
		{
			if (this->arrayBits[i] == 1)
			break;
		}
		
		for (; i < 128; i++)
		{
			res << (char)(arrayBits[i] + 48);
		}
	}
	return res.str();
}
QInt QInt::operator~()
{
	QInt res;
	for (int i = 0; i < 128; i++)
	{
		res.arrayBits[i] = 1 - this->arrayBits[i];
	}
	return res;
}
string QInt::toBinaryString(const QInt& a)
{
	stringstream res;
	if (a.arrayBits[0] == 1)
	{
		for (int i = 0; i < 128; i++)
		{
			res<<(char)(a.arrayBits[i] + 48);
		}
	}
	else
	{
		res << "0";
		int i = 0;
		for (; i < 128; i++)
		{
			if (a.arrayBits[i] == 1) break;
		}
		for (; i < 128; i++)
		{
			res<<(char)(a.arrayBits[i] + 48);
		}
	}
	return res.str();
}
string QInt::toHexaString()
{
	string res;
	char kitu[16] = { '0','1' ,'2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	for (int i = 0; i < 128; i += 4)
	{
		int dem = arrayBits[i+0]*8+arrayBits[i+1]*4+arrayBits[i+2]*2+arrayBits[i+3];
		//res.append((const char*)kitu[dem]);
		res.insert(res.end(), kitu[dem]);
	}
	while (res[0] == '0')
	{
		res.erase(0, 1);
	}
	return res;
}
string QInt::toHexaString(const QInt& a)
{
	string res;
	char kitu[16] = { '0','1' ,'2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	int i = 0;
	for (int i = 0; i < 128; i += 4)
	{
		int dem = a.arrayBits[i + 0] * 8 + a.arrayBits[i + 1] * 4 + a.arrayBits[i + 2] * 2 + a.arrayBits[i + 3];
		res.insert(res.end(), kitu[dem]);

	}
	while (res[0] == '0')
	{
		res.erase(0, 1);
	}
	return res;
}
QInt QInt::operator+(const QInt& a)
{
	int nho = 0;
	for (int i = 127; i >= 0; i--)
	{
		int res = (this->arrayBits[i] + nho + a.arrayBits[i]);
		nho = res / 2;
		this->arrayBits[i] = res % 2;
	}
	return *this;
}
