#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
	srand(time(0));
	const int r=10;
	int tab[r]={0};
	
	for(int i=0; i<r; i++)
	tab[i]=rand()%100;

	for(int i=0; i<r; i++)
	{
		if (tab[i]%2==0)	
		cout<<tab[i]<<endl;
	}
	cout<<endl;					//parzyste
	
	int i=0;
	
	do 
	{
		if (tab[i]%2|0)
		cout<<tab[i]<<endl;	
		i++;
	}
	
	while (i<r);			
	
	cout<<endl;					//nieparzyste
	
	i=0;
	while (i<r)
	{
	if (tab[i]<5)	
	cout<<tab[i]<<endl;	
	i++;
	}
							//mniejsze od 5
	system("pause");
	return 0;	
}
