#pragma once
enum Direcciones{arriba,abajo,derecha,izquierda,ninguna};
using namespace System::Drawing;
class Cjugador {
	int x;
	int y;
	int vel;
	bool suelo;
	int gravedad;
	bool saltando;
	Rectangle jug;
	Direcciones direccion;

public:
	Cjugador() {
		this->x = 80;
		this->y = 90;
		vel = 20;
		suelo = false;
		gravedad = 6;
		jug = Rectangle(x, y, 50, 50);
		direccion = Direcciones::arriba;
		saltando = false;
	}

	void setDir(Direcciones dir) {
		direccion = dir;
	}
	void dibujarjugador(Graphics^ g) {
		//g->DrawImage(bmpjugador, x, y, 30, 20);
		Pen^ red = gcnew Pen(Brushes::Blue);
		g->DrawRectangle(red,jug);
	}
	Rectangle getJug() {
		return jug;
	}
	void suelotrue() {
		suelo = true;
	}
	void suelofalse() {
		suelo = false;
	}
	void animar() {
		if (saltando && vel > 0) {
			y = y - vel;
			vel--;
		}
		else {
			vel = 20;
			saltando = false;
		}
		
		if (suelo) {
			
		}
		else {
			y = y + gravedad;
		}
		switch (direccion)
		{
		case Direcciones::derecha:
			x = x + 2;
			break;
		case Direcciones::izquierda:
			x= x-2;
			break;
		default:
			
			break;
		}
		jug = Rectangle(x, y, 50, 50);
	}
	void salto() {
		if (suelo) {
			saltando = true;
		}
	}
	void mover(char a) {
		switch (a)
		{
		case 'a': x--;
			break;
		case  'w':
			break;

		case 'd': x++;
			break;
		default:
			break;
		}
	}



};