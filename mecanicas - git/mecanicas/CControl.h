#pragma once
#include "Personaje.h"
#include "Suelo.h"
using namespace System::Drawing;
class Ccontroladora
{
public:
	Ccontroladora() {
		
		suelo1 = new Csuelo(Rectangle(60, 300, 50, 20));
		suelo2 = new Csuelo(Rectangle(90, 400, 90, 80));
		suelo3 = new Csuelo(Rectangle(190, 350, 80, 30));
		jugador = new Cjugador();
		
	}
	~Ccontroladora() {}
	void dibujar(Graphics^ g) {
		suelo1->dibujar(g);
		suelo2->dibujar(g);
		suelo3->dibujar(g);
		jugador->dibujarjugador(g);
	}
	void animar() {
		if (jugador->getJug().IntersectsWith(suelo1->getSuel())|| jugador->getJug().IntersectsWith(suelo2->getSuel()) || jugador->getJug().IntersectsWith(suelo3->getSuel())) {
			jugador->suelotrue();
		}else {
			jugador->suelofalse();
		}
		jugador->animar();
		
	}
	void salto() {
		jugador->salto();
	}
	void setDir(Direcciones dir) {
		jugador->setDir(dir);
	}

private:
	Csuelo *suelo1;
	Csuelo* suelo2;
	Csuelo* suelo3;
	Cjugador* jugador;
	Rectangle a;
	Rectangle b;
};