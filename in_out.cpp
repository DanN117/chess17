// Chess17 v1.1 - Dan Nigai

#include "punct.h"
#include "vector.h"
#include "tabla.h"
#include "desen.h"
#include "in_out.h"


IO::IO()
{
}

IO::~IO()
{
}


int IO::Xin(char x)
{
	return x - 49;
}

int IO::Yin(char y)
{
	return y - 97;
}


char IO::Xout(int x)
{
	return x + 49;
}

char IO::Yout(int y)
{
	return y + 97;
}


Vector IO::GetMutareValida(Tabla & mainTab)
{
	Pct vSrc(9, 9);
	Pct vDst(9, 9);

	while(!vSrc.Valid() || mainTab.GetEchipaPiesa(vSrc) != mainTab.GetJucator() || !mainTab.VerificPiesa(vSrc))	
	{
		Desen(mainTab);
		cout << "\n   Selectare piesa:\n";
		cin >> vSrc;
	}

	while (!vSrc.Valid() || !mainTab.VerificMutare(Vector(vSrc, vDst)))		//TO DO: daca mut in acelasi loc, selectez alta piesa
	{
		Desen(mainTab, vSrc);
		cout << "\n   Selectare destinatie:\n";
		cin >> vDst;
	}

	return Vector(vSrc, vDst);
}
