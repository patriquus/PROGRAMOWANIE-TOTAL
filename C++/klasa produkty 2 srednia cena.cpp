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
		void setNazwa(string s)
		{
			nazwa = s;
		}
		string getNazwa()
		{
			return nazwa;
		}
		
		void setIlosc(int s)
		{
		ilosc = s;
		}
		int getIlosc()
		{
			return ilosc;
		}

		void setCena(float s)
		{
		cena = s;
		}
		float getCena()
		{
			return cena;
		}
		
		void setProducent(string s)
		{
		producent = s;
		}
		string getProducent()
		{
			return producent;
		}
};

int main(int argc, char *argv[])
{
	int a=5;
	Produkt p[a];
	float suma = 0, srednia = 0;
	for (int i=1; i<5; i++)
	{
		string nazwa;
		cout<<"Podaj nazwe " << i << ". produktu"<<endl;
		cin>>nazwa;
		p[i].setNazwa(nazwa);
		
		int ilosc;
		cout<<"Podaj ilosc " << i << "s. produktow"<<endl;
		cin>>ilosc;
		p[i].setIlosc(ilosc);
		
		float cena;
		cout<<"Podaj cene " << i << ". produktu"<<endl;
		cin>>cena;
		p[i].setCena(cena);
		
		string producent;
		cout<<"Podaj nazwe producenta " << i << ". produktu"<<endl;
		cin>>producent;
		p[i].setProducent(producent);		
		
		suma=suma+p[i].getCena();				
		}			
	
	for(int i=1; i<5; i++)
	{
		cout<<p[i].getNazwa()<<endl;
		cout<<p[i].getIlosc()<<endl;
		cout<<p[i].getCena()<<endl;
		cout<<p[i].getProducent()<<endl;	
	
	}
		
	srednia=suma/a;
	cout<<"Srednia wynosi = "<<srednia<<endl;	
		
		
	
		
	system("pause");
	return 0;
}
