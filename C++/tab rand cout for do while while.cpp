#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{

	const int r=10;     //rozmiar tablicy
	int tab[r]={0};     //zerowanie tablicy
	
	for(int i=0; i<r; i++)
	tab[i]=rand()%100;    //przypisywanie losowej wartości do kolejnych elementów tablicy
	
    //wyświetlanie zawartości tablicy petla for
	for(int i=0; i<r; i++)
	cout<<tab[i]<<endl;   
	
	int i=0;

	cout<<endl;
    //wyświetlanie zawartości tablicy petla do while	
	do 
	{

		cout<<tab[i]<<endl;	
		i++;
	}
	
	while (i<r);
	
	cout<<endl;
	
    //wyświetlanie zawartości tablicy petla while
	i=0;
	while (i<r)
	{	
	cout<<tab[i]<<endl;	
	i++;
	}
	
	system("pause");
	return 0;	
}
