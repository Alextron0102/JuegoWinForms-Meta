#pragma once
using namespace System;
using namespace System::Drawing;
class CFigura
{
protected:
	int x, y, dx;
	bool activa;
public:
	CFigura() {}
	CFigura(int x, int y, int dx);
	~CFigura() {}
	virtual void dibujar(Graphics^ g) = 0;
	virtual void borrar(Graphics^ g) = 0;
	void mover(Graphics^ g);
	bool llegada();
	int getY() {
		return y;
	}
};

CFigura::CFigura(int x, int y, int dx)
{
	activa = true;
	this->x = x;
	this->y = y;
	this->dx = dx;
}

void CFigura::mover(Graphics^ g) {
	borrar(g);
	x += dx;
	dibujar(g);
}
bool CFigura::llegada() {
	if (activa == false) {
		return false;
	}
	if (x + dx < 1 || x + dx >500) {
		dx = 0;
		activa = false;
		return true;
	}
	return false;
}