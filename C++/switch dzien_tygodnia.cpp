#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int i;
	label1:
	cout<<"Wpisz nr dnia tygodnia"<<endl;
	cin>>i;

	switch(liczba){
		
		case 1:
		cout<<"Poniedzialek"<<endl;
		break;
			
		case 2:
		cout<<"Wtorek"<<endl;
		break;
			
		case 3:
		cout<<"Sroda"<<endl;
		break;
			
		case 4:
		cout<<"Czwartek"<<endl;
		break;
		
		case 5:
		cout<<"Piatek"<<endl;
		break;
			
		case 6:
		cout<<"Sobota"<<endl;
		break;
			
		case 7:
		cout<<"Niedziela"<<endl;
		break;
		
		default:
		cout<<"Wybierz nr dnia tygodnia od 1 do 7"<<endl;
		goto label1;
	}
	
	system("pause");
	return 0;
}
