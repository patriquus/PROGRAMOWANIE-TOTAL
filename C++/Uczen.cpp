#include <cstdlib>
#include <iostream>

using namespace std;

class Osoba {
	public:
		string imie, nazwisko, adres, pesel, data_ur;
	
	Osoba() {
		imie = "bd.";
		nazwisko = "bd.";
		adres = "bd.";
		pesel = "00000000000";
		data_ur = "00.00.0000";
	}
	
	Osoba(string imie, string nazwisko, string adres, string pesel, string data_ur) {
		this -> imie = imie;
		this -> nazwisko = nazwisko;
		this -> adres = adres;
		this -> pesel = pesel;
		this -> data_ur = data_ur;
	}		
};

class Uczen: public Osoba {
	public: 
	string klasa, profil, data_rozp, nr_legit;
	
	Uczen() {
		klasa = "bd.";
		profil = "bd.";
		data_rozp = "bd.";
		nr_legit = "bd.";
	}
	
	Uczen(string klasa, string profil, string data_rozp, string nr_legit) {
		this -> klasa = klasa;
		this -> profil = profil;
		this -> data_rozp = data_rozp;
		this -> nr_legit = nr_legit;
	}
	
	void wprowadz_dane() {
		cout << "Podaj imie: ";
		cin >> imie;
		cout << "Podaj nazwisko: ";
		cin >> nazwisko;
		cout << "Podaj adres: ";
		cin >> adres;
		cout << "Podaj PESEL: ";
		cin >> pesel;
		cout << "Podaj date urodzenia: ";
		cin >> data_ur;
		cout << "Podaj klase: ";
		cin >> klasa;
		cout << "Podaj profil: ";
		cin >> profil;
		cout << "Podaj date rozpoczecia nauki: ";
		cin >> data_rozp;
		cout << "Podaj nr legitymacji szkolnej: ";
		cin >> nr_legit;		
		cout << endl;
	}	
	
	void wyswietl() {
		cout << "Imie i nazwisko: " << imie << " " << nazwisko << endl;
		cout << "Adres: " << adres << endl;
		cout << "PESEL: " << pesel << endl;
		cout << "Data urodzenia: " << data_ur << endl;
		cout << "Klasa " << klasa << ", profil " << profil << endl;
		cout << "Data rozpoczecia nauki: " << data_rozp << endl;
		cout << "Legitymacja szkolna nr " << nr_legit << endl;
		cout << endl;
	}
};

int main(int argc, char *argv[]) {

	Uczen nr[30];
	
	for(int n=0; n<2; n++)
	nr[n].wprowadz_dane();
	
	for(int n=0; n<2; n++)
	nr[n].wyswietl();

	system("pause");
	return 0;
}
