#pragma once
#include"CFigura.h"
using namespace System::Drawing;
class CRombo :public CFigura
{
public:
	CRombo();
	CRombo(int x, int y, int dx, int lado);
	~CRombo();
	void borrar(Graphics^ g);
	void dibujar(Graphics^ g);
private:
	int lado;
};
CRombo::CRombo()
{
	lado = 0;
}
CRombo::~CRombo(){}
CRombo::CRombo(int x, int y, int dx, int lado) :CFigura(x, y,dx) {
	this->lado = lado;
}
void CRombo::borrar(Graphics^ g) {
	//Hace el algoritmo para poder borrar el rombo
	array<Point>^ puntos = gcnew array<Point>(4);
	puntos[0] = Point(x + lado / 2, y);
	puntos[1] = Point(x , y + lado / 2);
	puntos[2] = Point(x + lado / 2, y + lado);
	puntos[3] = Point(x + lado, y + lado / 2);
	g->DrawPolygon(Pens::Snow, puntos);

}
void CRombo::dibujar(Graphics^ g){
	array<Point>^ puntos = gcnew array<Point>(4);
	puntos[0] = Point(x + lado / 2, y);
	puntos[1] = Point(x, y + lado / 2);
	puntos[2] = Point(x + lado / 2, y + lado);
	puntos[3] = Point(x + lado, y + lado / 2);
	g->DrawPolygon(Pens::Black, puntos);
}
