// Chess17 v1.1 - Dan Nigai

#include "punct.h"
#include "tabla.h"
#include "in_out.h"
#include "desen.h"


void Clear()
{
	system("cls");
}

void SetCuloare(int c, int b)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c + b * 16);
}

void Desen(Tabla &tab, Pct sel)
{
	Clear();

	cout << "\n   Runda: " << tab.GetRunda() << "\n   Randul jucatorului: ";
	SetCuloare(tab.GetCuloareJucator());
	cout << tab.GetJucator();

	cout << "\n    ";
	SetCuloare(7);
	for (int i = 0; i < 8; i++)
	{
		cout << IO::Yout(i) <<"  ";
	}

	for (int i = 7; i >= 0; i--)
	{
		SetCuloare(7);
		cout << "\n " << IO::Xout(i) << " ";
			for (int j = 0; j < 8; j++)
			{
				SetCuloare(tab.GetCuloarePatrat(i, j), Pct(i, j) == sel ? 15 : 0);
				cout << "[";

				SetCuloare(tab.GetCuloarePiesa(i, j, Pct(i, j) == sel || tab.VerificMutare(sel, Pct(i, j))), Pct(i, j) == sel ? 15 : 0);
				cout << tab.GetSimbol(i, j);

				SetCuloare(tab.GetCuloarePatrat(i, j), Pct(i, j) == sel ? 15 : 0);
				cout << "]";
			}
	}

	SetCuloare(7);
	cout << "\n Nr.   piese: " << tab.GetNrPiese();
	cout << "\n";
}
