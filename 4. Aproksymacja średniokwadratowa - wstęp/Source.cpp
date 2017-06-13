#include "Punkt.h"
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "");

	int stopien;
	cout << "WprowadŸ stopieñ wielomianu: ";
	cin >> stopien;

	if (stopien == 1) {

		double g00 = 0, g01 = 0, g10 = 0, g11 = 0;
		double p0 = 0, p1 = 0;
		double a0 = 0, a1 = 0;

		int n;
		cout << "WprowadŸ liczbê punktów: ";
		cin >> n;
		Punkt * tab = new Punkt[n];
		for (int i = 0; i < n; i++) {
			cout << "WprowadŸ punkt x[" << i << "]: ";
			cin >> tab[i].x;
			cout << "WprowadŸ punkt y[" << i << "]: ";
			cin >> tab[i].y;
		}

		for (int i = 0; i < n; i++) {
			g00 += pow(tab[i].x, 0);
			g01 += pow(tab[i].x, 1);
			g10 += pow(tab[i].x, 1);
			g11 += pow(tab[i].x, 2);
			p0 += tab[i].y;
			p1 += (tab[i].x*tab[i].y);
		}
		cout << "g00 = " << g00 << " g01 = " << g01 << " g10 = " << g10 << " g11 = " << g11 << endl;
		cout << "p0 = " << p0 << " p1 = " << p1 << endl;
		double W;
		double Wa0;
		double Wa1;
		W = g00*g11 - g01*g10;
		if (W != 0.) {
			Wa0 = p0*g11 - g01*p1;
			Wa1 = g00*p1 - p0*g10;
			a0 = Wa0 / W;
			a1 = Wa1 / W;
		}
		else {
			cout << "Wyznacznik = 0, nie da siê rozwi¹zaæ uk³adu";
			return 0;
		}
		cout << "a0 = " << a0 << endl;
		cout << "a1 = " << a1 << endl;
		cout << std::showpos << "Wynik: y=" << a1 << "*x" << a0 << endl;
		cout << "---------------------------------------------------------------------" << endl;
	}

	if (stopien == 2) {

		double g00 = 0, g01 = 0, g02 = 0,
			g10 = 0, g11 = 0, g12 = 0,
			g20 = 0, g21 = 0, g22 = 0;

		double p0 = 0, p1 = 0, p2 = 0;

		double a0 = 0, a1 = 0, a2 = 0;

		int n;
		cout << "WprowadŸ liczbê punktów: ";
		cin >> n;
		Punkt * tab = new Punkt[n];
		for (int i = 0; i < n; i++) {
			cout << "WprowadŸ punkt x[" << i << "]: ";
			cin >> tab[i].x;
			cout << "WprowadŸ punkt y[" << i << "]: ";
			cin >> tab[i].y;
		}

		for (int i = 0; i < n; i++) {
			g00 += pow(tab[i].x, 0);
			g01 += pow(tab[i].x, 1);
			g02 += pow(tab[i].x, 2);
			g10 += pow(tab[i].x, 1);
			g11 += pow(tab[i].x, 2);
			g12 += pow(tab[i].x, 3);
			g20 += pow(tab[i].x, 2);
			g21 += pow(tab[i].x, 3);
			g22 += pow(tab[i].x, 4);

			p0 += tab[i].y;
			p1 += (tab[i].x*tab[i].y);
			p2 += (pow(tab[i].x, 2)*tab[i].y);
		}
		cout << "g00 = " << g00 << " g01 = " << g01 << " g02 = " << g02 << endl;
		cout << "g10 = " << g10 << " g11 = " << g11 << " g12 = " << g12 << endl;
		cout << "g20 = " << g20 << " g21 = " << g21 << " g22 = " << g22 << endl;
		cout << "p0 = " << p0 << " p1 = " << p1 << "p2 = " << p2 << endl;

		double W;
		double Wa0;
		double Wa1;
		double Wa2;

		W = g00 * g11 * g22 + g10 * g21 * g02 + g20 * g01 * g12
			- (g20 * g11 * g02 + g10 * g01 * g22 + g00 * g12 * g21);

		if (W != 0) {
			Wa0 = p0 * g11 * g22 +
				p1 * g21 * g02 +
				p2 * g01 * g12 -
				(p2 * g11 * g02 +
					p1 * g01 * g22 +
					p0 * g12 * g21);

			Wa1 = g00 * p1 * g22 +
				g10 * p2 * g02 +
				g20 * p0 * g12 -
				(g20 * p1 * g02 +
					g10 * p0 * g22 +
					g00 * g12 * p2);

			Wa2 = g00 * g11 * p2 +
				g10 * g21 * p0 +
				g20 * g01 * p1 -
				(g20 * g11 * p0 +
					g10 * g01 * p2 +
					g00 * p1 * g21);

			a0 = Wa0 / W;
			a1 = Wa1 / W;
			a2 = Wa2 / W;
		}
		else {
			cout << "Wyznacznik = 0, nie da siê rozwi¹zaæ uk³adu";
			return 0;
		}
		cout << "a0 = " << a0 << endl;
		cout << "a1 = " << a1 << endl;
		cout << "a2 = " << a2 << endl;
		cout << std::showpos<< "Wynik: y=" << a2 << "*x^2" << a1 << "x" << a0 << endl;
		cout << "---------------------------------------------------------------------" << endl;
	}


	/*
	int stopien;
	cout << "WprowadŸ stopieñ wielomianu: ";
	cin >> stopien;
	int wielkosc = stopien + 1;
	double * a = new double[wielkosc];
	double ** g = new double *[wielkosc];
	for (int i = 0; i < (wielkosc); i++)
	g[i] = new double[wielkosc];
	for (int i = 0; i < (wielkosc); i++)
	for (int j = 0; j < (wielkosc); j++)
	g[i][j] = 0;

	int n;
	cout << "WprowadŸ liczbê punktów: ";
	cin >> n;
	Punkt * tab = new Punkt[n];
	for (int i = 0; i < n; i++) {
	cout << "WprowadŸ punkt x[" << i << "]: ";
	cin >> tab[i].x;
	cout << "WprowadŸ punkt y[" << i << "]: ";
	cin >> tab[i].y;
	//to do
	for (int i = 0; i < (wielkosc); i++)
	for (int j = 0; j < (wielkosc); j++)
	for (int k = 0; k < n; k++)
	g[i][j] += (tab[k].x, (i + j));
	//
	}
	double * p = new double[wielkosc];
	for (int i = 0; i < wielkosc; i++) {
	for (int j = 0; j < n; j++)
	p[i] = tab[j].y*pow(tab[j].x, i);
	}

	if (stopien == 1) {
	double W;
	double * Wa = new double[wielkosc];
	W = g[0][0]*g[1][1] - g[0][1]*g[1][0];
	if (W != 0.) {
	Wa[0] = p[0]*g[1][1] - g[0][1]*p[1];
	Wa[1] = g[0][0]*p[1] - p[0]*g[1][0];
	a[0] = Wa[0] / W;
	a[1] = Wa[1] / W;
	}
	else {
	cout << "Wyznacznik = 0, nie da siê rozwi¹zaæ uk³adu";
	return 0;
	}
	cout << "a0 = " << a[0] << endl;
	cout << "a1 = " << a[1] << endl;
	cout << "Wynik: y=" << a[1] << "*x+" << a[0] << endl;
	}
	if (stopien == 2) {
	double W;
	double * Wa = new double[wielkosc];
	W = g[0][0] * g[1][1] * g[2][2] + g[1][0] * g[2][1] * g[0][2] + g[2][0] * g[0][1] * g[1][2]
	- (g[2][0] * g[1][1] * g[0][2] + g[1][0] * g[0][1] * g[2][2] + g[0][0] * g[1][2] * g[2][1]);
	if (W != 0) {
	Wa[0] = p[0] * g[1][1] * g[2][2] + p[1] * g[2][1] * g[0][2] + p[2] * g[0][1] * g[1][2]
	- (p[2] * g[1][1] * g[0][2] + p[1] * g[0][1] * g[2][2] + p[0] * g[1][2] * g[2][2]);
	Wa[1]= g[0][0] * p[1] * g[2][2] + g[1][0] * p[2] * g[0][2] + g[2][0] * p[0] * g[1][2]
	- (g[2][0] * p[1] * g[0][2] + g[1][0] * p[0] * g[2][2] + g[0][0] * g[1][2] * p[2]);
	Wa[2] = g[0][0] * g[1][1] * p[2] + g[1][0] * g[2][1] * p[0] + g[2][0] * g[0][1] * p[1]
	- (g[2][0] * g[1][1] * p[0] + g[1][0] * g[0][1] * p[2] + g[0][0] * p[1] * g[2][1]);
	for (int i = 0; i < (wielkosc); i++)
	a[i] = Wa[i] / W;
	}
	else {
	cout << "Wyznacznik = 0, nie mo¿na rozwi¹zaæ uk³adu";
	return 0;
	}
	for (int i = 0; i < (wielkosc); i++)
	cout << "a[" << i << "] = " << a[i] << endl;
	cout << "Wynik: y=" << a[2] << "*x^2+" << a[1] << "*x" << a[0] << endl;

	}
	*/
	system("pause");
	return 0;
}