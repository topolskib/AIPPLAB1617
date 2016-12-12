#include<iostream>
using namespace std;

struct Parking
{
	int rozmiar;
	bool* miejsca;
};

Parking wczytajParking()
{
	Parking parking;

	cout << "wprowadz rozmiar parkingu" << endl;
	cin >> parking.rozmiar;
	parking.miejsca = new bool[parking.rozmiar];
	cout << "wprowadz zajete miejsca" << endl;
	for (int i = 0; i < parking.rozmiar; i++)
	{
		cin >> parking.miejsca[i];
	}
	return parking;
}

void wypiszParking(Parking parking)
{
	cout << "rozmiar:" << parking.rozmiar << endl;
	cout << "miejsca:";
	for (int i = 0; i < parking.rozmiar; i++)
	{
		cout << parking.miejsca[i] << "  ";
	}
	cout << endl;
}

int obliczWolneMiejsca(Parking parking)
{
	int suma = 0;
	for (int i = 0; i < parking.rozmiar; i++)
	{
		if (parking.miejsca[i] == 0)
			suma++;
	}
	return suma;
}

int* obliczWolneMiejsca(Parking parkingi[], int n)
{
	int* suma = new int[n];

	for (int i = 0; i < n; i++)
	{
		suma[i] = obliczWolneMiejsca(parkingi[i]);
	}
	return suma;
}

int main() {
	Parking parking;
	parking = wczytajParking();

	wypiszParking(parking);

	cout << obliczWolneMiejsca(parking);
	delete[] parking.miejsca;

	Parking* parkingi = new Parking[3];
	for (int j = 0; j < 3; j++)
	{
		parkingi[j] = wczytajParking();
	}

	int* liczbaMiejsc = obliczWolneMiejsca(parkingi, 3);

	for (int i = 0; i < 3; i++)
	{
		cout << liczbaMiejsc[i] << " ";
	}

	
	delete[] liczbaMiejsc;
	for (int k = 0; k < 3; k++)
	{
		delete[] parkingi[k].miejsca;
	}
	delete[] parkingi;

	return 0;
}