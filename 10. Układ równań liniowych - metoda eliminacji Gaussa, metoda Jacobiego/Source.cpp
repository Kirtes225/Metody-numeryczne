#include <iostream>
#include "Macierz.h"
#include <Eigen/Dense>
using namespace std;

using Eigen::MatrixXd;
using Eigen::VectorXd;


int main(void){
	setlocale(LC_ALL, "");
	cout << "!MACIERZE S¥ WYPE£NIANE W KODZIE PROGRAMU!" << endl;
	cout << "Zmieniaj¹c macierze i ich wymiary nie zapomnij zmieniæ macierzy L, D, U w metodzie Jacobiego" << endl;
	cout << endl;
	cout << "METODA ELIMINACJI GAUSSA: " << endl;
	int iloscWierszy, iloscKolumn;

	//WYMIARY MACIERZY
	iloscWierszy = 3;
	iloscKolumn = 4;
	/////////////////////////////////////////////////////////////////////////

	MatrixXd A(iloscWierszy, iloscKolumn);
	VectorXd x(iloscWierszy);

	//wype³nienie macierzy A,  3x4
	A(0, 0) = 1;	A(0, 1) = 2;	A(0, 2) = 1;	A(0, 3) = 8;
	A(1, 0) = 3;	A(1, 1) = 1;	A(1, 2) = 1;	A(1, 3) = 8;
	A(2, 0) = 1;	A(2, 1) = 3;	A(2, 2) = 1;	A(2, 3) = 10;

	double tmp;

	int etap = 1;

	for (int j = 0; j < iloscWierszy; j++){
		for (int i = 1; i < iloscWierszy; i++){
			if (j == 1 && i == 1)i++;
			tmp = A(i, j) / A(j, j);

			
			//tworzenie macierzy górnej trójk¹tnej
			for (int k = 0; k < iloscKolumn; k++)
				A(i, k) -= A(j, k) * tmp;

			cout << "Tworzenie macierzy górnej trójk¹tnej - etap: " << etap << endl;
			cout << A << endl << endl;
			etap++;
			if (A(1, 0) == 0 && A(2, 0) == 0 && A(2, 1) == 0) 
				break;
		}
		if (A(1, 0) == 0 && A(2, 0) == 0 && A(2, 1) == 0) 
			break;
	}

	x(2) = A(2, 3) / A(2, 2);
	x(1) = (A(1, 3) - A(1, 2)*x(2)) / A(1, 1);
	x(0) = (A(0, 3) - A(0, 2)*x(2) - A(0, 1)*x(1)) / A(0, 0);

	cout << "Rozwi¹zanie: " << endl;
	cout << x << endl;
	cout<< endl;

	cout << "METODA JACOBIEGO: " << endl;

	//WYMIARY MACIERZY
	iloscWierszy = 3;
	iloscKolumn = 3;
	////////////////////////////////////////////
	
	//wype³nianie macierzy A, 3x3 
	A(0, 0) = 3;	A(0, 1) = 1;	A(0, 2) = 1;
	A(1, 0) = 0;	A(1, 1) = 5;	A(1, 2) = 1;
	A(2, 0) = 1;	A(2, 1) = 1;	A(2, 2) = 6;

	//wype³nianie macierzy (wektora) b, 3x1
	VectorXd b(3);
	b(0) = 5;
	b(1) = 6;
	b(2) = 8;

	MatrixXd L(3, 3), D(3, 3), U(3, 3);
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			L(i, j) = 0;
			D(i, j) = 0;
			U(i, j) = 0;
		}
	}

	//macierz dolna trójk¹tna
	L(1, 0) = A(1, 0);
	L(2, 0) = A(2, 0);
	L(2, 1) = A(2, 1);

	//macierz diagonalna
	D(0, 0) = A(0, 0);
	D(1, 1) = A(1, 1);
	D(2, 2) = A(2, 2);

	//macierz górna trójk¹tna
	U(0, 1) = A(0, 1);
	U(0, 2) = A(0, 2);
	U(1, 2) = A(1, 2);

	VectorXd x0(3), x1(3), x2(3);
	x0(0) = 0; x0(1) = 0; x0(2) = 0;

	cout << "Wektor x0 : " << endl;
	cout << x0 << endl << endl;


	cout << "Wektor x1 : " << endl;
	x1 = (-D.inverse())*(L + U)*x0 + D.inverse()*b;
	cout << x1 << endl << endl;

	cout << "Wektor x2 : " << endl;
	x2 = (-D.inverse())*(L + U)*x1 + D.inverse()*b;
	cout << x2 << endl << endl;

	system("Pause");
	return 0;
}