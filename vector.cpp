// Chess17 v1.1 - Dan Nigai

#include "punct.h"
#include "in_out.h"
#include "vector.h"


Vector::Vector() : _src(9, 9), _dst(9, 9)
{
}

Vector::Vector(Pct a, Pct b) : _src(a), _dst(b)
{
}

Vector::~Vector()
{
}


bool Vector::Valid() const
{
	return _src.Valid() && _dst.Valid();
}


int Vector::GetSrcX() const
{
	return _src.GetX();
}

int Vector::GetSrcY() const
{
	return _src.GetY();
}

Pct Vector::GetSrc() const
{
	return _src;
}


int Vector::GetDstX() const
{
	return _dst.GetX();
}

int Vector::GetDstY() const
{
	return _dst.GetY();
}

Pct Vector::GetDst() const
{
	return _dst;
}


int Vector::GetVX() const
{
	return _dst.GetX() - _src.GetX();
}

int Vector::GetVY() const
{
	return _dst.GetY() - _src.GetY();
}


int Vector::GetVXabs() const
{
	return abs(_dst.GetX() - _src.GetX());
}

int Vector::GetVYabs() const
{
	return abs(_dst.GetY() - _src.GetY());
}


int Vector::GetVXdir() const
{
	if (_dst.GetX() - _src.GetX() < 0)
		return -1;

	if (_dst.GetX() - _src.GetX() == 0)
		return 0;

	if (_dst.GetX() - _src.GetX() > 0)
		return 1;

	return 0;
}

int Vector::GetVYdir() const
{
	if (_dst.GetY() - _src.GetY() < 0)
		return -1;

	if (_dst.GetY() - _src.GetY() == 0)
		return 0;

	if (_dst.GetY() - _src.GetY() > 0)
		return 1;

	return 0;
}

Pct Vector::GetVdir() const
{
	int dx = GetVXdir(), dy = GetVYdir();

	return Pct(dx, dy);
}


ostream & operator << (ostream & out, const Vector & v)
{
	return out << "   V:  " << v.GetSrc() << " - " << v.GetDst() << "   ";
}
