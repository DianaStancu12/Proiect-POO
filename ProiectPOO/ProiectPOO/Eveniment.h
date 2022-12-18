#pragma once
#include <iostream>

using namespace std;

class Eveniment
{
private:
	static int NrMaximBilete;
	char TipEveniment[25];
	char* NumeEveniment;
	int NrBilete;
	double PretBilet;
public:
	Eveniment();
	Eveniment(char tip[25], char* nume, int nrBilete, double pret);
	Eveniment(const Eveniment& e);
	~Eveniment();
	Eveniment& operator=(const Eveniment& e);
	string getTipEveniment();
	void setTipEveniment(char tip[25]);
	char* getNumeEveniment();
	void setNumeEveniment(const char* NumeEvenment);
	int getNrBilete();
	void setNrBilete(int bilete);
	double getPretBilet();
	void setPretBilet(double pret);
	void pretCinema(int pret);
	bool operator!();
	void tipEv(int tip);
	friend ostream& operator<<(ostream& out, Eveniment e);
	friend istream& operator>>(istream& in, Eveniment& e);
};