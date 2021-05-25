#include <iostream>
#include <stdio.h>    
#include <math.h> 
#include <iomanip>

// Definizione costante PI,
// utilizzata per convertire l'argomento della funzione cos()
#define PI 3.14159265

// Definizioni costanti calcolati nella risposta
// al quesito numero 4, in seguito alla definizione
// dell'equazione 4
#define omega 1.535e10
#define k 51.166
#define Eeff 6.137
#define c 3e8

using namespace std;

// Definizione della funzione integranda
// double f(double x, double t){
// 	return Eeff * cos(((k * x) - (omega * t)) * PI / 180.0);
// }  
double f(double t){
	return Eeff * cos(((k * t * c) - (omega * t)) * PI / 180.0);
}   

// Metodo di Cavalieri-Simpson
double cavalieriSimpson(double a, double b, int n){
	double h, s, sum, x;
	int j;
	h = (b - a) / n;
	s = h / 2;
	sum = f(a) + f(b) + 4 * f(a + s);
	x = a + h;
	for(j = 1; j < n; j++){
		sum = sum + 2 * f(x) + 4 * f(x + s);
		x += h;
	}
	return sum * (h / 6);
}

int main(int argc, char** argv) {

	double a, b;
	int n;
	cout << "Metodo di Cavalieri-Simpson:" << endl;
	cout << "Inserire limite a dell'integrale: ";
	cin >> a;
	cout << endl;
	cout << "\nInserire limite b dell'intergale: ";
	cin >> b;
	cout << endl;	
	cout << "\nInserire il numero di punti: ";
	cin >> n;
	cout << endl;
	double risultatoCavalieri;
	risultatoCavalieri = cavalieriSimpson(a, b, n);
	cout << "L'area calcolata con il metodo Cavalier-Simpson e': " << risultatoCavalieri << endl;
	cout << "-----------------------------------" << endl;

	return 0;
}