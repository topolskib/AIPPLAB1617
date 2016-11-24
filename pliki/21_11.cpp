#include <iostream>
using namespace std;

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

		cout << tablica[i]<< ", ";
	}
	cout << endl;

}

int* sortuj(int* tablica, int n, int k)
{
	int* tablica_pom = new int[k];
	
	for (int i = 0; i < k; i++)
	{
		tablica_pom[i] = 0;
	}

	int wartosc;
	for (int i = 0; i < n; i++)
	{
		wartosc = tablica[i];

		tablica_pom[wartosc - 1]++;

	}

	int* tablica_posortowana = new int[n];
	int pomocnicza=0;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < tablica_pom[i]; j++)
		{
			tablica_posortowana[pomocnicza] = i + 1;
			pomocnicza++;
		}

	}
	delete[] tablica_pom;

	return tablica_posortowana;
}

int najwieksza(const int* tablica, int n) {
	int pom = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (tablica[i] > pom && tablica[i]<0) pom = tablica[i];
	}
	if (pom == INT_MIN) return 0;
	else return pom;
}

void podnies(int* tablica, int n) {
	int pom = najwieksza(tablica, n);
	if (pom < 0) {
		for (int i = 0; i < n; i++) {
			tablica[i] -= pom;
		}
	}
}

int naprawde_podnies(int* tablica, int n) {
	int licznik = 0;
	while (najwieksza(tablica, n) < 0) {
		podnies(tablica, n);
		licznik++;
	}
	return licznik;
}

void sort(int*tab, int n)
{
	int pom;
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (tab[j] > tab[j + 1])
			{
				pom = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = pom;
			}
		}
	}
}

int main() {
	
	int n;
	cout << "wielkosc" << endl;
	cin >> n;
	int* tablica = wczytajTablice(n);
	//cout << najwieksza(tablica, n) << endl;
	/*podnies(tablica, n);
	wypiszTablica(tablica, n);
	int ile_podniesien = naprawde_podnies(tablica, n);
	cout << ile_podniesien << endl;*/
	sort(tablica, n);
	wypiszTablica(tablica, n);
	delete[] tablica;

	/* Do zadania o sortowaniu kube³kowym

	int n;
	cout << "wielkosc" << endl;
	cin >> n;

	int k;
	cout << "max wartosc" << endl;
	cin >> k;

	int* tablica = wczytajTablice(n);

	wypiszTablica(tablica, n);

	int* tablica_posortowana = sortuj(tablica, n, k);

	wypiszTablica(tablica_posortowana, n);

	delete[] tablica;
	delete[] tablica_posortowana;
	*/



	return 0;
}