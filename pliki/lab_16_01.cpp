#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
using namespace std;


double** tworzMacierz(int n, int m)
{
	double** M = new double*[n];
	for (int i = 0; i<n; ++i)
		M[i] = new double[m];
	return M;
}
// wypelnia macierz losowymi wartosciami z przedzialu [0,1]
void wypelnijMacierz(double** A, int n, int m)
{
	for (int i = 0; i<n; ++i)
	{
		for (int j = 0; j<m; ++j)
			A[i][j] = rand() / (double)RAND_MAX;
	}
}

// kasuje macierz z pamieci
void kasujMacierz(double** A, int n, int m)
{
	for (int i = 0; i<n; ++i)
		delete[] A[i];
	delete[] A;
}
// wypisuje macierz na ekran
void wypiszMacierz(double** A, int n, int m)
{
	for (int i = 0; i<n; ++i)
	{
		for (int j = 0; j<m; ++j)
			cout << " "  << A[i][j];
		cout << endl;
	}
}

double ** dodajWiersz(double** A, int n, int m, int w) {

	double ** dodana = tworzMacierz(n + 1, m);
	double * srednia = new double[m];
	double suma = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			suma += A[j][i];
		}
		srednia[i] = suma / n;
		suma = 0;
	}

	for (int i = 0; i < n + 1; i++) {

		if (i < w) {
			for (int j = 0; j < m; j++) {
				dodana[i][j] = A[i][j];
			}
		}

		if (i == w) {
			for (int j = 0; j < m; j++) {
				dodana[i][j] = srednia[j];
			}
		}

		if (i > w) {
			for (int j = 0; j < m; j++) {
				dodana[i][j] = A[i - 1][j];
			}
		}

	}
	return dodana;
}

double** usunWiersz(double**A, int w, int k, int e) {

	double ** odjeta = tworzMacierz(w - 1, k);

	for (int i = 0; i < w - 1; i++) {

		if (i < e) {
			for (int j = 0; j < k; j++) {
				odjeta[i][j] = A[i][j];
			}
		}

		if (i >= e) {
			for (int j = 0; j < k; j++) {
				odjeta[i][j] = A[i + 1][j];
			}
		}
	}
	return odjeta;
}

double **zerujDolnyTrojkat(double**A, int w, int k) {

	double** zero = tworzMacierz(w, k);

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < k; j++) {
			if (i > j) {
				zero[i][j] = 0;
			}
			else
				zero[i][j] = A[i][j];
		}
	}
	return zero;
}

bool diagonalnieDominujaca(double** A, int w, int k) {

	int suma = 0;
	for (int i = 0; (i < w & i < k); i++) {
		for (int j = 0; j < k; j++) {

			if (i != j) {
				suma += A[i][j];
			}

		}
		if (suma > A[i][i]) {
			return false;
		}
		suma = 0;
	}
	return true;
}


double **odbicieKolumnowe(double**A, int w, int k, int o) {
	int roznica = 0;
	int odleglosc = min(o, k - 1 - o);
	int szerokoscNowej = 2 * odleglosc + 1;
	int indeksOdpowiadajacy, indeksWNowejMacierzy;
	double ** odbita = tworzMacierz(w, szerokoscNowej);
	for (int i = 0; i < k; i++) {
		roznica = i - o; // odleglosc aktualnej kolumny od punktu symetrii
		indeksOdpowiadajacy = i - 2 * roznica; // jest to numer indeksu symetryczny wzglêdem danego `o`
		indeksWNowejMacierzy = odleglosc + roznica; // jest to indeks tej kolumny nowej macierzy do której ewentualnie skopiujemy aktualny wiersz. 
													// Warto zauwa¿yæ, ¿e `odleglosc` to srodek nowej macierzy, wiêc musimy tylko przesun¹æ siê o wartosc `roznica`
		if ((indeksOdpowiadajacy < 0) || (indeksOdpowiadajacy >= k)) { // sprawdzamy, czy ten symatryczny indeks nie wychodzi poza granice macierzy. Jeœli tak, to wiemy ¿e nie zostanie on w³¹czony do nowej macierzy 
			continue;
		}
		for (int j = 0; j < w; j++) {
			odbita[j][indeksWNowejMacierzy] = A[j][indeksOdpowiadajacy];
		}
	}
	return odbita;
}

int main() {

	/*double** macierz = tworzMacierz(2, 2);
	wypelnijMacierz(macierz, 2, 2);
	wypiszMacierz(macierz, 2, 2);
	//double**odjeta=usunWiersz(macierz, 2, 2, 1);
	//wypiszMacierz(odjeta, 1, 2);
	kasujMacierz(macierz, 2, 2);
	//kasujMacierz(odjeta, 2, 2);
	*/
	/*double** macierz = tworzMacierz(4, 5);
	wypelnijMacierz(macierz, 4, 5);
	wypiszMacierz(macierz, 4, 5);
	double ** zero = zerujDolnyTrojkat(macierz, 4, 5);
	wypiszMacierz(zero, 4, 5);
	*/

	/*double** macierz = tworzMacierz(6, 5);
	for (int i = 0; i < 6;i++) {
	for (int j = 0;j < 5;j++) {

	if (i == j) {
	macierz[i][j] = 10;
	}
	else {
	macierz[i][j] = 1;
	}
	}
	}

	wypiszMacierz(macierz, 6, 5);
	cout << diagonalnieDominujaca(macierz, 6, 5) << endl;
	*/

	double** macierz = tworzMacierz(2, 5);
	wypelnijMacierz(macierz, 2, 5);
	wypiszMacierz(macierz, 2, 5);
	cout << endl;
	double** odbita = odbicieKolumnowe(macierz, 2, 5, 2);

	wypiszMacierz(odbita, 2, 5);

	double** odbita2 = odbicieKolumnowe(macierz, 2, 5, 3);

	cout << endl;
	wypiszMacierz(odbita2, 2, 3);

	kasujMacierz(macierz, 2, 5);
	kasujMacierz(odbita, 2, 5);
	kasujMacierz(odbita2, 2, 3);

	return 0;
}