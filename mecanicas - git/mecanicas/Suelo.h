#pragma once
using namespace System::Drawing;

class Csuelo {
private:
	Rectangle a;
	Rectangle b;
public:
	Csuelo(Rectangle rect){
		a = rect;
		
		
	}
	void dibujar(Graphics^g) {

		g->DrawRectangle(gcnew Pen(Color::Brown), a);
	}
	Rectangle getSuel() {
		return a;
		
	}
};