#include <iostream>
#include <cmath>

using namespace std;

double metodaProstokatow(double, double, unsigned int);
double metodaTrapezow(double, double, unsigned int);
double metodaSimpsona(double, double, unsigned int);

double f(double x) {
	return 2 * tan(x);
}


int main() {
	char next;
	do {
		setlocale(LC_ALL, "");

		double a, b;
		double precision;

		cout << "Podaj punkt a: ";
		cin >> a;
		cout << "Podaj punkt b: ";
		cin >> b;
		cout << "Podaj dok³adnoœæ: ";
		cin >> precision;

		cout << "Wynik ca³kowania (metoda prostok¹tów): " << metodaProstokatow(a, b, precision) << endl;
		cout << "Wynik ca³kowania (metoda trapezów): " << metodaTrapezow(a, b, precision) << endl;
		cout << "Wynik ca³kowania (metoda Simpsona): " << metodaSimpsona(a, b, precision) << endl;

		cout << "Chcesz kontynuowaæ - wpisz t: ";
		cin >> next;
		cout << endl;
	} while (next == 't');

	system("pause");
	return 0;
}

double metodaProstokatow(double a, double b, unsigned int precision) {
	if (b < a) {
		double temp = a;
		a = b;
		b = temp;
	}

	double result = 0.0;
	double dx = (b - a) / precision;
	double at = a;

	for (unsigned int i = 0; i < precision; i++) {
		result += f(at);
		at += dx;
	}

	return result*dx;
}

double metodaTrapezow(double a, double b, unsigned int precision) {
	//pole trapezu (a+b)*h/2
	//tutaj [f(a)+f(b)]/(a-b)/2
	//f(b) = f(a + dx)
	//[f(a)+f(a+dx)]/(a-b)/2


	if (b < a) {
		double temp = a;
		a = b;
		b = temp;
	}

	double result = 0.0;
	double dx = (b - a) / precision;
	double at = a;

	for (unsigned int i = 0; i < precision; i++) {
		result += (f(at) + f(at + dx));
		at += dx;
	}
	return result*dx*0.5;
}

double metodaSimpsona(double a, double b, unsigned int n) {
	if (b < a) {
		double temp = a;
		a = b;
		b = temp;
	}
	if (n == 0)	n = 1;

	double sum = 0.0,
		step = (b - a) / static_cast<double>(n),
		from = a,
		to = a + step;

	for (unsigned int i = 0; i < n; i++) {
		sum += (to - from) / 6.0 * (f(from) + 4.0*f((from + to) / 2.0) + f(to));
		from = to;
		to += step;
	}
	return sum;
}