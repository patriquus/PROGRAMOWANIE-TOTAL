#include <cstdlib>
#include <iostream>

using namespace std;

class Prostokat{
	private:
		int a;
		int b;
		int pole;
		int obwod;
		
	public:
		Prostokat() {
			a = 0;
			b = 0;
		}	
		
		Prostokat(int a, int b) {
			this -> a = a;
			this -> b = b;
		}
		
	void wczytaj_dane() {
		cout << "Podaj bok a: ";
		cin >> a;
		cout << "Podaj bok b: ";		
		cin >> b;
	}
		
	void przetworz_dane() {
		pole=a*b;
		obwod=2*a+2*b;
	}
			
	void wyswietl_wynik() {
			cout << "Pole wynosi: " << pole << endl;
			cout << "Obwod wynosi: " << obwod << endl;
		}
};

int main(int argc, char *argv[])
{

Prostokat p1, p2;	
p1.wczytaj_dane();
p2.wczytaj_dane();
p1.przetworz_dane();
p2.przetworz_dane();
p1.wyswietl_wynik();
p2.wyswietl_wynik();

		
	system("pause");
	return 0;
}
