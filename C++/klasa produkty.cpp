#include <cstdlib>
#include <iostream>

using namespace std;

class Produkt{
	private:
	string nazwa;
	int ilosc;
	float cena;
	string producent;
	
	public:
		void setNazwa(string s){
			nazwa = s;
		}
		string getNazwa(){
			return nazwa;
		}
		
		
		
			void setIlosc(int s){
			ilosc = s;
		}
		int getIlosc(){
			return ilosc;
		}
		
		
		
			void setCena(float s){
			cena = s;
		}
		float getCena(){
			return cena;
		}
		
		
		
			void setProducent(string s){
			producent = s;
		}
		string getProducent(){
			return producent;
		}
};

int main(int argc, char *argv[])
{
	Produkt p1;
	p1.setNazwa("klawiatura");
	p1.setIlosc(100);
	p1.setCena(32);
	p1.setProducent("Microsoft");
	
/*	p1.nazwa = "Klawiatura";
	p1.ilosc = 100;
	
	monitor.nazwa = "monitor";
	monitor.ilosc = 100;
*/

	cout<<"Nazwa produktu: "<<p1.getNazwa()<<endl;
	cout<<"Ilosc produktu: "<<p1.getIlosc()<<endl;	
	cout<<"Cena za produkt: "<<p1.getCena()<<endl;	
	cout<<"Producent: "<<p1.getProducent()<<endl;
	
	system("pause");
	return 0;
}
