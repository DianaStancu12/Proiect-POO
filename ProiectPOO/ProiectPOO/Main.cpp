#include <iostream>
#include "Eveniment.h"
#include "LocatieEveniment.h"
#include "Data.h"
#include "Ora.h"

int main()
{
	cout << "*****************  " << endl;
	cout << "*****************  " << endl;
	cout << "The Ticketing App" << endl;
	cout << "=================" << endl;
	cout << "Va rugam sa introduceti urmatoarele date: " << endl;
	cout << "Pentru ce tip de eveniment se va genera biletul?" << endl;
	Eveniment e1;
	string tip;
	tip = e1.getTipEveniment();
	cin >> tip;
	cout << "Cate bilete doriti?"<<endl;
	Eveniment e3;
	double nrB = e3.getNrBilete();
	cin >> nrB; 
	Eveniment e4;
	cout << "Pretul este: "<<endl;
	e4.setPretBilet(15);
	cout << e4.getPretBilet() * nrB << endl;
	LocatieEveniment e5, e6, e7;
	int rand=e5.getRand();
	int nrscaun=e6.getNrScaune();
	string zona = e7.getZona();
	cout << "Doriti un loc la VIP sau unul normal?" << endl;
	cin >> zona;
	if (zona == "VIP")
	{
		rand = 1;
	}
	else rand = 5;
	cout << "Locurile dumneavoastra sunt: " << endl;
	for (int i = 0; i < nrB; i++)
	{
		cout << "Randul:" << rand << "," << "Locul:" << i;
	}

}