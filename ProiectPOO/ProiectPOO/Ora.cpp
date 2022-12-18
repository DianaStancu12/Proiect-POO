#include "Ora.h"

	OraEveniment::OraEveniment()
	{
		ora = 0;
		minute = 0;
	}

	OraEveniment::OraEveniment(int ora, int minute)
	{
		this->ora = ora;
		this->minute = minute;
	}

	OraEveniment::OraEveniment(const OraEveniment& o)
	{
		ora = o.ora;
		minute = o.minute;
	}

	OraEveniment& OraEveniment:: operator=(const OraEveniment& o)
	{
		if (this != &o)
		{
			ora = o.ora;
			minute = o.minute;
		}
		return *this;
	}

	bool OraEveniment::oravalida()
	{
		if (ora >= 0 && ora <= 23)
		{
			return true;
		}
		else return false;
	}

	bool OraEveniment::minutvalid()
	{
		if (minute >= 0 && minute <= 59)
		{
			return true;
		}
		else return false;
	}



	ostream& operator<<(ostream& out, OraEveniment o)
	{
			if (o.ora < 10)
			{
				out << "0" << o.ora << ":";
			}
			else out << o.ora << ":";
			if (o.minute < 10)
			{
				out << "0" << o.minute;
			}
		return out;
	}

	istream& operator>>(istream& in, OraEveniment& o)
	{
		cout << "Ora este: ";
		in >> o.ora;
		while (o.oravalida() == false)
		{
			cout << "Ora introdusa nu este valida. Va rugam sa introduceti o ora valida: ";
			in >> o.ora;
		}
		cout << "Minut: ";
		in >> o.minute;
		while (o.minutvalid() == false)
		{
			cout << "Minutul introdus nu este valid. Va rugam sa introduceti un minut valid: ";
			in >> o.minute;
		}
		return in;
	}