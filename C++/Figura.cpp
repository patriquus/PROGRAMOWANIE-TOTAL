#include <cstdlib>
#include <iostream>

using namespace std;

class Figura{
	protected:
		int wysokosc, szerokosc;
	public: void ustaw_wartosc (int a, int b)
	{
		wysokosc = a;
		szerokosc = b;
	}
};

class Prostokat: public Figura{
	public:
		int pole(){
			return wysokosc * szerokosc;
		}
};

class Trojkat: public Figura{
	public:
		int pole(){
			return wysokosc * szerokosc / 2; 
		}
};

int main(int argc, char *argv[]) {

	Trojkat tr;
	Prostokat pr;
	tr.ustaw_wartosc(5,10);
	pr.ustaw_wartosc(5,5);
	cout << tr.pole() << endl;

	system("pause");
	return 0;
}
