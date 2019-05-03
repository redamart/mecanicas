#pragma once
#pragma once
//enum Direcciones { arriba, abajo, derecha, izquierda, ninguna };
using namespace System::Drawing;
class Cenemigo {
	int x;
	int y;
	int vel;
	bool suelo;
	int gravedad;
	bool saltando;
	Rectangle jug;
	Direcciones direccion;

public:
	Cenemigo() {
		this->x = 49;
		this->y = 40;
		vel = 20;
		
		gravedad = 6;
		jug = Rectangle(x, y, 50, 50);
		direccion = Direcciones::derecha;
		saltando = false;
	}

	void setDir(Direcciones dir) {
		direccion = dir;
	}
	void dibujarjugador(Graphics^ g) {
		//g->DrawImage(bmpjugador, x, y, 30, 20);
		Pen^ red = gcnew Pen(Brushes::RosyBrown);
		g->DrawRectangle(red, jug);
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
		if (this->x > 600) {
			setDir(izquierda);
		} 
		if (this->x < 0) {
			setDir(derecha);
		}
		
		jug = Rectangle(x, y, 50, 50);
	}

	void mover() {
		switch (direccion)
		{
		case Direcciones::derecha:
			x = x + 2;
			break;
		case Direcciones::izquierda:
			x = x - 2;
			break;
		case Direcciones::arriba:
			y = y - 2;
			break;
		case Direcciones::abajo:
			y = y + 2;
			break;
		default:

			break;
		}
	}



};