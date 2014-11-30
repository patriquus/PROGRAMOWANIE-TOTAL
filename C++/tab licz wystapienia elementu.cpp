#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
	srand(time(0));
	const int r=1000;
	int tab[r]={0};
	int x;
	
	for(int i=0; i<r; i++)
	tab[i]=rand()%101;
	
/*	for(int i=0; i<r; i++)
	{
		cout<<tab[i]<<endl;		//wyœwietlanie tablicy
	}		
*/	

    int licz=0;
	cout<<"Podaj liczbe "<<endl;
	cin>>x;	
	
	for(int i=0; i<r; i++)
	{	
		if (tab[i]==x)
	    licz++;
	}
	
	cout<<"Liczba pojawila sie w tablicy "<<licz<<" razy"<<endl;	

	system("pause");
	return 0;	
}
