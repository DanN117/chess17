// Chess17 v1.1 - Dan Nigai

#include "punct.h"
#include "vector.h"
#include "tabla.h"
#include "AI.h"


AI::AI()
{
}

AI::~AI()
{
}


int AI::Random07()
{
	return rand() % 8;
}


Vector AI::RandomVec()
{
	return Vector(Pct(Random07(), Random07()), Pct(Random07(), Random07()));
}


Vector AI::RandomValid(Tabla & tab)		//bucla infinita daca nu exista mutari
{
	Vector v = RandomVec();

	while (!tab.VerificMutare(v))
	{
		v = RandomVec();
	}

	return v;
}


/*
Vector AI::Max_1_N(Tabla & tab, int n)
{
	Vector vecAI[n];

	for (int i = 0; i < n; i++)
	{
		//TO DO: verific daca mai exista mutari
		vecAI[i] = RandomValid(tab);
	}

	//TO DO: return max(   vecAI   );
*/
