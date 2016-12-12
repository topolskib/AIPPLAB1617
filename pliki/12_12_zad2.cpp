#include <iostream>

using namespace std;

struct Skarbiec
{
	double x, y;
	int zloto;
};
struct Rozbojnik
{
	int zloto;
	Skarbiec* skarbiec;
};

Skarbiec wylosujSkarbiec()
{
	Skarbiec s;
	s.x = (1.0*rand() / RAND_MAX) * 100;
	s.y = (1.0*rand() / RAND_MAX) * 100;
	s.zloto = 0;
	return s;
}


// Wypisanie wszystkich informacji o skarbcu, na który pokazuje podany wskaŸnik.
void wypiszSkarbiec(Skarbiec* s)
{
	int p = cout.precision();
	cout.precision(5);
	setlocale(LC_ALL, "");
	cout << "Wspó³rzêdne:\tx=" << s->x << "\ty=" << s->y << endl;
	cout << "Z³oto: \t" << s->zloto << endl;
	cout.precision(p);
}
// Wypisanie wszystkich informacji o podanym rozbojniku.
void wypiszRozbojnika(Rozbojnik r)
{
	cout << "Posiadane z³oto:" << r.zloto << endl;
	cout << "Skarbiec:" << endl;
	wypiszSkarbiec(r.skarbiec);
}

void schowajLupy(Rozbojnik* r){
	if (r->zloto > 10)
	{
		r->skarbiec->zloto += (r->zloto - 10);
		r->zloto = 10;
	}
}

void przeniesSkarbiec(Rozbojnik* r)
{
	int pom;
	pom = r->skarbiec->zloto;
	r->skarbiec->zloto = 0;
	r->skarbiec = new Skarbiec;
	*(r->skarbiec) = wylosujSkarbiec();
	r->skarbiec->zloto = pom;
}

int main() {
	Skarbiec NowySkarbiec = wylosujSkarbiec();
	Rozbojnik r1 = { 100, &NowySkarbiec };
	Rozbojnik r2 = { 100, &NowySkarbiec };
	wypiszRozbojnika(r1);
	wypiszRozbojnika(r2);
	//podpunkt2
	schowajLupy(&r1);
	schowajLupy(&r2);
	wypiszRozbojnika(r1);
	wypiszRozbojnika(r2);
	//podpunkt3
	przeniesSkarbiec(&r1);
	wypiszRozbojnika(r1);
	wypiszRozbojnika(r2);
	//podpunkt4
	Rozbojnik* rozbojnicy = new Rozbojnik[40];
	int suma = 0;
	for (int i = 0; i < 40; i++)
	{
		rozbojnicy[i] = { rand() % 21, &NowySkarbiec };
		suma += rozbojnicy[i].zloto;
	}
	cout << "Suma zlota: " << suma << endl;
	//podpunkt5
	suma = 0;
	for (int i = 0; i < 40; i++)
	{
		schowajLupy(&(rozbojnicy[i]));
		suma += rozbojnicy[i].zloto;
	}
	cout << "Suma zlota: " << suma << endl;
	cout << "Stan skarbca: ";
	wypiszSkarbiec(&NowySkarbiec);
	delete[] rozbojnicy;
	return 0;
}