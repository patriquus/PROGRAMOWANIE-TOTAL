#include <cstdlib>
#include <iostream>

using namespace std;

void funkcja(int,int);

int main(int argc, char *argv[])
{
    int x,y;
    cout<<"Podaj dlugosc boku x"<<endl;
    cin>>x;
    cout<<"Podaj dlugosc boku y"<<endl;
    cin>>y;   
    
	funkcja(x,y);
	system("pause");
	return 0;
}

void funkcja(int x, int y)
{
	
	for(int i=0; i<y; i++)
	{
		for(int i=0; i<x; i++)
		{
			cout<<"*";
		}
	cout<<endl;
	}
	
	cout<<endl;
}

	


