#pragma once
#include <list>
#include "Suelo.h"
#include <array>
class CMapa {
private:
	Csuelo* suelos[10];
	
public:
	CMapa() {
		suelos[0] = new Csuelo(Rectangle(190, 350, 80, 30));
		suelos[1] = new Csuelo(Rectangle(90, 400, 90, 80));
		suelos[2] = new Csuelo(Rectangle(190, 350, 80, 30));
	}
	void dibujar(Graphics^ g) {
		
		for (int i = 0; i < 3; i++) {
			suelos[i]->dibujar(g);
		}
	}
	Rectangle getRect(int i) {
		return suelos[i]->getSuel();
	}
};
