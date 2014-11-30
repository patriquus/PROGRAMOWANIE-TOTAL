#include <cstdlib>
#include <iostream>

using namespace std;

class Zwierze {
	protected:
		int x;
		
	void istnieje(){
		cout<<"Istnieje\n";
		x=1;	
	}
	
	public:
	void oddychaj(){
		this->istnieje();
		cout<<"Oddycham\n";	
	}
	
	void jedz(){
		cout<<"Jem\n";	
	}
	
	Zwierze(){
		cout<<"Utworzono obiekt ZWIERZE"<<endl;	
	}
};

class Ptak: public Zwierze{
	public:
		Ptak(){
			cout<<"Utworzono obiekt PTAK"<<endl;
		}
		void latac(){
			cout<<"Latam\n";	
		}
};

int main(int argc, char *argv[]){
	// ZWIERZE
	Zwierze z;
	z.oddychaj();
	z.jedz();
	
	// PTAK
	Ptak p;
	p.oddychaj();
	p.jedz();
	p.latac();
	system("pause");
	return 0;
}
