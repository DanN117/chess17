// Chess17 v1.1 - Dan Nigai

#pragma once

#include <stdlib.h>

#include "clase.h"


class AI
{

public:
	AI();
	~AI();

	static int Random07();

	static Vector RandomVec();

	static Vector RandomValid(Tabla & tab);		//TO DO: ar trebui const

	//TO DO: Vector AI::Max_1_N(Tabla & tab, int n = 30);
};