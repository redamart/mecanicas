#pragma once
#include "Personaje.h"
#include "Suelo.h"
using namespace System::Drawing;
class Ccontroladora
{
public:
	Ccontroladora() {
		mapa = new Csuelo();
		jugador = new Cjugador();
	}
	~Ccontroladora() {}
	void dibujar(Graphics^ g) {
		mapa->dibujar(g);
		jugador->dibujarjugador(g);
	}
	void animar() {
		if (jugador->getJug().IntersectsWith(mapa->getSuel())) {
			jugador->suelotrue();
		}else {
			jugador->suelofalse();
		}
		jugador->animar();
		
	}
	void setDir(Direcciones dir) {
		jugador->setDir(dir);
	}

private:
	Csuelo *mapa;
	Cjugador* jugador;
};