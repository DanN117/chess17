// Chess17 v1.1 - Dan Nigai

#include "punct.h"
#include "vector.h"
#include "tabla.h"
#include "piesa.h"


Piesa::Piesa(int ech, Tabla * tab) : _echipa(ech), _tab(tab)
{
}

Piesa::~Piesa()
{
}


int Piesa::GetEchipa() const
{
	return _echipa;
}


bool Piesa::GetMutat() const
{
	return _mutat;
}

void Piesa::SetMutat()
{
	_mutat = true;
}

void Piesa::ResetMutat()
{
	_mutat = false;
}



Pion::Pion(int ech, Tabla * tab) : Piesa(ech, tab)
{
}

Pion::~Pion()
{
}


bool Pion::VerifMutare(Pct const & src, Pct const & dst) const
{
	return VerifMutare(Vector(src, dst));
}

bool Pion::VerifMutare(Vector const & vec) const
{
	if (GetEchipa() == 1 && vec.GetVX() < 0 || GetEchipa() == 2 && vec.GetVX() > 0)	//verificare directie
		return false;
	
	if (_tab->GetEchipaPiesa(vec.GetDst()) == 0)	//mutare
		return vec.GetVYabs() == 0 && (vec.GetVXabs() == 1 || (vec.GetVXabs() == 2 && !GetMutat() && _tab->GetEchipaPiesa(vec.GetSrc() + vec.GetVdir()) == 0));
								
	if (_tab->GetEchipaPiesa(vec.GetDst()) != GetEchipa())	//capturare
		return vec.GetVYabs() == 1 && vec.GetVXabs() == 1;

	//TO DO: en passant

	return false;
}


char Pion::GetSimbol() const
{
	return _rend;
}

int Pion::GetCost() const
{
	return _cost;
}



Cal::Cal(int ech, Tabla * tab) : Piesa(ech, tab)
{
}

Cal::~Cal()
{
}


bool Cal::VerifMutare(Pct const & src, Pct const & dst) const
{
	return VerifMutare(Vector(src, dst));
}

bool Cal::VerifMutare(Vector const & vec) const
{
	return (vec.GetVXabs() * vec.GetVYabs() == 2) && (vec.GetVXabs() + vec.GetVYabs() == 3);
}


char Cal::GetSimbol() const
{
	return _rend;
}

int Cal::GetCost() const
{
	return _cost;
}



Tura::Tura(int ech, Tabla * tab) : Piesa(ech, tab)
{
}

Tura::~Tura()
{
}


bool Tura::VerifMutare(Pct const & src, Pct const & dst) const
{
	return VerifMutare(Vector(src, dst));
}

bool Tura::VerifMutare(Vector const & vec) const
{
	if ((vec.GetVX() != 0) && (vec.GetVY() != 0))
	{
		return false;
	}

	for (Pct i = vec.GetSrc() + vec.GetVdir(); i != vec.GetDst(); i = i + vec.GetVdir())
	{
		if (!_tab->GetSpatiuGol(i))
			return false;
	}

	return true;
}


char Tura::GetSimbol() const
{
	return _rend;
}

int Tura::GetCost() const
{
	return _cost;
}



Nebun::Nebun(int ech, Tabla * tab) : Piesa(ech, tab)
{
}

Nebun::~Nebun()
{
}


bool Nebun::VerifMutare(Pct const & src, Pct const & dst) const
{
	return VerifMutare(Vector(src, dst));
}

bool Nebun::VerifMutare(Vector const & vec) const
{
	if (vec.GetVXabs() != vec.GetVYabs())
	{
		return false;
	}

	for (Pct i = vec.GetSrc() + vec.GetVdir(); i != vec.GetDst(); i = i + vec.GetVdir())
	{
		if (!_tab->GetSpatiuGol(i))
			return false;
	}

	return true;
}


char Nebun::GetSimbol() const
{
	return _rend;
}

int Nebun::GetCost() const
{
	return _cost;
}



Regina::Regina(int ech, Tabla * tab) : Piesa(ech, tab)
{
}

Regina::~Regina()
{
}


bool Regina::VerifMutare(Pct const & src, Pct const & dst) const
{
	return VerifMutare(Vector(src, dst));
}

bool Regina::VerifMutare(Vector const & vec) const
{
	if (vec.GetVXabs() != vec.GetVYabs() && vec.GetVX() != 0 && vec.GetVY() != 0)
	{
		return false;
	}

	for (Pct i = vec.GetSrc() + vec.GetVdir(); i != vec.GetDst(); i = i + vec.GetVdir())
	{
		if (!_tab->GetSpatiuGol(i))
			return false;
	}

	return true;
}


char Regina::GetSimbol() const
{
	return _rend;
}

int Regina::GetCost() const
{
	return _cost;
}



Rege::Rege(int ech, Tabla * tab) : Piesa(ech, tab)
{
}

Rege::~Rege()
{
}


bool Rege::VerifMutare(Pct const & src, Pct const & dst) const
{
	return VerifMutare(Vector(src, dst));
}

bool Rege::VerifMutare(Vector const & vec) const
{
	return vec.GetVX() <= 1 && vec.GetVX() >= -1 && vec.GetVY() <= 1 && vec.GetVY() >= -1;

	//TO DO: verific capturare

	//TO DO: rocada

}


char Rege::GetSimbol() const
{
	return _rend;
}

int Rege::GetCost() const
{
	return _cost;
}
