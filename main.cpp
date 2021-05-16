#include <iostream>
#include <stdio.h>    
#include <math.h> 
#include <iomanip>   

using namespace std;

double f(double x){
	return (2 * x * x) / ((x * x) + 4);
}      

double puntoCentrale(double a, double b) {
	double centrale, area;
	centrale = (a + b) /2;
	area = (b - a) * f(centrale);
	return area;
}

double rettangoli(double a, double b, int n){
	double x, sum, h;
	int j;
	h = (b - a) / n;
	x = a + h/2;
	sum = 0.0;
	for(j = 0; j < n; j++){
		sum = sum + h * f(x);
		x += h;
	}
	return sum;
}

double trapezi(double a, double b, int n){
	double x, sum, h;
	int j;
	h = (b - a) / n;
	x = a + h;
	sum = f(a) + f(b);
	for(j = 1; j < n; j++){
		sum += 2 * f(x);
		x += h;
	}
	return sum * (h / 2);
}

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

void confronto(){

	const char separator = ' '; // Separatore tre caselle
  const int wordWidth = 18; // Larghezza di ogni casella contente una stringa (testo)
	const int width = 18; // Larghezza di ogni casella contente un numero (int/double)
	
	double a, b, risultato; 
	int n;
	cout << endl;
	cout << "Inserire limite a dell'integrale: ";
	cin >> a;
	cout << endl;
	cout << "Inserire limite b dell'intergale: ";
	cin >> b;
	cout << endl;
	cout << "Inserire il numero massimo di intervalli: ";
	cin >> n;
	cout << endl;

	// Header della tabella
  cout << "I risultati sono:" << endl;
  cout << left << setw(wordWidth) << setfill(separator) << "Intervalli"; // Iterazioni svolte
  cout << left << setw(wordWidth) << setfill(separator) << "Punto Centrale"; // Math.sqrt()
  cout << left << setw(wordWidth) << setfill(separator) << "Rettangoli"; // Algortimmo Babilonese
  cout << left << setw(wordWidth) << setfill(separator) << "Trapezi"; // Algoritmo Errore
  cout << left << setw(wordWidth) << setfill(separator) << "Cavalieri-Simpson";
  cout << endl;


	for(int i = 0; i < n; i++){
		cout << left << setw(width) << setfill(separator) << i + 1;
		cout << left << setw(width) << setfill(separator) << puntoCentrale(a, b);
		cout << left << setw(width) << setfill(separator) << rettangoli(a, b, i);
		cout << left << setw(width) << setfill(separator) << trapezi(a, b, i);
		cout << left << setw(width) << setfill(separator) << cavalieriSimpson(a, b, i);
		cout << endl;
	}

	cout << "---------------------------------" << endl;
	cout << "Confronto con iterazioni logaritmiche" << endl;
	int confrontoLog[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

	// Header della tabella
  cout << "I risultati sono:" << endl;
  cout << left << setw(wordWidth) << setfill(separator) << "Intervalli"; // Iterazioni svolte
  cout << left << setw(wordWidth) << setfill(separator) << "Punto Centrale"; // Math.sqrt()
  cout << left << setw(wordWidth) << setfill(separator) << "Rettangoli"; // Algortimmo Babilonese
  cout << left << setw(wordWidth) << setfill(separator) << "Trapezi"; // Algoritmo Errore
  cout << left << setw(wordWidth) << setfill(separator) << "Cavalieri-Simpson";
  cout << endl;


	for(int i = 0; i < 9; i++){
		cout << left << setw(width) << setfill(separator) << confrontoLog[i];
		cout << left << setw(width) << setfill(separator) << puntoCentrale(a, b);
		cout << left << setw(width) << setfill(separator) << rettangoli(a, b, confrontoLog[i]);
		cout << left << setw(width) << setfill(separator) << trapezi(a, b, confrontoLog[i]);
		cout << left << setw(width) << setfill(separator) << cavalieriSimpson(a, b, confrontoLog[i]);
		cout << endl;
	}

	cout << "---------------------------------" << endl;
	cout << "Confronto con iterazioni intermedie" << endl;
	int confrontoIntermedio[13] = {1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 75, 100};

	// Header della tabella
  cout << "I risultati sono:" << endl;
  cout << left << setw(wordWidth) << setfill(separator) << "Intervalli"; // Iterazioni svolte
  cout << left << setw(wordWidth) << setfill(separator) << "Punto Centrale"; // Math.sqrt()
  cout << left << setw(wordWidth) << setfill(separator) << "Rettangoli"; // Algortimmo Babilonese
  cout << left << setw(wordWidth) << setfill(separator) << "Trapezi"; // Algoritmo Errore
  cout << left << setw(wordWidth) << setfill(separator) << "Cavalieri-Simpson";
  cout << endl;


	for(int i = 0; i < 13; i++){
		cout << left << setw(width) << setfill(separator) << confrontoIntermedio[i];
		cout << left << setw(width) << setfill(separator) << puntoCentrale(a, b);
		cout << left << setw(width) << setfill(separator) << rettangoli(a, b, confrontoIntermedio[i]);
		cout << left << setw(width) << setfill(separator) << trapezi(a, b, confrontoIntermedio[i]);
		cout << left << setw(width) << setfill(separator) << cavalieriSimpson(a, b, confrontoIntermedio[i]);
		cout << endl;
	}
}

double calcoloSingolo() {
	
	double a, b;

	// Metodo del punto centrale:
	cout << endl;
	cout << "Metodo del punto centrale:" << endl;
	cout << "Inserire limite a dell'integrale: ";
	cin >> a;
	cout << endl;
	cout << "\nInserire limite b dell'intergale: ";
	cin >> b;
	cout << endl;
	double risultatoPuntoCentrale;
	risultatoPuntoCentrale = puntoCentrale(a, b);
	cout << "L'area calcolata con il punto centrale e': " << risultatoPuntoCentrale << endl;
	cout << "-----------------------------------" << endl;
	
	// Metodo dei rettangoli:
	int nRett;;
	cout << "Metodo dei rettangoli:" << endl;
	cout << "Inserire limite a dell'integrale: ";
	cin >> a;
	cout << endl;
	cout << "Inserire limite b dell'intergale: ";
	cin >> b;
	cout << endl;
	cout << "Inserire il numero di rettangoli: ";
	cin >> nRett;
	cout << endl;
	double risultatoRettangoli;
	risultatoRettangoli = rettangoli(a, b, nRett);
	cout << "L'area calcolata con il metodo dei rettangoli e': " << risultatoRettangoli << endl;
	cout << "-----------------------------------" << endl;

	
	// Metodo dei trapezi:
	int nTrap;
	cout << "Metodo dei trapezi:\n";
	cout << "Inserire limite a dell'integrale: ";
	cin >> a;
	cout << endl;
	cout << "\nInserire limite b dell'intergale: ";
	cin >> b;	
	cout << endl;
	cout << "\nInserire il numero di trapezi: ";
	cin >> nTrap;
	cout << endl;
	double risultatoTrapezi;
	risultatoTrapezi = trapezi(a, b, nTrap);
	cout << "L'area calcolata con il metodo dei trapezi e': " << risultatoTrapezi << endl;
	cout << "-----------------------------------" << endl;
	
	// Metodo di Cavalieri-Simpson:
	double aCav, bCav;
	int nCav;
	cout << "Metodo di Cavalieri-Simpson:" << endl;
	cout << "Inserire limite a dell'integrale: ";
	cin >> aCav;
	cout << endl;
	cout << "\nInserire limite b dell'intergale: ";
	cin >> bCav;
	cout << endl;	
	cout << "\nInserire il numero di punti: ";
	cin >> nCav;
	cout << endl;
	double risultatoCavalieri;
	risultatoCavalieri = cavalieriSimpson(aCav, bCav, nCav);
	cout << "L'area calcolata con il metodo Cavalier-Simpson e': " << risultatoCavalieri << endl;
	cout << "-----------------------------------" << endl;

	return 0;
}

double runApp() {
	double scelta;
	cout << endl;
	cout << "Calcola i risultati singolarmente: (inserisci -1 se vuoi saltare, 0 se vuoi continuare)" << endl;
	cin >> scelta;

	if(scelta == 0) {
		calcoloSingolo();
	};

	cout << endl;
	cout << "Confronto tra i risultati: (inserisci -1 se vuoi saltare, 0 se vuoi continuare)" << endl;
	cin >> scelta;
	if(scelta == 0) {
		confronto();
	}

	return 0;
}

int main(int argc, char** argv) {

	runApp();

	return 0;
}
