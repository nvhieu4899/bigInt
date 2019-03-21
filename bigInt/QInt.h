#pragma once
#include <string>
#include <climits>
#include <sstream>
#include "_common.h"
using namespace std;
string div2(string x);

class QInt
{
	char arrayBits[128];
public:
	void setBit(int pos, char bit);
	QInt(string value,int radix = 10);
	QInt();
	~QInt();
	//Operator XOR
	QInt operator^(QInt);
	//Operator OR
	QInt operator|(QInt);
	//Operator AND
	QInt operator&(QInt);
	QInt operator~();
	//THIEU TOAN TU NOT ~
	// Operator + - * /
	QInt& operator=(const QInt&);
	QInt operator+(const QInt&);
	QInt operator-(const QInt&);
	QInt operator*(const QInt&);
	QInt operator/(const QInt&);
	QInt operator>>(const int&);
	QInt operator<<(const int&);
	string toBinaryString();
	static string toBinaryString(const QInt&);
	string toDecimalString();
	static string toDecimalString(const QInt&);
	string toHexaString();
	static string toHexaString(const QInt&);
};

