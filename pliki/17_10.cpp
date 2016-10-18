#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

int main_2() {
	// Zadanie 2 z zadań przygotowawczych 2
	
	int a; 
	int suma = 0;
	
	// Wpisujemy liczbę z klawiatury, dodajemy ją do sumy
	cout << "Wpisz liczbe: " <<  endl;
	cin >> a;
	suma += a;
	while (a > 0) { // Jeśli wpisana liczba jest większa od 0 (warunek w while), to powtarzamy czynność
		cout << "Wpisz liczbe: " << endl;
		cin >> a;
		suma += a;
	}

	cout << suma;
	system("pause");
	return 0;
}

int main() {
	// Zadanie 9 z zadań przygotowawczych 2

	int k, fib1=1, fib2=1, fib;
	cin >> k;
	
	if (k < 0) {
		cout << "Blad" << endl;
		exit(1);
	}
	
	if (k == 0 || k == 1) { // oddzielne rozpatrzenie przypadków 0 i 1
		cout << "F(" << k << ") = 1" << endl;
		return 0;
	}
	for (int i = 2; i <= k; i++) { 
		/*
		W pętli zaczynamy od i = 2 i kończymy na k aby odzwierciedlić to, że obsłużyliśmy już przypadki dla 0,1.
		Nie ma to oczywiście wpływu na wynik, to samo otrzymamy dla int i = 1; i<k;... , ale w tej wersji jest to 
		odrobinę bardziej intuicyjne.		
		Samo liczenie wyrazów ciągu przebiega następująco: mamy zapisane w pamięci dwa wyrazy ciągu - aktualny (fib2) i poprzedni (fib1). W celu policzenia kolejnego wyrazu musimy wyznaczyć ich sumę (to będzie nowy wyraz aktualny), a wyraz aktualny przenieść do zmiennej przechowującej wyraz poprzedni.
		
		Rozwiązanie bez zmiennej pomocniczej (warto przeanalizować dlaczego to działa):
		
		fib2 = fib1 + fib2
		fib1 = fib2 - fib1
		
		*/
		
		fib = fib1;
		fib1 = fib2;
		fib2 = fib + fib2;
	}
	cout << "F(" << k << ") = "<< fib2 << endl;
	system("pause");
	return 0;
}

int main_21()
{
	// zadanie 2 z mojej strony
	
	int k;
	int wynik;
	int kiedy = 0; // zmienna odpowiadająca za wskazanie pierwszego wypadnięcia 6 

	cout << "wprowadz liczbe" << endl;
	cin >> k;

	srand(time(0));
	rand();

	int licznik = 0; // zmienna odpowiadająca za zliczanie wypadnięć 6

	for (int i = 0; i < k; i++)
	{

		wynik = rand() % 6; // reszta z dzielenia przez 6 daje nam liczbę ze zbioru {0,1,2,3,4,5}...
		wynik++; // więc dodajemy 1

		if(wynik == 6) 
		{
			licznik++; // jeśli wyrzuciliśmy 6, to zwiększamy licznik o 1
			
			
			if (kiedy == 0) // ponadto, jeśli jeszcze nie wypadła 6, to musimy zapisać że wypadła pierwszy raz
			{
				kiedy = i + 1; // Ponieważ i jest indeksowane od 0, to musimy dodać 1 aby dostać numer rzutu.
							   // Po pierwszym wyrzuceniu 6 zmienna 'kiedy' przyjmie wartość większą od 0, więc 
							   // nie wejdziemy już do tego ifa i nie zmienimy wartości tej zmiennej
			}
		}
	}


	cout << licznik << endl;
	cout << kiedy << endl;

	system("pause");
	return 0;
}


int main() {
	// zadanie 3 z mojej strony
	
	
	int k; // ilosć strzelców
	int n; // ilość strzałów na strzelca
	double p; // początkowe prawdopobobieństwo trafienia
	int suma = 0;

	cin >> k;
	cin >> n;
	cin >> p;
	double p_pom = p; // Tworzymy zmienną która będzie używana jako prawdopodobieństwo w trakcie oddawania strzałów.
					  // Jest to potrzebne, ponieważ dla każdego strzelca prawdopodobieństwo trafienia będzie się zmieniać,
					  // a chcemy żeby kolejny strzelec startował znowu z bazowym prawdopobieństwem.

	srand(time(0));
	double w;
	bool wynik;
	int maksimum = 0;
	int najlepszy = 0;
	for (int j = 1; j <= k; j++) // Zewnętrzna pętla przebiega po strzelcach. 
	{
		for (int i = 1; i <= n; i++) // Wewnętrzna pętla przebiega po strzałach dla ustalonego strzelca
		{
			w = double(rand()) / RAND_MAX; // 'w' przyjmuje wartości rzeczywiste z zakresu [0,1)
			wynik = (w <= p_pom); // Tworząc warunek 'w<p_pom' sprawiamy, że zmienna 'wynik' będzie przyjmowała wartosć true 
			                      // z prawdopodobieństwem równym p_pom
			suma += int(wynik); // Rzutujemy zmienną 'wynik' na typ int (teraz przyjmuje 0 lub 1) i dodajemy do sumy 
								// dla aktualnego strzelca.

			if (wynik == 0)
			{
				p_pom *= 0.95; // Jeśli spudłował, to zmniejszamy prawdopobieństwo trafienia
			}
			else p_pom *= 1.03; // W przeciwnym przypadku zwiększamy
			if (p_pom > 1)
			{
				p_pom = 1; // Poprawka na to, żeby prawdopodobienstwo nie było większe od 1
			}
		}
		cout << suma << endl;
		if (suma > maksimum) { // Jeżeli wynik dla strzelca jest większy niż aktualnie zapisany wynik, to ...			
			maksimum = suma; // ... aktualizujemy największy wynik oraz ...
			najlepszy = j; // ... aktualizujemy numer strzelca z najlepszym wynikiem.
		}
		suma = 0; // Skończyliśmy symulację dla aktualnego strzelca, więc zmienne 'suma' i 'p_pom' musimy przywrócić do 
				  // stanu początkowego.
		p_pom = p;
		
	}
	
	cout << endl << maksimum << endl;
	cout << endl << najlepszy << endl;
	system("pause");
	return 0;
}
