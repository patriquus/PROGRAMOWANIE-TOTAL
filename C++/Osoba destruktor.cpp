#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class Osoba {
	public: string imie, nazwisko;
	
	Osoba() {
		imie = "brak";
		nazwisko = "brak";
	}
	
	Osoba(string imie, string nazwisko) {
		this -> imie = imie;
		this -> nazwisko = nazwisko;
	}
	~Osoba() {
		cout << "obiekt zostal zniszczony" << endl;
	}
	
};

int main(int argc, char *argv[]) {


	return 0;
}
