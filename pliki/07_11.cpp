#include<iostream>
#include <cmath>

using namespace std;

struct FunkcjaKwadratowa {
	double a;
	double b;
	double c;
};

FunkcjaKwadratowa pochodna(FunkcjaKwadratowa f, int &n) {
	FunkcjaKwadratowa fp;
	fp.a = 0;
	fp.b = 2 * f.a;
	fp.c = f.b;
	if (fp.b != 0) n = 2;
	if (fp.b == 0 && fp.c != 0) n = 1;
	if (fp.b == 0 && fp.c == 0) n = 0;
	return fp;
}

void wypisz(FunkcjaKwadratowa f1) {
	cout << f1.a << "x^2 + " << f1.b << "x + " << f1.c << endl;
}

struct Okrag
{
	double x;
	double y;
	double r;
};

int zliczPunkty(Okrag okr)
{
	int x_lo = okr.x - okr.r;
	int x_hi = okr.x + okr.r + 1;
	int y_lo = okr.y - okr.r;
	int y_hi = okr.y + okr.r + 1;
	int iloscpkt = 0;
	for (int i = x_lo; i <= x_hi; i++)
	{
		for (int j = y_lo; j <= y_hi; j++)
		{
			if (((okr.x - i)*(okr.x - i) + (okr.y - j)*(okr.y - j)) <= okr.r*okr.r) iloscpkt++;
		}
	}
	return iloscpkt;
}

int silnia(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n*silnia(n - 1);
	}
}

int potega(int n) {
	int pom;
	if (n == 0) {
		return 1;
	}

	if (n % 2 == 0) {
		pom = potega(n / 2);
		return pom*pom;
	}

	else {
		return 2 * potega(n - 1);
	}

}

int Stycznosc(Okrag o1, Okrag o2) {
	if ((o1.r + o2.r)*(o1.r + o2.r) < ((o1.x - o2.x)*(o1.x - o2.x) + (o1.y - o2.y)*(o1.y - o2.y))) {
		return 0;
	}
	return 1;
}


int main() {
	
    // Zadanie z przecinaniem się okręgów - zachęcam do dokończenia
	Okrag kolo = { 0,0,1 };
	Okrag kolo2 = { 3,3,4 };

	cout << Stycznosc(kolo, kolo2) << endl;
	system("pause");
	return 0;
    
    
	/*int n=5;
	FunkcjaKwadratowa f2 = { 5,3,1 };
	FunkcjaKwadratowa wynik;
	wynik = pochodna(f2, n);
	wypisz(wynik);
	cout << n << endl;*/
	/* 
	 
	int iloscPkt = zliczPunkty(kolo);
	cout << iloscPkt << endl << endl;
	system("pause");

	cout << silnia(5) << endl;
	system("pause");
	return 0;
	 */

	/*cout << potega(5) << endl;
	system("pause");
	return 0;*/

}
