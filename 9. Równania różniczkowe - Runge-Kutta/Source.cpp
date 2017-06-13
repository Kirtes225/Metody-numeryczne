#include <iostream>
#include <cmath>

using namespace std;

double f(double, double);

double rk2(double, double, double);

double rk4(double, double, double);

int main() {
	setlocale(LC_ALL, "");

	double a, b, h;
	
	double y0;
	cout.precision(10);
	cout << "WprowadŸ pocz¹tek przedzia³u (a): ";
	cin >> a;
	cout << "WprowadŸ koniec przedzia³u (b): ";
	cin >> b;
	cout << "Podaj krok: ";
	cin>>h;

	const int N = (b - a) / h;

	cout << "WprowadŸ y0: ";
	cin >> y0;
	cout << endl;

	double y = y0, x = a;
	cout << "Metoda Rungego-Kutty (RK2): " << endl << "x = " << x << " y = " << y << endl;
	for (int i = 0; i < N; ++i) {
		y += h*rk2(x, y, h);
		x += h;
		cout << "x = " << x << " y = " << y << endl;
	}

	cout << endl;

	y = y0, x = a;
	cout << "Metoda Rungego-Kutty (RK4): " << endl << "x = " << x << " y = " << y << endl;
	for (int i = 0; i < N; ++i) {
		y += h*rk4(x, y, h);
		x += h;
		cout << "x = " << x << " y = " << y << endl;
	}


	system("pause");
	return 0;
}

double f(double x, double y) {
	return (y - x*x);
}

double rk2(double x, double y, double h) {
	double k[2];
	k[0] = f(x, y);
	k[1] = f(x + h, y + h*k[0]);
	return 0.5*(k[0] + k[1]);
}

double rk4(double x, double y, double h) {
	double k[4];
	k[0] = f(x, y);
	k[1] = f(x + 0.5*h, y + 0.5*h*k[0]);
	k[2] = f(x + 0.5*h, y + 0.5*h*k[1]);
	k[3] = f(x + h, y + h*k[2]);
	return (k[0] + 2.0*k[1] + 2.0*k[2] + k[3]) / 6.0;
}
