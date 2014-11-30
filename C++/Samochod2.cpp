#include <cstdlib>
#include <iostream>

using namespace std;

class Samochod{
	public:
	string marka;
	string model;
	string kolor;
	int vmax;
	int v;
	int stan;
	
	Samochod(){
	marka = "brak";
	model = "brak";
	kolor = "bez lakieru";
	vmax = 0;
	v = 0;	
	stan = 0;	
	}
	
	Samochod(string marka, string model, string kolor, int vmax, int v){
	this -> marka = marka;
	this -> model = model;
	this -> kolor = kolor;
	this -> vmax =vmax;
	this -> v = v;
	this -> stan = stan;
}

	void wprowadz_dane(){
		cout << "WPROWADZ DANE POJAZDU:" << endl << endl;
		cout << "Podaj marke: ";
		cin >> marka;
		cout << "Podaj model: ";
		cin >> model;		
		cout << "Podaj kolor: ";
		cin >> kolor;	
		cout << "Podaj predkosc maksymalna (km/h): ";
		cin >> vmax;			
	}
	
	void info(){			
		cout << "Twoj samochod to " << marka << " " << model << endl;
		cout << "Kolor lakieru: " << kolor << endl;
		cout << "Predkosc maksymalna: " << vmax << " km/h" << endl;
	}
	
	void wlacz_silnik() {
		stan = 1;
		cout << "Uruchomiono silnik" << endl;
	}
	
	void przyspiesz() {
		v = v + 10;
		cout << "Aktualna predkosc: " << v << " km/h" << endl;
	}
	
	void zwolnij() {
		v = v - 10;
		cout << "Aktualna predkosc: " << v << " km/h" << endl;
		
	}
	
	void hamuj() {
		v = 0;
	}
	
};
int main(int argc, char *argv[]){
	Samochod s;
	s.wprowadz_dane();
	s.info();
	
	cout<<"1. Wlacz silnik"<<endl;
	cout<<"2. Przyspiesz"<<endl;
	cout<<"3. Zwolnij"<<endl;
	cout<<"4. Hamuj"<<endl;
	
	label1:
	int i = 0;
	
	cin >> i;	
		
		switch(i){
		
		case 1:
		s.wlacz_silnik();
		break;
			
		case 2:
		if (s.stan == 1){
			s.przyspiesz();				
		}
		else {
			cout << "Wlacz silnik" << endl;
			goto label1;	
		}		
		break;
			
		case 3:
		s.zwolnij();
		break;
			
		case 4:
		s.hamuj();
		break;
		
		default:
		cout<<"Sprobuj ponownie"<<endl;
		goto label1;
	}
	goto label1;



	system("pause");
	return 0;
}
