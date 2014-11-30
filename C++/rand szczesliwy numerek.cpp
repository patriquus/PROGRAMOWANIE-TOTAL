#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{

	int x=time(0);
	srand(time(0));
	int l;
	int w=rand()%100;
	bool win=0;
	int i=0;
	
	//cout<<"Podaj liczbe"<<w<<endl;	
    	
	for (i=0; i<5; i++)
		{
		cout<<"Podaj liczbe"<<endl;
		cin>>l;	
			
		if (l==w)
			{
				win=1;
				break;
				}
				
		else if (l<w)
			cout<<"Podales za mala liczbe"<<endl;
		else if (l>w)
			cout<<"Podales za duza liczbe"<<endl;	
			}
	
	int y=time(0);	
	if (win==1)
		cout<<"Podales prawidlowa liczbe za "<<i+1<<" razem po "<<y-x<<" sekundach"<<endl;
	else if (win==0)
		cout<<"Niestety ci sie nie udalo - szczesliwym numerkiem byla liczba "<<w<<endl;	

	system("pause");
	return 0;
}
