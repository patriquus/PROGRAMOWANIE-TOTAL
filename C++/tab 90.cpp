#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	const int rozmiar=10;
	int tab1[rozmiar]={0};	//zerowanie tablicy
		
	for (int i=9; i<10; i--)	//wype�nianie tablicy w p�tli 
		tab1[i]=i;										
	
	for(int i=0; i<rozmiar; i++)	//wy�wietlanie tablicy
		cout<<tab1[i]<<endl;
		 
	system("pause");
	return 0;
}
