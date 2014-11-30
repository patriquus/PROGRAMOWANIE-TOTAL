#include <cstdlib>
#include <iostream>

using namespace std;

class Samochod{
	public:
	string marka;
	string model;
	int rocznik;
	string typ;
	int ilosc_drzwi;
	
	Samochod(){
	marka = "brak";
	model = "brak";
	rocznik = 0;
	typ = "brak";
	ilosc_drzwi = 0;		
	}
	
	Samochod(string marka, string model, int rocznik, string typ, int ilosc_drzwi){
	this->marka=marka;
	this->model=model;
	this->rocznik=rocznik;
	this->typ=typ;
	this->ilosc_drzwi=ilosc_drzwi;
}

	void wczytaj_dane(){
		cout<<"Podaj marke"<<endl;
		cin>>marka;
		cout<<"Podaj model"<<endl;
		cin>>model;		
		cout<<"Podaj rocznik"<<endl;
		cin>>rocznik;		
		cout<<"Podaj typ"<<endl;
		cin>>typ;		
		cout<<"Podaj ilosc drzwi"<<endl;
		cin>>ilosc_drzwi;
	}
	
	void info(){			
		cout<<"Marka "<<marka;
		cout<<"\tModel "<<model;
		cout<<"\tRocznik "<<rocznik;
		cout<<"\tTyp "<<typ;
		cout<<"\tIlosc drzwi "<<ilosc_drzwi<<endl;
	}
};
int main(int argc, char *argv[]){
	Samochod samochodzik;
	samochodzik.wczytaj_dane();
	samochodzik.info();
	
	system("pause");
	return 0;
}
