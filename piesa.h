// Chess17 v1.1 - Dan Nigai

#pragma once

#include "clase.h"


class Piesa
{
	const int _echipa;
	bool _mutat = false;

protected:
	Tabla *_tab;

public:
	Piesa(int ech, Tabla * const tab);
	~Piesa();

	int GetEchipa() const;

	bool GetMutat() const;
	void SetMutat();
	void ResetMutat();

	virtual bool VerifMutare(Pct const &src, Pct const &dst) const = 0;
	virtual bool VerifMutare(Vector const &vec) const = 0;

	virtual char GetSimbol() const = 0;
	virtual int  GetCost() const = 0;

};


class Pion : public Piesa
{
public:
	static const int _cost = 100;
	static const char _rend = 'P';

	Pion(int ech, Tabla * const tab);
	~Pion();

	bool VerifMutare(Pct const &src, Pct const &dst) const;
	bool VerifMutare(Vector const &vec) const;

	char GetSimbol() const;
	int  GetCost() const;

};


class Cal: public Piesa
{
public:
	static const int _cost = 320;
	static const char _rend = 'H';

	Cal(int ech, Tabla * const tab);
	~Cal();

	bool VerifMutare(Pct const &src, Pct const &dst) const;
	bool VerifMutare(Vector const &vec) const;

	char GetSimbol() const;
	int  GetCost() const;

};


class Tura : public Piesa
{
public:
	static const int _cost = 510;
	static const char _rend = 'R';

	Tura(int ech, Tabla * const tab);
	~Tura();

	bool VerifMutare(Pct const &src, Pct const &dst) const;
	bool VerifMutare(Vector const &vec) const;

	char GetSimbol() const;
	int  GetCost() const;

};


class Nebun : public Piesa
{
public:
	static const int _cost = 333;
	static const char _rend = 'B';

	Nebun(int ech, Tabla * const tab);
	~Nebun();

	bool VerifMutare(Pct const &src, Pct const &dst) const;
	bool VerifMutare(Vector const &vec) const;

	char GetSimbol() const;
	int  GetCost() const;

};


class Regina : public Piesa
{
public:
	static const int _cost = 880;
	static const char _rend = 'Q';

	Regina(int ech, Tabla * const tab);
	~Regina();

	bool VerifMutare(Pct const &src, Pct const &dst) const;
	bool VerifMutare(Vector const &vec) const;

	char GetSimbol() const;
	int  GetCost() const;

};


class Rege : public Piesa
{
public:
	static const int _cost = 1000000;
	static const char _rend = 'K';

	Rege(int ech, Tabla * const tab);
	~Rege();

	bool VerifMutare(Pct const &src, Pct const &dst) const;
	bool VerifMutare(Vector const &vec) const;

	char GetSimbol() const;
	int  GetCost() const;

};