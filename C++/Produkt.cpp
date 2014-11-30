#include <cstdlib>
#include <iostream>

using namespace std;

class Produkt{
	private:
	string nazwa;
	int cena;
	
	public:
		
		Produkt(){
			cout << "Utworzono obiekt za pomoca konstruktora bez parametrow" << endl;
			nazwa = "Brak nazwy";
			cena = 0;
		}
		
		Produkt(string nazwa, int cena) {
			this -> nazwa = nazwa;
			this -> cena = cena;
			}
		
		void setNazwa(string nazwa)
		{
			this -> nazwa = nazwa;
		}

		void setCena(float cena)
		{
		this -> cena = cena;
		}
		
		void info()
		{
			cout << "Nazwa produktu: " << nazwa << endl;
			cout << "Cena produktu: " << cena << endl << endl;
			}
};

int main(int argc, char *argv[])
{
Produkt p1;
p1.setNazwa("Laptop");
p1.setCena(4500);
p1.info();	

Produkt p2;
p2.info();	

Produkt p3("Mysz", 15);
p3.info();	
		
	system("pause");
	return 0;
}
