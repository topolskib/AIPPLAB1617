#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
using namespace std;

int main()
{
	int liczbaPokeballi;
	int przebyteKilometry;
	int przyrostSzansy = 0;
	double Szansa1 = 0;
	double modyfikatorPrzyrostuSzansy;
	double a; //wylosowana liczba z przedzialu, punkt 4 zadania
	

	cout << "Wprowadz liczbe posiadanych Poke Balli: " << endl;
	cin >> liczbaPokeballi;
	cout << "Wprowadz maksymalna liczbe przebytych kilometrow, potrzebnych do spotkania Pokemona: " << endl;
	cin >> przebyteKilometry;
	cout << "Wprowadz przyrost modyfikatora szansy spotkania Pokemona: " << endl;
	cin >> modyfikatorPrzyrostuSzansy;

	if (liczbaPokeballi < 10 || liczbaPokeballi>50 || przebyteKilometry < 15 || przebyteKilometry>20 || przyrostSzansy > 0.01 || przyrostSzansy < 0) {
		cout << "Wprowadzone dane sa niepoprawne. Program zakonczy dzialanie." << endl;
	}

	srand(liczbaPokeballi);

	for (int i = 1; i <= przebyteKilometry; i++) { // pętla po kolejnych kilometrach

		Szansa1 =((double)rand() / RAND_MAX)*0.8 + przyrostSzansy;	

		if (Szansa1 >= 0.75 || i == przebyteKilometry) {

				for(int j = 1; j <= liczbaPokeballi; j++)
				{
					
					a = double(rand()) / RAND_MAX;
					if (a >= 0.85) {
						cout << "Nasz trener zlapal je wszystkie!" << endl;
						cout << "Trener do zlapania Pokemona zuzyl " << j<< " szt. Poke Balli." << endl;
						cout << "Trener potrzebowal " << i << " km do spotkania poszukiwanego Pokemona." << endl;
						return 0;
					}
					// dla a z przedziałi (0.1, 0.85) nie dzieje się nic

					else if (a <= 0.1 || j == liczbaPokeballi) {
						cout << "Niestety poszukiwany Pokemon uciekl!" << endl;
						cout << "Trener do zlapania Pokemona zuzyl " << j << " szt. Poke Balli." << endl;
						cout << "Trener potrzebowal " << i << " km do spotkania poszukiwanego Pokemona." << endl;
						return 0;
						
					}
					
				}

		}
		if( Szansa1 < 0.75){
			przyrostSzansy += modyfikatorPrzyrostuSzansy;
		}




				
	}
	
	return 0;
}
