#pragma once
#include "CListaSE.h"
#include "Suelo.h"
#include <array>
class CMapa {
private:
	SList<Csuelo>* suelos;
	
public:
	CMapa() {
		suelos = new SList<Csuelo>();
		suelos->addFirst(Csuelo(Rectangle(190, 350, 80, 30)));
		suelos->addFirst(Csuelo(Rectangle(90, 400, 90, 80)));
		suelos->addFirst(Csuelo(Rectangle(190, 350, 80, 30)));
		
	}
	void dibujar(Graphics^ g) {
		
		for (int i = 0; i < 1; i++) {
			suelos->getAt(i).dibujar(g);
		}
	}
	Rectangle getRect(int i) {
		return suelos->getAt(i).getSuel();
	}
};
