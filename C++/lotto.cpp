#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char *argv[])
{
	srand(time(0));
	int tab[6]={0};	//zerowanie tablicy
	int x, powt;
	
	for(int i=0; i<6;)
	{
		do {
			x=rand()%48+1;		//przypisywanie losowej wartosci do zmiennej x
			for (int j=0;j<6;j++)
			{
				powt=0;
				if(tab[j]==x)
				{
					powt=1;	//sprawdzanie czy liczba sie powtorzyla
					break;
				}

			}
			}
			while (powt==1);
			tab[i]=x;		//przypisywanie wartosci do elementu tablicy
			i++;
			}
	
	int tab1[6]={0};
	cout<<"Podaj 6 liczb"<<endl;	
	
	for(int i=0; i<6; i++)
	{
		label1:
		cin>>tab1[i];
			
		if(tab1[i] < 1 || tab1[i] > 48)
		{
			cout<<"Musisz podac liczbe od 1 do 48"<<endl;
			goto label1;
		}
	}

	cout<<"\n\nTRWA LOSOWANIE\n\n";
	cout<<"Wylosowane liczby to:"<<endl;
			
	for(int i=0; i<6; i++)
	cout<<tab[i]<<" ";	
	
	int los=0;	
	for(int i=0; i<6;i++)
	{	
		for(int j=0; j<6; j++)
		{
			if (tab[i]==tab1[j])
			los++;
		}
	}
	
	if (los==0 || los==5 || los==6)
	cout<<"\n\nTrafiles "<<los<<" liczb"<<endl;
	else if (los==1)
	cout<<"\n\nTrafiles "<<los<<" liczbe"<<endl;
	else if (los>1 && los<5)
	cout<<"\n\nTrafiles "<<los<<" liczby"<<endl;
			
	system("pause");
	return 0;	
}
