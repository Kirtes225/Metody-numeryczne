#include <iostream>

using namespace std;

double gaussKwadratura2(double, double);
double gaussKwadratura4(double, double);
double przykladGaussKwadratura2(double, double);
double przykladGaussKwadratura4(double, double);
double funkcjaPrzyklad(double);
double funkcja(double);

int main() {
	setlocale(LC_ALL, "");
	//DLA DWÓCH WÊZ£ÓW <W PDF, W TABELI to N = 1, k = 0; 1>
	//DLA CZTERECH WÊZ£ÓW <W PDF, W TABELI to N = 3, k = 0; 1; 2; 3>
	double aPrzyklad = 1., bPrzyklad = 2.;
	cout << "Wynik dla ca³ki 1/x metod¹ kwadratury Gaussa - 2 wêz³y: " << przykladGaussKwadratura2(aPrzyklad, bPrzyklad) << endl;
	cout << "Wynik dla ca³ki 1/x metod¹ kwadratury Gaussa - 4 wêz³y: " << przykladGaussKwadratura4(aPrzyklad, bPrzyklad) << endl;
	double a, b;
	cout << "Podaj punkt a: ";
	cin >> a;
	cout << "Podaj punk b: ";
	cin >> b;
	cout << "Ca³kowanie za pomoc¹ kwadratury Gaussa dla dwóch wêz³ów:" << gaussKwadratura2(a, b) << endl;
	cout << "Ca³kowanie za pomoc¹ kwadratury Gaussa dla czterech wêz³ów:" << gaussKwadratura4(a, b) << endl;
	cout << endl;
	system("pause");
	return 0;
}

double funkcjaPrzyklad(double x) {
	return 1 / x;
}

double funkcja(double x) {
	return 2 * x*x;
}

double gaussKwadratura2(double a, double b)
{
	if (b < a) {
		double pom = a;
		a = b;
		b = pom;
	}

	const int kwadratura = 2;

	double x[kwadratura] = { 0.577350, -0.577350 },
		A[kwadratura] = { 1, 1 };
	double srednia = (a + b)*0.5,
		dlugosc = (b - a)*0.5,
		suma = 0.;

	for (int k = 0; k < kwadratura; ++k) {
		double t = srednia + dlugosc*x[k];
		suma += A[k] * funkcja(t);
	}

	return suma*dlugosc;
}

double gaussKwadratura4(double a, double b)
{
	if (b < a) {
		double pom = a;
		a = b;
		b = pom;
	}

	const int kwadratura = 4;

	double x[kwadratura] = { -0.861136, -0.339981, 0.339981, 0.861136 },
		A[kwadratura] = { 0.347855, 0.652145, 0.652145, 0.347855 };
	double srednia = (a + b)*0.5,
		dlugosc = (b - a)*0.5,
		suma = 0.;

	for (int k = 0; k < kwadratura; ++k) {
		double t = srednia + dlugosc*x[k];
		suma += A[k] * funkcja(t);
	}

	return suma*dlugosc;
}

double przykladGaussKwadratura2(double a, double b)
{
	if (b < a) {
		double pom = a;
		a = b;
		b = pom;
	}

	const int kwadratura = 2;

	double x[kwadratura] = { 0.577350, -0.577350 },
		A[kwadratura] = { 1, 1 };
	double srednia = (a + b)*0.5,
		dlugosc = (b - a)*0.5,
		suma = 0.;

	for (int k = 0; k < kwadratura; ++k) {
		double t = srednia + dlugosc*x[k];
		suma += A[k] * funkcjaPrzyklad(t);
	}

	return suma*dlugosc;
}

double przykladGaussKwadratura4(double a, double b)
{
	if (b < a) {
		double pom = a;
		a = b;
		b = pom;
	}

	const int kwadratura = 4;

	double x[kwadratura] = { -0.861136, -0.339981, 0.339981, 0.861136 },
		A[kwadratura] = { 0.347855, 0.652145, 0.652145, 0.347855 };
	double srednia = (a + b)*0.5,
		dlugosc = (b - a)*0.5,
		suma = 0.;

	for (int k = 0; k < kwadratura; ++k) {
		double t = srednia + dlugosc*x[k];
		suma += A[k] * funkcjaPrzyklad(t);
	}

	return suma*dlugosc;
}