#include <cstdlib>
#include <iostream>

using namespace std;

class Konto {
	public:
		string imie, nazwisko, nr_konta;
		float saldo;
		
Konto(){
	imie = "bd.";
	nazwisko = "bd.";
	nr_konta = "brak";
	saldo = 0;
}		

Konto(string imie, string nazwisko, string nr_konta, float saldo){
	this -> imie = imie;
	this -> nazwisko = nazwisko;
	this -> nr_konta = nr_konta;
	this -> saldo = saldo;
}

void wczytaj_dane() {
	cout << "Podaj imie: ";
	cin >> imie;
	cout << "Podaj nazwisko: ";
	cin >> nazwisko;
	cout << "Podaj nr konta: ";
	cin >> nr_konta;
	cout << "Podaj biezace saldo: ";
	cin >> saldo;
}

void info() {
	cout << "Imie i nazwisko: " << imie << " " << nazwisko << endl;
	cout << "Numer rachunku: " << nr_konta << endl;
	cout << "Biezace saldo: " << saldo << endl;
}

void wplata(){
	int wplata;
	cout << "Podaj kwote wplaty: ";
	cin >> wplata;
	saldo = saldo + wplata;
	}

void wyplata(){
	int wyplata;
	cout << "Podaj kwote wyplaty: ";
	cin >> wyplata;
	if (wyplata > saldo) {
		cout << "Mozesz maksymalnie wyplacic " << saldo << " PLN. Sproboj ponownie.";
	}
	else
	saldo = saldo - wyplata;
}	
		
};

int main(int argc, char *argv[]) {

	Konto k1;
	k1.info();
	k1.wczytaj_dane();
	k1.info();
	
	k1.wplata();
	k1.wyplata();
	k1.wyplata();
	

	
	system("pause");
	return 0;
}
