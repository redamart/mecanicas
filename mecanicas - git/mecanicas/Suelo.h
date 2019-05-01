#pragma once
using namespace System::Drawing;

class Csuelo {
private:
	Rectangle a;
	Rectangle b;
public:
	Csuelo(){
		a = Rectangle(60, 300, 50, 20);
		b = Rectangle(90, 100, 30, 80);
		
	}
	void dibujar(Graphics^g) {

		g->DrawRectangle(gcnew Pen(Color::Brown), a);
	}
	Rectangle getSuel() {
		return a;
		
	}
};