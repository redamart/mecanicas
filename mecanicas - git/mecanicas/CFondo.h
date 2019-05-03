#pragma once

#include<ctime>
#include<stdlib.h>
#define filas 22
#define columnas 28
using namespace System::Drawing;
class CFondo
{
private:
	int** matri;
public:
	CFondo() {}
	~CFondo() {}


	void pintarM(Graphics^ g, Bitmap^ bmpsuelo, Bitmap^ bmppuas, Bitmap^ bmpuas2, Bitmap^ bmpcañones, Bitmap^ bmptrampolin) {
		int z = 0;
		int y = 0;
	}


	void fondo(Graphics^ g, Bitmap^ nada) {
		g->DrawImage(nada, 0, 0, 864, 672);
	}
	int** getmatriz() {
		return matri;
	}
};


