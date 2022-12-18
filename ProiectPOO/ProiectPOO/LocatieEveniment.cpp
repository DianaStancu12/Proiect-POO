#include "LocatieEveniment.h"

LocatieEveniment::LocatieEveniment() :NumarMaximLocuri(100)
{
	loc = nullptr;
	rand = 0;
	nr_scaune = 0;
	zona = "Necunoscuta";
}

LocatieEveniment::LocatieEveniment(int** loc, int rand, int nr_scaune, string zona, int NumarMaximLocuri) : NumarMaximLocuri(NumarMaximLocuri)
{
	if (loc != nullptr && rand > 0 && nr_scaune > 0)
	{
		this->loc = new int*[rand];
		for (int i = 0; i < nr_scaune; i++)
		{
			this->loc[i] = new int[nr_scaune];
		}
		for (int i = 0; i < rand; i++)
		{
			for (int j = 0; j < nr_scaune; j++)
			{
				this->loc[i][j] = loc[i][j];
			}
		}
		this->rand = rand;
		this->nr_scaune = nr_scaune;
	}
	else
	{
		this->loc = nullptr;
		this->rand = 0;
		this->nr_scaune = 0;
	}
	this->zona = zona;
}

LocatieEveniment::LocatieEveniment(const LocatieEveniment& l):NumarMaximLocuri(l.NumarMaximLocuri)
{
	if (l.loc != nullptr && l.rand > 0 && l.nr_scaune > 0)
	{
		this->loc = new int*[l.rand];
		for (int i = 0; i < l.nr_scaune; i++)
		{
			this->loc[i] = new int[l.nr_scaune];
		}
		for (int i = 0; i < l.rand; i++)
		{
			for (int j = 0; j < l.nr_scaune; j++)
			{
				this->loc[i][j] = l.loc[i][j];
			}
		}
		this->rand = l.rand;
		this->nr_scaune = l.nr_scaune;
	}
	else
	{
		this->loc = nullptr;
		this->rand = 0;
		this->nr_scaune = 0;
	}
	this->zona = l.zona;
}

LocatieEveniment::~LocatieEveniment()
{
	if (loc != nullptr)
	{
		for (int i = 0; i < rand; i++)
		{
			delete[] loc[i];
		}
		delete[] loc;
	}
}

LocatieEveniment& LocatieEveniment::operator=(const LocatieEveniment& l)
{
	if (this != &l)
	{
		if (this->loc != nullptr)
		{
			for (int i = 0; i < this->rand; i++)
			{
				delete[] this->loc[i];
			}
			delete[] this->loc;
		}
		if (l.loc != nullptr && l.rand > 0 && l.nr_scaune > 0)
		{
			this->loc = new int*[l.rand];
			for (int i = 0; i < l.nr_scaune; i++)
			{
				this->loc[i] = new int[l.nr_scaune];
			}
			for (int i = 0; i < l.rand; i++)
			{
				for (int j = 0; j < l.nr_scaune; j++)
				{
					this->loc[i][j] = l.loc[i][j];
				}
			}
			this->rand = l.rand;
			this->nr_scaune = l.nr_scaune;
		}
		else
		{
			this->loc = nullptr;
			this->rand = 0;
			this->nr_scaune = 0;
		}
		this->zona = l.zona;
	}
	return *this;
}

int** LocatieEveniment::getLoc()
{
	if (loc != nullptr)
	{
		int** copy = new int*[rand];
		for (int i = 0; i < nr_scaune; i++)
		{
			copy[i] = new int[nr_scaune];
		}
		for (int i = 0; i < rand; i++)
		{
			for (int j = 0; j < nr_scaune; j++)
			{
				copy[i][j] = loc[i][j];
			}
		}
		return copy;
	}
	else return nullptr;
}

void LocatieEveniment::setLoc(int** loc, int rand, int nr_scaune)
{
	if (loc != nullptr && rand>0 && nr_scaune>0)
	{
			for (int i = 0; i < this->rand; i++)
			{
				delete[] this->loc[i];
			}
			delete[] this->loc;

		this->loc = new int*[rand];
		for (int i = 0; i < nr_scaune; i++)
		{
			this->loc[i] = new int[nr_scaune];
		}
		for (int i = 0; i < rand; i++)
		{
			for (int j = 0; j < nr_scaune; j++)
			{
				this->loc[i][j] = loc[i][j];
			}
		}
		this->rand = rand;
		this->nr_scaune = nr_scaune;
	}
}

int LocatieEveniment::getRand()
{
	return rand;
}

void LocatieEveniment::setRand(int rand)
{
	this->rand = rand;
}

int LocatieEveniment::getNrScaune()
{
	return nr_scaune;
}

void LocatieEveniment::setNrScaune(int nr_scaune)
{
	this->nr_scaune = nr_scaune;
}

string LocatieEveniment::getZona()
{
	return zona;
}

void LocatieEveniment::setZona(string zona)
{
	if (this->rand < 5)
	{
		zona = "VIP";
	}
	else zona = "Normal";
}

bool LocatieEveniment::operator>(const LocatieEveniment& l)
{
	if (l.rand * l.nr_scaune > NumarMaximLocuri)
	{
		return false;
	}
	else return true;
}

bool LocatieEveniment::operator!()
{
	return nr_scaune < 10;
}


ostream& operator<<(ostream& out, LocatieEveniment l)
{
	out << "Rand: " << l.rand << endl;
	out << "Numar Scaune: " << l.nr_scaune << endl;
	out << "Zona: " << l.zona << endl;
	out << "Numar Maxim Locuri: " << l.NumarMaximLocuri << endl;
	out << "Loc: ";
	for (int i = 0; i < l.rand; i++)
	{
		for (int j = 0; j < l.nr_scaune; j++)
		{
			out << l.loc[i][j] << " ";
		}
	}
	out << endl;

	return out;
}

istream& operator>>(istream& in, LocatieEveniment& l)
{
	cout << "Rand: ";
	in >> l.rand;
	cout << "Nr Scaune: ";
	in >> l.nr_scaune;
	cout << "Zona: ";
	in >> l.zona;
	if (l.loc != nullptr)
	{
		for (int i = 0; i < l.rand; i++)
		{
			delete[] l.loc[i];
		}
		delete[] l.loc;
		l.loc = nullptr;
	}
	l.loc = new int*[l.rand];
	for (int i = 0; i < l.nr_scaune; i++)
	{
		l.loc[i] = new int[l.nr_scaune];
	}
	cout << "Loc: ";
	for (int i = 0; i < l.rand; i++)
	{
		for (int j = 0; j < l.nr_scaune; j++)
		{
			in >> l.loc[i][j];
		}
	}

	return in;
}
