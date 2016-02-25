// Chess17 v1.1 - Dan Nigai

#include "punct.h"
#include "vector.h"
#include "piesa.h"
#include "tabla.h"


Piesa *& Tabla::Piese(Pct p)
{
	return _piese[p.GetX()][p.GetY()];
}


Tabla::Tabla()
{
	_piese[0][0] = new Tura(1, this);
	_piese[0][1] = new Cal(1, this);
	_piese[0][2] = new Nebun(1, this);
	_piese[0][3] = new Regina(1, this);
	_piese[0][4] = new Rege(1, this);
	_piese[0][5] = new Nebun(1, this);
	_piese[0][6] = new Cal(1, this);
	_piese[0][7] = new Tura(1, this);

	for (int j = 0; j < 8; j++)
	{
		_piese[1][j] = new Pion(1, this);
	}

	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			_piese[i][j] = nullptr;
		}
	}

	for (int j = 0; j < 8; j++)
	{
		_piese[6][j] = new Pion(2, this);
	}

	_piese[7][0] = new Tura(2, this);
	_piese[7][1] = new Cal(2, this);
	_piese[7][2] = new Nebun(2, this);
	_piese[7][3] = new Regina(2, this);
	_piese[7][4] = new Rege(2, this);
	_piese[7][5] = new Nebun(2, this);
	_piese[7][6] = new Cal(2, this);
	_piese[7][7] = new Tura(2, this);

}

	//TO DO: constructor copiere

	//TO DO: constructor copiere + mutare_piesa

Tabla::~Tabla()
{
	int del = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (_piese[i][j] != nullptr)		
			{
				delete _piese[i][j];
				_piese[i][j] = nullptr;
				del++;
			}
		}
	}

	cout << "\n   "<< del <<" piese au fost sterse.\n";
}


int Tabla::GetRunda() const
{
	return _runda;
}

int Tabla::IncRunda()
{
	_runda++;
	return _runda;
}


int Tabla::GetJucator() const
{
	return ((_runda + 1) % 2) + 1;
}

int Tabla::GetCuloareJucator() const
{
	return GetJucator()-1 ? 11 : 12;
}


int Tabla::GetEchipaPiesa(int a, int b) const
{
	if (_piese[a][b] != nullptr)
	{
		return _piese[a][b]->GetEchipa();
	}
	else
	{
		return 0;
	}
}

int Tabla::GetEchipaPiesa(Pct p) const
{
	return GetEchipaPiesa(p.GetX(), p.GetY());
}

bool Tabla::GetSpatiuGol(Pct p) const
{
	return _piese[p.GetX()][p.GetY()] == nullptr;
}


int Tabla::GetCuloarePiesa(int a, int b, int s) const
{
	switch (GetEchipaPiesa(a, b))
	{
	case 0:
		return s ? GetCuloareJucator()-8 : 0;
	case 1:
		return s ? 4 : 12;
	case 2:
		return s ? 3 : 11;
	default:
		return 14;
	}

	return 13;
}

int Tabla::GetCuloarePatrat(int a, int b, int s) const
{
	return (a + b + 1) % 2 ? 8 : 15;
}

char Tabla::GetSimbol(int a, int b) const
{
	if (a < 0 || a > 7)
		return 73;

	if (b < 0 || b > 7)
		return 74;

	if (_piese[a][b] == nullptr)
		return 120;

	return _piese[a][b]->GetSimbol();
}


int Tabla::GetNrPiese() const
{
	int sum = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (!GetSpatiuGol(Pct(i, j)))
			{
				sum++;
			}
		}
	}

	return sum;
}

int Tabla::GetCost() const
{
	int sum = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (!GetSpatiuGol(Pct(i, j)))
			{
				sum += _piese[i][j]->GetCost() * (GetEchipaPiesa(Pct(i, j)) == 1 ? 1 : -1);
			}
		}
	}

	return sum;
}


bool Tabla::SahMat(int jucator) const
{
	return 0;	//TO DO: verificari, etc
}


bool Tabla::VerificPiesa(Pct p)
{
	bool k = false;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (VerificMutare(Vector(p, Pct(i, j))))
			{
				k = true;
			}
		}
	}

	return k;
}


bool Tabla::VerificMutare(Pct const & src, Pct const & dst)
{
	return VerificMutare(Vector(src, dst));
}

bool Tabla::VerificMutare(Vector const & vec)
{
	if (!vec.Valid())
		return false;

	if (GetEchipaPiesa(vec.GetSrc()) != GetJucator() || GetSpatiuGol(vec.GetSrc()))		// piesele mele
		return false;

	if (GetEchipaPiesa(vec.GetSrc()) == GetEchipaPiesa(vec.GetDst()))		// nu atac piesele mele
		return false;

	if (vec.GetSrc() == vec.GetDst())										// are loc mutare
		return false;

	return (Piese(vec.GetSrc())->VerifMutare(vec));

	//TO DO: verificari extra pt rocada, en passent, etc
}


void Tabla::AplicMutare(Pct const & src, Pct const & dst)
{
	AplicMutare(Vector(src, dst));
}

void Tabla::AplicMutare(Vector const & vec)
{
	cout << "\nMutare: " << vec;

	Piesa *x = Piese(vec.GetDst());
	Piese(vec.GetDst()) = Piese(vec.GetSrc());
	Piese(vec.GetSrc()) = x;

	if (GetEchipaPiesa(vec.GetSrc()) != GetEchipaPiesa(vec.GetDst()) && !GetSpatiuGol(vec.GetSrc()) && !GetSpatiuGol(vec.GetDst()))
	{
		delete Piese(vec.GetSrc());
		Piese(vec.GetSrc()) = nullptr;
	}

	if (!GetSpatiuGol(vec.GetSrc()))
		Piese(vec.GetSrc())->SetMutat();

	if (!GetSpatiuGol(vec.GetDst()))
		Piese(vec.GetDst())->SetMutat();

}
