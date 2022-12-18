#pragma once
#include<iostream>

using namespace std;

class DataEveniment
{
private:
	int zi;
	int luna;
	int an;
public:
	DataEveniment();
	DataEveniment(int zi, int luna, int an);
	DataEveniment(const DataEveniment& d);
	DataEveniment& operator=(const DataEveniment& d);
	int getZi();
	void setZi(int z);
	int getLuna();
	void setLuna(int l);
	int getAn();
	void setAn(int a);
	bool anbisect(int an);
	bool verificare();
	friend ostream& operator<<(ostream& out, DataEveniment& d);
	friend istream& operator>>(istream& in, DataEveniment& d);
};