// Chess17 v1.1 - Dan Nigai

#pragma once

#include <iostream>

#include "clase.h"

using namespace std;


class Pct
{
	int _x;
	int _y;

public:
	Pct();
	Pct(int a, int b);
	~Pct();

	bool Valid() const;

	int GetX() const;
	int GetY() const;

	bool operator == (Pct p) const;
	bool operator != (Pct p) const;
	Pct  operator  + (Pct p) const;

	friend istream& operator >> (istream& in, Pct &p);
	friend ostream& operator << (ostream& out, const Pct &p);

};