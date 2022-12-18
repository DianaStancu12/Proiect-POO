#include "Eveniment.h";
int Eveniment::NrMaximBilete = 100;
Eveniment::Eveniment()
{
	strcpy_s(TipEveniment, 11, "Necunoscut");
	NumeEveniment = nullptr;
	NrBilete = 0;
	PretBilet = 15;
}
Eveniment::Eveniment(char tip[25], char* nume, int nrBilete, double pret)
{
	strcpy_s(this->TipEveniment, strlen(tip) + 1, tip);
	this->NrBilete = nrBilete;
	this->PretBilet = pret;
	if (nume != nullptr)
	{
		this->NumeEveniment = new char[strlen(nume) + 1];
		strcpy_s(this->NumeEveniment, strlen(nume) + 1, nume);
	}
}

Eveniment::Eveniment(const Eveniment& e)
{
	strcpy_s(this->TipEveniment, strlen(e.TipEveniment) + 1, e.TipEveniment);
	if (e.NumeEveniment != nullptr)
	{
		this->NumeEveniment = new char[strlen(e.NumeEveniment) + 1];
		strcpy_s(this->NumeEveniment, strlen(e.NumeEveniment) + 1, e.NumeEveniment);
	}
	this->NrBilete = e.NrBilete;
	this->PretBilet = e.PretBilet;
}

Eveniment::~Eveniment()
{
	if (NumeEveniment != nullptr)
	{
		delete[] NumeEveniment;
	}
}

Eveniment& Eveniment:: operator=(const Eveniment& e)
{
	if (this != &e)
	{
		strcpy_s(this->TipEveniment, strlen(e.TipEveniment) + 1, e.TipEveniment);
		if (NumeEveniment != nullptr)
		{
			this->NumeEveniment = new char[strlen(e.NumeEveniment) + 1];
			strcpy_s(this->NumeEveniment, strlen(e.NumeEveniment) + 1, e.NumeEveniment);
		}
		this->NrBilete = e.NrBilete;
		this->PretBilet = e.PretBilet;
	}
	return *this;
}

string Eveniment::getTipEveniment()
{
	return TipEveniment;
}

void Eveniment::setTipEveniment(char tip[25])
{
	strcpy_s(TipEveniment, strlen(tip) + 1, tip);
}

char* Eveniment::getNumeEveniment()
{
	if (NumeEveniment != nullptr)
	{
		char* copy = new char[strlen(NumeEveniment) + 1];
		strcpy_s(copy, strlen(NumeEveniment) + 1, NumeEveniment);
		return copy;
	}
	return nullptr;
}

void Eveniment::setNumeEveniment(const char* NumeEvenment)
{
	if (NumeEveniment != nullptr)
	{
		if (this->NumeEveniment != nullptr)
		{
			delete[] this->NumeEveniment;
		}
		this->NumeEveniment = new char[strlen(NumeEveniment) + 1];
		strcpy_s(this->NumeEveniment, strlen(NumeEveniment) + 1, NumeEveniment);
	}
}

int Eveniment::getNrBilete()
{
	return NrBilete;
}

void Eveniment::setNrBilete(int bilete)
{
	NrBilete = bilete;
}

double Eveniment::getPretBilet()
{
	return PretBilet;
}

void Eveniment::setPretBilet(double pret)
{
	PretBilet = pret;
}

void Eveniment::pretCinema(int pret)
{
	if(TipEveniment=="Film")
	PretBilet += pret;
}

void Eveniment::tipEv(int tip)
{
	cout<<tip;
}

bool Eveniment::operator!()
{
	return TipEveniment == "Film";
}

ostream& operator<<(ostream& out, Eveniment e)
{
	out << "Tip Eveniment: " << e.TipEveniment << endl;
	out << "Nume Eveniment: ";
	if (e.NumeEveniment != nullptr)
	{
		out << e.NumeEveniment << endl;
	}
	out << "Nr Bilete: " << e.NrBilete << endl;
	out << "Pret Bilet: " << e.PretBilet << endl;
	return out;
}

istream& operator>>(istream& in, Eveniment& e)
{
	cout << "Tip Eveniment: ";
	in >> e.TipEveniment;
	if (e.NumeEveniment != nullptr)
	{
		delete[] e.NumeEveniment;
	}
	cout << "Nume Eveniment: ";
	string buffer;
	in >> buffer;
	e.NumeEveniment = new char[strlen(buffer.c_str()) + 1];
	strcpy_s(e.NumeEveniment, strlen(buffer.c_str()) + 1, buffer.c_str());

	cout << "Nr Bilete: ";
	in >> e.NrBilete;
	cout << "Pret Bilet: ";
	in >> e.PretBilet;
	return in;
}