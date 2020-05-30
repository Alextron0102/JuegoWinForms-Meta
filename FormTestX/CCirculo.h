#pragma once
#include"CFigura.h"
using namespace System::Drawing;
class CCirculo :public CFigura
{

private:
	int radio;
public:
	CCirculo();
	CCirculo(int x, int y, int dx, int radio);
	~CCirculo();
	void borrar(Graphics^ g);
	void dibujar(Graphics^ g);

};

CCirculo::CCirculo()
{
	int radio = 0;
}
CCirculo::CCirculo(int x, int y, int dx, int radio) :CFigura(x, y,dx)
{
	this->radio = radio;

}
CCirculo::~CCirculo(){}
void CCirculo::borrar(Graphics^ g) {
	g->DrawEllipse(Pens::Snow, x, y, radio, radio);
}
void CCirculo::dibujar(Graphics^ g) {
	g->DrawEllipse(Pens::Green, x, y, radio, radio);
}

