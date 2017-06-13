#include <iostream>
#include <math.h>
#include "Punkt.h"
#include <Eigen/Dense>
using Eigen::MatrixXd;
using Eigen::VectorXd;
using namespace std;

double sumaX(int, int, Punkt*);
double sumaY(int, int, Punkt*);
double approx(MatrixXd mg, int degree, double x);

int main(void){
	setlocale(LC_ALL, "");
	int potega = 0;
	int i, j;
	
	int n; // liczba punktów

	double podanyPkt;
	double suma = 0;
	int stopien;

	cout << "WprowadŸ liczbê punktów: ";
	cin >> n;

	Punkt *tab = new Punkt[n];
	
	for (int i = 0; i < n; i++) {
		cout << "WprowadŸ punkt x[" << i << "]: ";
		cin >> tab[i].x;
		cout << "WprowadŸ punkt y[" << i << "]: ";
		cin >> tab[i].y;
	}

	cout << "W jakim punkcie chcesz znaæ wartoœæ: ";
	cin >> podanyPkt;

	cout << "WprowadŸ stopieñ wielomianu: ";
	cin >> stopien;

	stopien++;

	MatrixXd macierzG(stopien, stopien);
	VectorXd macierzRo(stopien);

	potega = 0;
	for (i = 0; i < stopien; i++){
		for (j = 0; j < stopien; j++){
			macierzG(i, j) = sumaX(n, potega, tab);
			potega++;
		}
		potega -= (potega - i - 1);
	}

	for (i = 0; i < stopien; i++){
		macierzRo(i) = sumaY(n, i, tab);
	}

	macierzG = macierzG.inverse();
	macierzG *= macierzRo;

	double wartoscPkt = 0;

	cout << "y=";
	for (int i = stopien - 1; i >= 0 ; i--){
		cout << showpos << macierzG(i) << "x^" <<i;
		wartoscPkt += macierzG(i)*pow(podanyPkt, i);
	}
	cout << endl;
	cout << noshowpos << "Punkt podany przez u¿ytkownika: " << podanyPkt << "\tWartoœæ: " << wartoscPkt << endl;

	double blad = 0, blad_sredniokwadratowy = 0;
	for (int i = 0; i < n; i++){
		blad = (tab[i].y - approx(macierzG, stopien, tab[i].x))*(tab[i].y - approx(macierzG, stopien, tab[i].x));
		blad_sredniokwadratowy += blad;
	}

	blad_sredniokwadratowy = blad_sredniokwadratowy / n;
	cout << "B³¹d œredniokwadratowy = " << blad_sredniokwadratowy << endl;

	system("Pause");
	return 0;
}

double sumaX(int n, int k, Punkt *p){
	double suma = 0;

	for (int i = 0; i < n; i++)
		suma += pow(p[i].x, k);

	return suma;
}

double sumaY(int n, int k, Punkt *p)
{
	double suma = 0;
	for (int i = 0; i < n; i++)
	{
		suma += pow(p[i].x, k) * p[i].y;
	}
	return suma;
}

double approx(MatrixXd mg, int degree, double x)
{
	double result = 0;
	for (int i = 0; i < degree; i++)
	{
		result += mg(i)*pow(x, i);
	}
	return result;
}