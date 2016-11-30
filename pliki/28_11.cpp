#include <iostream>
using namespace std;

int* scal(int* tablica1, int* tablica2, int n1, int n2) {

	int* tablica = new int [n1 + n2];
	int j1 = 0;
	int j2 = 0;
	for (int i = 0; i < n1 + n2; i++) {

		if (j1 == n1) {
			tablica[i] = tablica2[j2];
			j2++;
			continue;
		}
		if (j2 == n2) {
			tablica[i] = tablica1[j1];
			j1++;
			continue;
		}
		if (tablica1[j1] >= tablica2[j2]) {
			tablica[i] = tablica2[j2];
			j2++;
			continue;
		}
		if (tablica1[j1] < tablica2[j2]) {
			tablica[i] = tablica1[j1];
			j1++;
		}
	}
	return tablica;
}



int* wczytajTablice(int n)
{

	int* tablica = new int[n];

	cout << "wartosc" << endl;
	for (int i = 0; i < n; i++)
	{

		cin >> tablica[i];
	}

	return tablica;
}

void wypiszTablica(const int* tablica, int n)
{

	for (int i = 0; i < n; i++)
	{

		cout << tablica[i] << ", ";
	}
	cout << endl;

}

int* pomocnicza(int* wiersz, int i)
{
	int n = 2 * i + 1;
	int* kolejny = new int[n];
	for (int j = 0; j < n; j++) 
	{
		if (j == 0)
		{
			kolejny[j] = wiersz[0];
			continue;
		}
		if (j == n - 1)
		{
			kolejny[j] = wiersz[n - 3];
			continue;
		}
		if (j == 1)
		{
			kolejny[j] = wiersz[0] + wiersz[1];
			continue;
		}
		if (j == n - 2)
		{
			kolejny[j] = wiersz[n - 3] + wiersz[n - 4];
			continue;
		}
		kolejny[j] = wiersz[j - 2] + wiersz[j - 1] + wiersz[j];
	}
	return kolejny;
}

int* trojkat(int a, int b, int c, int d, int n)
{
	int* wynik = new int[2 * n - 1];
	if (n == 1)
	{
		wynik[0] = a;
		return wynik;
	}
	/*if (n == 2)
	{
		wynik[0] = b;
		wynik[1] = c;
		wynik[2] = d;
		return wynik;
	}*/

	int* wynikPom = new int[2 * n - 1];
	wynikPom[0] = b;
	wynikPom[1] = c;
	wynikPom[2] = d;
	for (int i = 2; i < n; i++)
	{
		wynik = pomocnicza(wynikPom, i);
		wynikPom = wynik;
	}
	return wynikPom;
}

int main() {

	/* Zadanie 5.14
	int* tablica1 = wczytajTablice(3);
	int* tablica2 = wczytajTablice(3);
	
	int* tablicaWynikowa = scal(tablica1, tablica2, 3, 3);

	wypiszTablica(tablicaWynikowa,6);
	*/

	/*
	int a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;
	int* wiersz = trojkat(a, b, c, d, n);
	wypiszTablica(wiersz, 2 * n - 1);
	delete[] wiersz;
	*/


	system("pause");
	return 0;
}