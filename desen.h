// Chess17 v1.1 - Dan Nigai

#pragma once

#include <iostream>
#include <Windows.h>
#include <stdlib.h>

#include "clase.h"

using namespace std;


void Clear();

void SetCuloare(int c, int b = 0);

void Desen(Tabla &tab, Pct sel = Pct(9, 9));
