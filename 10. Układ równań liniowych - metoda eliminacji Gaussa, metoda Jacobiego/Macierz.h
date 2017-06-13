#pragma once

#include <iostream>

using namespace std;

class Macierz{
private:
	
	int **macierz;
	int kolumny, wiersze;

public:

	Macierz();
	Macierz(int, int);
	void uzupelnij_macierz(int *);
	void metoda_eliminacji_Gaussa();
	void wyswietl_macierz();
	~Macierz();
};

Macierz::Macierz(){

}

Macierz::Macierz(int i, int j) {
	kolumny = j;
	wiersze = i;

	macierz = new int*[i];
	for (int a = 0; a < kolumny; a++){
		macierz[a] = new int[wiersze];
	}

	for (int a = 0; a < kolumny; a++){
		for (int b = 0; b < wiersze; b++){
			macierz[a][b] = 0;
		}
	}
}

void Macierz::uzupelnij_macierz(int *tab){
	if (tab == NULL) return;

	int k = 0;
	for (int i = 0; i < kolumny; i++){
		for (int j = 0; j < wiersze; j++){
			macierz[i][j] = tab[k];
			k++;
		}
	}
}

void Macierz::wyswietl_macierz(){
	if (macierz == NULL) return;

	for (int i = 0; i < kolumny; i++){
		for (int j = 0; j < wiersze; j++){
			cout << macierz[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void Macierz::metoda_eliminacji_Gaussa(){
	for (int i = 1; i < kolumny; i++){
		for (int j = 0; j < wiersze; j++){
			macierz[i][j] -= macierz[0][j] * (macierz[0][i] / macierz[0][0]);
		}
	}
}


Macierz::~Macierz() {

}
