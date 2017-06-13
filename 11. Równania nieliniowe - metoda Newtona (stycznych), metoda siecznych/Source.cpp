#include <iostream>
#include <cmath>

using namespace std;

double f(double);

double pochodnaf(double);

double sieczne(double, double, double);

double Newton(double, double, double);

int main() {
	setlocale(LC_ALL, "");
	cout.setf(ios::fixed);
	cout.precision(15);
	double a, b, epsilon;

	cout << "RÓWNANIANIA NIELINIOWE - NEWTON, SIECZNE" << endl;
	cout << "Podaj a: ";
	cin >> a;
	cout << "Podaj b: ";
	cin >> b;
	cout << "Podaj epsilon: ";
	cin >> epsilon;
	cout << "Wynik dla metody Newtona: " << endl;
	Newton(a, b, epsilon);
	cout << "Wynik dla metody siecznych: " << endl;
	sieczne(a, b, epsilon);

	system("pause");
	return 0;
}

double f(double x) {
	return sin(x) - x*x*x;
	//return cos(x) - 3 * x*x;
}

double pochodnaf(double x) {
	return cos(x) - 3*x*x;
	//return -sin(x) - 6 * x;
}

double sieczne(double a, double b, double epsilon) {
	if (b < a) {
		double pom = a;
		a = b;
		b = pom;
	}

	double xn_2 = a,
		xn_1 = b;
	int i = 0;
	while(true){
		double xn = xn_1 - (f(xn_1)*(xn_1 - xn_2)) / (f(xn_1) - f(xn_2));
		if (fabs(f(xn)) < epsilon) {
			cout << "x" << i << " = " << xn << " y = " << f(xn) << std::endl;
			cout << "Zakoñczono na " << i+1 << " iteracji" << endl << endl;
			return xn;
		}
		cout << "x" << i << " = " << xn << " y = " << f(xn) << std::endl;
		xn_2 = xn_1;
		xn_1 = xn;
		i++;
	}
	return xn_1;
}

double Newton(double a, double b, double epsilon){
	if (b < a) {
		double pom = a;
		a = b;
		b = pom;
	}

	double xn_1 = a;

	int i = 0;

	while(true) {
		if (pochodnaf(xn_1) == 0) {
			cout << "Dzielenie przez zero!" << endl;
		}
		else {
			double xn = xn_1 - f(xn_1) / pochodnaf(xn_1);
			if (fabs(f(xn)) < epsilon) {
				cout << "x" << i << " = " << xn << " y = " << f(xn) << std::endl;
				cout << "Zakoñczono na " << i+1 << " iteracji" << endl << endl;
				return xn;
			}
			cout << "x" << i << " = " << xn << " y = " << f(xn) << std::endl;
			xn_1 = xn;
			i++;
		}
		
	}
	return xn_1;

}