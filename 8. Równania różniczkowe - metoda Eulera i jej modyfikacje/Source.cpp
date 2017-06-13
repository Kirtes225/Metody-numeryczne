#include <iostream>
#include <cstdlib>

using namespace std;

double f(double x, double y);
double euler(double*, double, double, int);
double heume(double*, double, double, int);
double modeuler(double*, double, double, int);
void oblicz(double(*fun)(double*, double, double, int));

int main() {
	setlocale(LC_ALL, "");

	int wybor;
	
	cout << "Równania ró¿niczkowe - Euler, Heume i modyfikacja Eulera" << endl;
	cout << "[0] - Euler" << endl << "[1] - Heume" << endl << "[2] - modyfikacja metody Eulera" << endl;
	cout << "WprowadŸ liczbê: ";
	cin >> wybor;
	cout << endl;
	switch (wybor) {
	case 0:
		cout << "Wybrano metodê Eulera" << endl;
		oblicz(&euler);
		break;
	case 1:
		cout << "Wybrano metodê Heume" << endl;
		oblicz(&heume);
		break;
	case 2:
		cout << "Wybrano zmodyfikowan¹ metodê Eulera" << endl;
		oblicz(&modeuler);
		break;
	default:
		cout << "Z³a liczba" << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}

double f(double x, double y) {
	return pow(x, 2) + y;
}

double euler(double* y, double x, double h, int i) {
	return y[i] = y[i - 1] + (h*f(x, y[i - 1]));
}

double heume(double* y, double x, double h, int i) {
	double fk = f(x, y[i - 1]);
	return y[i - 1] + (h*0.5*(fk + f(x + h, y[i - 1] + h*fk)));
}

double modeuler(double* y, double x, double h, int i) {
	return y[i - 1] + (h*(f(x + (h / 2), y[i - 1] + (h*0.5*f(x, y[i - 1])))));
}

void oblicz(double(*fun)(double*, double, double, int))
{
	int liczbaPodzialow; //odpowiednik "kroku"
	double a, b, ya;

	cout << "Podaj pocz¹tek przedzia³u - a: ";
	cin >> a;
	cout << "Podaj koniec przedzia³u - b: ";
	cin >> b;
	cout << "Podaj liczbê podzia³ów - odpowiednik h: ";
	cin >> liczbaPodzialow;
	cout << "Podaj y(a): ";
	cin >> ya;
	cout << endl;
	if (!cin.good() || liczbaPodzialow <= 0) {
		cout << "Nie podano liczby lub liczba podzia³ów jest mniejsza lub równa 0";
		return;
	}
	if (a>b){
		double tmp = a;
		a = b;
		b = tmp;
	}

	double* y = new double[liczbaPodzialow + 1];
	y[0] = ya;
	double h = (b - a) / (double)liczbaPodzialow;
	
	for (int i = 1; i <= liczbaPodzialow; i++){
		double x = a + (h*(double)(i - 1));
		y[i] = (*fun)(y, x, h, i);
		cout << "y(" << x + h << ") = " << y[i] << endl;
	}

	delete[] y;

	return;
}