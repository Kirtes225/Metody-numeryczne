#include <iostream>
#include "Punkt.h"

using namespace std;

//x0 = 1, y0 = 1
//x1 = 2, y1 = 4
//x2 = 4, y2 = 16
//   |
//   |
//   V
//b0 = 1, b1 = 3, b2 = 1

int main()
{
	setlocale(LC_ALL, "");

	int wezly;

	cout << "Podaj liczbê wêz³ów: ";
	cin >> wezly;

	Punkt* tablica = new Punkt[wezly];
	double* b = new double[wezly];

	for (int i = 0; i < wezly; i++)
	{
		cout << "Podaj x[" << i << "]: ";
		cin >> tablica[i].x;
		cout << "Podaj y[" << i << "]: ";
		cin >> tablica[i].y;
		b[i] = 0.;
	}
	cout << "Podaj punkt, dla którego wyszukaæ wartoœæ: ";
	double podanyPkt;
	cin >> podanyPkt;

	b = Lagrange(tablica, wezly);

	double wartoscPkt;
	wartoscPkt = wartosc(tablica, wezly, podanyPkt);

	for (int i = 0; i < wezly; i++)
		cout << "b[" << i << "] = " << b[i] << endl;
	cout << "Punkt u¿ytkownika: " << podanyPkt << "\tWartoœæ: " << wartoscPkt << endl;
	system("pause");
	return 0;
}