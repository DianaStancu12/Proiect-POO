#pragma once
#include <iostream>
#include "Eveniment.h"

using namespace std;

class LocatieEveniment :public Eveniment
{
private:
	int** loc;
	int rand;
	int nr_scaune;
	string zona;
	const int NumarMaximLocuri;
public:
	LocatieEveniment();
	LocatieEveniment(int** loc, int rand, int nr_scaune, string zona, int NumarMaximLocuri);
	LocatieEveniment(const LocatieEveniment& l);
	~LocatieEveniment();
	LocatieEveniment& operator=(const LocatieEveniment& l);
	int** getLoc();
	void setLoc(int** loc, int rand, int nr_scaune);
	int getRand();
	void setRand(int rand);
	int getNrScaune();
	void setNrScaune(int nr_scaune);
	string getZona();
	void setZona(string zona);
	bool operator>(const LocatieEveniment& l);
	bool operator!();
	friend ostream& operator<<(ostream& out, LocatieEveniment l);
	friend istream& operator>>(istream& in, LocatieEveniment& l);
};
