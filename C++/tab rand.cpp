#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char *argv[])
{

	srand(time(0));
	const int r=10; //rozmiar tablicy
	int tab[r]={0}; //zerowanie tablicy
				
	int i=0;
	
	do {
	tab[i]=rand()%100;          //przypisywanie losowych warto�ci do kolejnych element�w tablicy
	
	cout<<tab[i]<<endl;	        //wy�wietlenie kolejnego elementu tablicy
	i++;
	}
	while (i<r);
	
	system("pause");
	return 0;	
}
