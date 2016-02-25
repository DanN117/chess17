// Chess17 v1.1 - Dan Nigai

#include <iostream>
#include <Windows.h>
#include <stdlib.h>

#include "clase.h"
#include "tabla.h"
#include "punct.h"
#include "vector.h"
#include "piesa.h"
#include "desen.h"
#include "in_out.h"
#include "AI.h"

using namespace std;


int main()
{
	Tabla mainTab;
	Vector mut;

	while (mainTab.GetRunda() <= 300)	//TO DO: conditii extra
	{
		if (mainTab.GetRunda() % 2 == 1)
		{
			mut = IO::GetMutareValida(mainTab);
		}
		else
		{
			mut = AI::RandomValid(mainTab);
		}

		if (mainTab.VerificMutare(mut))
		{
			mainTab.AplicMutare(mut);
			mainTab.IncRunda();
		}
	}

	cout << "\n   Jucatorul " << (rand() % 2 + 1) << " a castigat.";

    return 0;
}
