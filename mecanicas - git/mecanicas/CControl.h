#pragma once
#include "Personaje.h"
#include "Suelo.h"
#include "CFondo.h"
#include "CSuelos.h"
#include "Cenemigo.h"
using namespace System::Drawing;
class Ccontroladora
{
public:
	Ccontroladora() {
		
		mapa = new CMapa();
		jugador = new Cjugador();
		suelo = false;
		fondo = new CFondo();
		enemigo = new Cenemigo();
		
	}
	~Ccontroladora() {}
	void dibujar(Graphics^ g, Bitmap^ nada, Bitmap^ bmpsuelo, Bitmap^ bmppuas, Bitmap^ bmppuas2, Bitmap^ bmpcañones, Bitmap^ bmptrampolin, Bitmap^ bmpjugador) {
		fondo->fondo(g, nada);
		fondo->pintarM(g, bmpsuelo, bmppuas, bmppuas2, bmpcañones, bmptrampolin);
		jugador->dibujarjugador(g);
		mapa->dibujar(g);
	}
	void interseccion(){
		for (int i=0; i < 3; i++) {
			if (jugador->getJug().IntersectsWith(mapa->getRect(i))) {
				suelo = true;
			}
			
		} 
		if (suelo) {
			jugador->suelotrue();
		}
		else {
			jugador->suelofalse();
		}
		suelo = false;
	}
	void animar() {
		enemigo->animar();
		jugador->animar();
		enemigo->mover();
		jugador->mover();
		
	}
	void salto() {
		jugador->salto();
	}
	void setDir(Direcciones dir) {
		jugador->setDir(dir);
	}

private:
	bool suelo;
	Cjugador* jugador;
	Rectangle a;
	Rectangle b;
	CMapa* mapa;
	CFondo* fondo;
	Cenemigo* enemigo;
};