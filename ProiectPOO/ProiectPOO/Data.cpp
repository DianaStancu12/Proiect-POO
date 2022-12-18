#include "Data.h"

DataEveniment::DataEveniment()
{
	zi = 0;
	luna = 0;
	an = 0;
}

DataEveniment::DataEveniment(int zi, int luna, int an)
{
	this->zi = zi;
	this->luna = luna;
	this->an = an;
}

DataEveniment::DataEveniment(const DataEveniment& d)
{
	zi = d.zi;
	luna = d.luna;
	an = d.an;
}

DataEveniment& DataEveniment:: operator=(const DataEveniment& d)
{
	if (this != &d)
	{
		zi = d.zi;
		luna = d.luna;
		an = d.an;
	}
	return *this;
}

int DataEveniment::getZi()
{
	return zi;
}

void DataEveniment::setZi(int z)
{
	if (luna == 2)
	{
		if (DataEveniment::anbisect(an))
		{
			if (zi <= 28)
				zi = z;
		}
		else if (zi <= 29)
			zi = z;
	}
	if (z >= 1 && z <= 31)
	{
		zi = z;
	}
}

int DataEveniment::getLuna()
{
	return luna;
}

void DataEveniment::setLuna(int l)
{
	if (l >= 1 && l <= 12)
	{
		luna = l;
	}
}

int DataEveniment::getAn()
{
	return an;
}

void DataEveniment::setAn(int a)
{
	if (a > 0)
	{
		an = a;
	}
}

bool DataEveniment::anbisect(int an)
{
	if (an % 4 == 0) return true;
	else return false;
}

bool DataEveniment::verificare()
{
	if (zi == 0 || luna == 0 || an == 0)
	{
		return false;
	}
	else return true;
}


ostream& operator<<(ostream& out, DataEveniment& d)
{
	out << d.zi << "." << d.luna << "." << d.an;
	return out;
}

istream& operator>>(istream& in, DataEveniment& d)
{
	cout << "Anul: ";
	in >> d.an;
	if (d.an < 0)
	{
		cout << "Anul trebuie sa fie un numar pozitiv, mai mare decat 0. Va rugam sa introduceti un an valid: ";
		in >> d.an;
	}

	cout << "Luna: ";
	in >> d.luna;
	if (d.luna < 1 && d.luna>12)
	{
		cout << "Luna trebuie sa fie un numar intre 1 si 12. Va rugam sa introduceti o luna valida: ";
		in >> d.luna;
	}
	if (d.anbisect(d.an))
	{
		if (d.luna == 2 && d.zi > 28)
			cout << "Anul introdus este an bisect. Intr-un an bisect, luna februarie nu poate avea mai mult de 28 de zile. Va rugam introduceti o zi valida: ";
		in >> d.zi;
	}
	else if (d.luna == 2 && d.zi > 29)
	{
		cout << "Luna februarie nu poate avea mai mult de 29 de zile. Va rugam introduceti o zi valida: ";
		in >> d.zi;
	}
	else if (d.luna == 1 || d.luna == 3 || d.luna == 5 || d.luna == 8 || d.luna == 10 || d.luna == 12)
	{
		cout << "Zi: ";
		in >> d.zi;
		if (d.zi < 1 && d.zi>31)
		{
			cout << "Ziua trebuie sa fie un numar intre 1 si 31. Va rugam introduceti o zi valida: ";
			in >> d.zi;
		}
	}
	else if (d.luna == 4 || d.luna == 6 || d.luna == 9 || d.luna == 11)
	{
		cout << "Zi: ";
		in >> d.zi;
		if (d.zi < 1 && d.zi>30)
		{
			cout << "Ziua trebuie sa fie un numar intre 1 si 30. Va rugam introduceti o zi valida: ";
			in >> d.zi;
		}
	}
	return in;
}
