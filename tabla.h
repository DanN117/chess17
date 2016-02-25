// Chess17 v1.1 - Dan Nigai

#pragma once

#include <iostream>

#include "clase.h"

using namespace std;


class Tabla
{
	int _runda = 1;
	Piesa *_piese[8][8];
	Piesa*& Piese(Pct p);

public:
	Tabla();
	~Tabla();

	int GetRunda() const;
	int IncRunda();

	int GetJucator() const;
	int GetCuloareJucator() const;

	int GetEchipaPiesa(int a, int b) const;
	int GetEchipaPiesa(Pct p) const;
	bool GetSpatiuGol(Pct p) const;

	int GetCuloarePiesa(int a, int b, int s = 0) const;
	int GetCuloarePatrat(int a, int b, int s = 0) const;
	char GetSimbol(int a, int b) const;

	int GetNrPiese() const;
	int GetCost() const;
	//TO DO: get cost mutare	int(Tabla, Vector)
	// Tabla(Tabla, Vector)

	bool SahMat(int jucator) const;	//TO DO

	bool VerificPiesa(Pct p);	// daca poate fi mutat?

	bool VerificMutare(Pct const &src, Pct const &dst);
	bool VerificMutare(Vector const &vec);

	void AplicMutare(Pct const &src, Pct const &dst);
	void AplicMutare(Vector const &vec);

};