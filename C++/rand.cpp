#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
	srand(time(0));
	int tab[10]={0};
	int dodatnie=0, ujemne=0;
	
	for(int i=0; i<10; i++)
	{
		tab[i]=rand()%101-51;
		cout<<tab[i]<<endl;	
		if (tab[i]>0)
		dodatnie++;
		else if (tab[i]<0)
		ujemne++;			
	}

	cout<<"Wylosowanych liczb dodatnich: "<<dodatnie<<endl;
	cout<<"Wylosowanych liczb ujemne: "<<ujemne<<endl;
		
	system("pause");
	return 0;
}
