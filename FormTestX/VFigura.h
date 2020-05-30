#pragma once
#include "CCuadrado.h"
#include "CCirculo.h"
#include "CRombo.h"
#include <vector>
using namespace System::Drawing;
using namespace System;
using std::vector;

class ArregloFigura
{
private:
	vector<CFigura*> arrF;
	int contador;
public:
	ArregloFigura() {
		contador = 0;
	}
	~ArregloFigura() {}

	void dibujar(Graphics^ g);
	void AgregarFigura(Graphics^ g);
	void validarLlegada(Graphics^ g) {

		for (int i = 0; i < arrF.size(); i++)
		{
			if (arrF[i]->llegada()) {
				contador++;
				Drawing::Font^ fuente = gcnew Drawing::Font("Arial Black", 18);
				if (contador == 1) {
					g->DrawString("Ganaste", fuente, Brushes::Red, 590, arrF[i]->getY());
				}
				else
				{
					g->DrawString("Posicion "+contador.ToString()+"°", fuente, Brushes::Red, 590, arrF[i]->getY());
				}
			}
		}
	}
};
void ArregloFigura::dibujar(Graphics^ g)
{
	for (int i = 0; i < arrF.size(); i++)
	{
		if (!arrF[i]->llegada())
		arrF[i]->mover(g);
	}
}

void ArregloFigura::AgregarFigura(Graphics^ g)
{
	Random r;
	CFigura* fig;
	//Color col = Color::FromArgb(r.Next(256), r.Next(256), r.Next(256));
	//int color = ColorTranslator::ToWin32(col);
	fig = new CCirculo(0, 1,r.Next(1,20), 60);
	arrF.push_back(fig);
	fig = new CCuadrado(0, 120, r.Next(1, 20), 60);
	arrF.push_back(fig);
	fig = new CRombo(0, 240, r.Next(1, 20), 60);
	arrF.push_back(fig);

}




