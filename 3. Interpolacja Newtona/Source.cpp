#include<iostream>
#include "Punkt.h"

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	//int x[10], y[10], p[10];

	int wezly, j = 1, f1 = 1, f2 = 0;

	double podanyPkt, wartoscPkt;

	cout<<"Podaj lizbê wêz³ów: ";
	cin >> wezly;

	Punkt* tablica = new Punkt[wezly];
	double* p = new double[wezly];

	p[0] = 0; //nieu¿ywane

	for (int i = 0; i < wezly; i++) {
		cout << "Podaj x[" << i << "]: ";
		cin >> tablica[i].x;
		cout << "Podaj y[" << i << "]: ";
		cin >> tablica[i].y;
	}

	wartoscPkt = tablica[1].y;
	cout << "Podaj punkt, dla którego wyszukaæ wartoœæ: ";
	cin >> podanyPkt;

	do {
		for (int i = 1; i <= wezly - 1; i++) {
			p[i] = ((tablica[i + 1].y - tablica[i].y) / (tablica[i + j].x - tablica[i].x));
			cout << "p[" << i << "] = " << p[i] << endl;
			tablica[i].y = p[i];
		}
		f1 = 1;
		for (int i = 1; i <= j; i++) {
			f1 *= (podanyPkt - tablica[i].x);
		}
		f2 += (tablica[1].y * f1);
		wezly--;
		j++;
	}while (wezly != 1);
	
	wartoscPkt += f2;
	cout << "Punkt u¿ytkownika: " << podanyPkt << "\tWartoœæ: " << wartoscPkt << endl;
	system("pause");
	return 0;
}