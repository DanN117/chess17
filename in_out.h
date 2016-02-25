// Chess17 v1.1 - Dan Nigai

#pragma once

#include <iostream>

#include "clase.h"

using namespace std;


class IO
{
public:
	IO();
	~IO();

	static int  Xin(char x);
	static int  Yin(char y);

	static char Xout(int x);
	static char Yout(int y);

	static Vector GetMutareValida(Tabla & mainTab);

};