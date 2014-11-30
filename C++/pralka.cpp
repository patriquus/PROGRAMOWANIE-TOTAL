#include <cstdlib>
#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

class program{
	private:
	string nazwa;			//mazwa programu
	int temp, obr, zal;		//temperatura, max obroty, max zaladunek
	
	public:
		void setNazwa(string a){
			nazwa = a;
		}
		string getNazwa(){
			return nazwa;
		}

		void setTemp(int a){
			temp = a;
		}
		int getTemp(){
			return temp;
		}
		
		void setObr(int a){
			obr = a;
		}
		int getObr(){
			return obr;
		}
		
		void setZal(int a){
			zal = a;
		}
		int getZal(){
			return zal;
		}				
};

int main(int argc, char *argv[])
{

	program p[10];			//		PROGRAMY PRANIA
	
	p[1].setNazwa("Bawelna");
	p[1].setTemp(60);
	p[1].setObr(1200);
	p[1].setZal(7);
	
	p[2].setNazwa("Super krotkie");
	p[2].setTemp(30);
	p[2].setObr(1200);
	p[2].setZal(3.5);
	
	p[3].setNazwa("Reczniki");
	p[3].setTemp(60);
	p[3].setObr(1200);
	p[3].setZal(7);
	
	p[4].setNazwa("Welna");
	p[4].setTemp(40);
	p[4].setObr(900);
	p[4].setZal(2.5);
	
	p[5].setNazwa("Syntetyki");
	p[5].setTemp(40);
	p[5].setObr(900);
	p[5].setZal(3.5);
	
	p[6].setNazwa("Jedwab");
	p[6].setTemp(10);
	p[6].setObr(600);
	p[6].setZal(2);
	
	p[7].setNazwa("Mix");
	p[7].setTemp(10);
	p[7].setObr(1200);
	p[7].setZal(3.5);
	
	p[8].setNazwa("Jeans");
	p[8].setTemp(40);
	p[8].setObr(1200);
	p[8].setZal(3.5);
	
	p[9].setNazwa("Intensywne");
	p[9].setTemp(60);
	p[9].setObr(1200);
	p[9].setZal(3.5);

	system("cls");

	cout<<"PROGRAMY PRANIA"<<endl<<endl;	
	cout<<"1. Bawelna"<<endl;	
	cout<<"2. Super krotkie"<<endl;		
	cout<<"3. Reczniki"<<endl;		
	cout<<"4. Welna"<<endl;		
	cout<<"5. Syntetyki"<<endl;		
	cout<<"6. Jedwab"<<endl;		
	cout<<"7. Mix"<<endl;		
	cout<<"8. Jeans"<<endl;		
	cout<<"9. Intensywne"<<endl<<endl;		
	
	int i=0;
	wyb_prog:	
	cout<<"Wybierz program: "<<endl;
	cin>>i;
	cout<<endl;
	
	if (i>0 && i<10) {
		cout<<"Wybrales program: "<<i<<". "<< p[i].getNazwa()<<endl<<endl;
		cout<<"Uwaga! Maksymalny zaladunek wynosi "<<p[i].getZal()<<" kg"<<endl;
		cout<<"Temperatura wody ustawiona na "<<p[i].getTemp()<<" stopni"<<endl;
		cout<<"Maksymalna predkosc wirowania ustawiona na "<<p[i].getObr()<<" obr./min."<<endl;	
		cout<<endl;			
	}
	
	else {
		cout<<"Blad. Wybrales zly program. Sprobuj ponownie."<<endl;
		goto wyb_prog;
	}
	
	cout<<"Rozpoczynam pranie..."<<endl;
    Sleep(10000);	  
	system("cls");		
    cout<<"TRWA PRANIE..."<<endl; 
	 
    for(int i=120; i>0; i--)
    {
    	cout<<"Pozostalo "<<i<<" minut do konca\r";
        Sleep(60000);      
    }
    
    cout<<"Zakonczono pranie"<<endl;
		
	system("pause");
	return 0;
}
