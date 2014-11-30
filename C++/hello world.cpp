#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	cout<<"Program kalkulator"<<endl<<endl<<endl;
	cout<<"1. Dodawanie + \n2. Odejmowanie -\n3. Mnozenie *\n4. Dzielenie /\n5. Reszta z dzielenia"<<endl;
	int a, b, wyb;
	cin>>wyb;
	
	if (wyb==1)
	{
		
	cout<<"Podaj liczbe a: ";
	cin>>a; //wszytujemy liczbe a
	cout<<endl;
	
	cout<<"Podaj liczbe b: ";
	cin>>b; //wczytujemy liczbe b
	cout<<endl;
	
	cout<<"Wprowadziles liczby "<<a<<" i "<<b<<endl<<endl;
	
	cout<<"Suma liczb a i b wynosi: ";
	cout<<a+b<<endl;
	}
	
	else if (wyb==2)
	{
	cout<<"Podaj liczbe a: ";
	cin>>a; //wszytujemy liczbe a
	cout<<endl;
	
	cout<<"Podaj liczbe b: ";
	cin>>b; //wczytujemy liczbe b
	cout<<endl;
	
	cout<<"Wprowadziles liczby "<<a<<" i "<<b<<endl<<endl;
	
	cout<<"Roznica liczb a i b wynosi: ";
	cout<<a-b<<endl;
	}

	else if (wyb==3)
	{
		
	cout<<"Podaj liczbe a: ";
	cin>>a; //wszytujemy liczbe a
	cout<<endl;
	
	cout<<"Podaj liczbe b: ";
	cin>>b; //wczytujemy liczbe b
	cout<<endl;
	
	cout<<"Wprowadziles liczby "<<a<<" i "<<b<<endl<<endl;
	
	cout<<"Iloczyn liczb a i b wynosi: ";
	cout<<a*b<<endl;
	}

 	else if (wyb==4)
	{
	cout<<"Podaj liczbe a: ";
	cin>>a; //wszytujemy liczbe a
	cout<<endl;
	
	cout<<"Podaj liczbe b: ";
	cin>>b; //wczytujemy liczbe b
	cout<<endl;
	
	cout<<"Wprowadziles liczby "<<a<<" i "<<b<<endl<<endl;
	
	cout<<"Iloraz liczb a i b wynosi: ";		
	cout<<a/b<<endl;
	}
	
	else if (wyb==5)
	{
	cout<<"Podaj liczbe a: ";
	cin>>a; //wszytujemy liczbe a
	cout<<endl;
	
	cout<<"Podaj liczbe b: ";
	cin>>b; //wczytujemy liczbe b
	cout<<endl;
	
	cout<<"Wprowadziles liczby "<<a<<" i "<<b<<endl<<endl;
	
	cout<<"Reszta z dzielenia liczb a i b wynosi: ";
	cout<<a%b<<endl<<endl;
	}
	
	else
	{
	cout<<"Wprodziles zla wartosc"<<endl;
	}

	system("pause");
	return 0;
}
