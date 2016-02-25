// Chess17 v1.1 - Dan Nigai

#include "in_out.h"
#include "punct.h"


Pct::Pct() : _x(9), _y(9)
{
}

Pct::Pct(int a, int b) : _x(a), _y(b)
{
}

Pct::~Pct()
{
}


bool Pct::Valid() const
{
	return _x >= 0 && _x <= 7 && _y >=0 && _y <= 7;
}


int Pct::GetX() const
{
	return _x;
}

int Pct::GetY() const
{
	return _y;
}


bool Pct::operator == (Pct p) const
{
	return (p._x == _x) && (p._y == _y);
}

bool Pct::operator != (Pct p) const
{
	return (p._x != _x) || (p._y != _y);
}

Pct Pct::operator + (Pct p) const
{
	return Pct(p._x + _x, p._y + _y);
}


istream & operator >> (istream & in, Pct & p)
{
	char x, y;

	cout << "     (a-h): ";
	in >> y;
	p._y = IO::Yin(y);

	cout << "     (1-8): ";
	in >> x;
	p._x = IO::Xin(x);

	in.ignore(256, '\n');

	return in;
}

ostream & operator << (ostream & out, const Pct & p)
{
	return out << IO::Yout(p._y) << ":" << IO::Xout(p._x);
}
