// Chess17 v1.1 - Dan Nigai

#pragma once

#include <iostream>
#include <math.h>

#include "clase.h"

using namespace std;


class Vector
{
	Pct _src;
	Pct _dst;

public:
	Vector();
	Vector(Pct a, Pct b);
	~Vector();

	bool Valid() const;
	
	int GetSrcX() const;
	int GetSrcY() const;
	Pct GetSrc() const;

	int GetDstX() const;
	int GetDstY() const;
	Pct GetDst() const;

	int GetVX() const;
	int GetVY() const;

	int GetVXabs() const;
	int GetVYabs() const;

	int GetVXdir() const;
	int GetVYdir() const;
	Pct GetVdir() const;

	friend ostream& operator << (ostream& out, const Vector &v);

};