#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	
	const int rozmiar=10;
	int tab1[rozmiar]={0};				//zerowanie tablicy
	
	for (int i=0; i<rozmiar; i++)		//wype³nianie tablicy w pêtli 
		tab1[rozmiar-1-i]=rand()%100;	
											
	int suma=0;	
	
	for(int i=0; i<rozmiar; i++)		//wyœwietlanie tablicy
	{
		cout<<tab1[i]<<endl;
		suma=suma+tab1[i];				//sumowanie tablicy
		}	
			
	cout<<endl<<suma<<endl;	 			//wyœwietlanie sumy
	
	float sr=0;
	
	sr=(float)suma/rozmiar;				//liczenie œredniej
	cout<<endl<<sr<<endl;				//wyœwietlanie œredniej
	
	system("pause");
	return 0;
}
