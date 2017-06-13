#include <iostream>

using namespace std;


//funkcje
double funkcja1(double x1, double x2){
	return 2 * x1 + x2*x2 - 6;
}

double funkcja2(double x1, double x2){
	return x1*x2 - 2;
}

//pochodne cz¹stkowe
double pochodna_po_x1_fun1(double x1, double x2){
	return 2;
}

double pochodna_po_x2_fun1(double x1, double x2){
	return 2 * x2;
}

double pochodna_po_x1_fun2(double x1, double x2){
	return x2;
}
double pochodna_po_x2_fun2(double x1, double x2){
	return x1;
}

void obliczenieUkladu(double tabX0[2], double wynik[2]){
	double jakobian[2][2];
	
	double detJakobiana = pochodna_po_x1_fun1(tabX0[0], tabX0[1])*pochodna_po_x2_fun2(tabX0[0], tabX0[1]) 
		- (pochodna_po_x2_fun1(tabX0[0], tabX0[1])*pochodna_po_x1_fun2(tabX0[0], tabX0[1]));

	jakobian[0][0] = pochodna_po_x2_fun2(tabX0[0], tabX0[1]);
	jakobian[0][1] = -pochodna_po_x2_fun1(tabX0[0], tabX0[1]);
	jakobian[1][0] = -pochodna_po_x1_fun2(tabX0[0], tabX0[1]);
	jakobian[1][1] = pochodna_po_x1_fun1(tabX0[0], tabX0[1]);
	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			jakobian[i][j] *= (1 / detJakobiana);

	double F[2] = { funkcja1(tabX0[0], tabX0[1]), funkcja2(tabX0[0], tabX0[1]) };
	double mnozenie[2] = { jakobian[0][0] * F[0] + jakobian[0][1] * F[1], jakobian[1][0] * F[0] + jakobian[1][1] * F[1] };
	wynik[0] = tabX0[0] - mnozenie[0];
	wynik[1] = tabX0[1] - mnozenie[1];
}

int main(){
	setlocale(LC_ALL, "");
	
	double tabX0[2] = {2, 2};

	int iteracje = 1;

	double wynik[2];

	for (int i = 0; i < 10; i++){
		obliczenieUkladu(tabX0, wynik);
		cout << "Iteracja nr: " << iteracje << endl;
		cout << wynik[0] << endl;
		cout << wynik[1] << endl;
		tabX0[0] = wynik[0];
		tabX0[1] = wynik[1];
		iteracje++;
	}
	system("pause");
}