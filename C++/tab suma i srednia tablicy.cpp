#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	
	const int rozmiar=10;
	int tab1[rozmiar]={0};				//zerowanie tablicy
	
	for (int i=0; i<rozmiar; i++)		//wype�nianie tablicy w p�tli 
		tab1[rozmiar-1-i]=rand()%100;	
											
	int suma=0;	
	
	for(int i=0; i<rozmiar; i++)		//wy�wietlanie tablicy
	{
		cout<<tab1[i]<<endl;
		suma=suma+tab1[i];				//sumowanie tablicy
		}	
			
	cout<<endl<<suma<<endl;	 			//wy�wietlanie sumy
	
	float sr=0;
	
	sr=(float)suma/rozmiar;				//liczenie �redniej
	cout<<endl<<sr<<endl;				//wy�wietlanie �redniej
	
	system("pause");
	return 0;
}
