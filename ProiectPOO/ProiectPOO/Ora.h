#pragma once
#include<iostream>

using namespace std;

class OraEveniment
{
private:
	int ora;
	int minute;
public:
	OraEveniment();
	OraEveniment(int ora, int minute);
	OraEveniment(const OraEveniment& o);
	OraEveniment& operator=(const OraEveniment& o);
	bool oravalida();
	bool minutvalid();
	friend ostream& operator<<(ostream& out, OraEveniment o);
	friend istream& operator>>(istream& in, OraEveniment& o);
};
