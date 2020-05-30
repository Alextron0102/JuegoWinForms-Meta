#pragma once
#include"CFigura.h"
using namespace System::Drawing;
class CCuadrado :public CFigura
{
private:
	int  lado;
public:
	CCuadrado();
	CCuadrado(int x, int y, int dx, int lado);
	~CCuadrado();
	void borrar(Graphics^ g);
	void dibujar(Graphics^ g);

};

CCuadrado::CCuadrado()
{
	int lado = 0;
}
CCuadrado::CCuadrado(int x, int y, int dx, int lado) :CFigura(x, y,dx)
{
	this->lado = lado;
}
CCuadrado::~CCuadrado(){}
void CCuadrado::borrar(Graphics^ g) {
	g->DrawRectangle(Pens::Snow, x, y, lado, lado);
}
void CCuadrado::dibujar(Graphics^ g) {
	g->DrawRectangle(Pens::PaleVioletRed, x, y, lado, lado);
}

