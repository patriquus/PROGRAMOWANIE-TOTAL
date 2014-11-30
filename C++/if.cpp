#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int a,b;
	cout<<"Podaj liczbe a"<<endl<<endl;
	cin>>a;
	cout<<"Podaj liczbe b"<<endl<<endl;
	cin>>b;
	
	if (a>b)
	{
		cout<<a<<" jest wieksze od "<<b<<endl<<endl;
		}
		
	else if (a<b)
	{
		cout<<a<<" jest mniejsze od "<<b<<endl<<endl;
		}	
	
	else
	{
		cout<<a<<" jest rowne "<<b<<endl<<endl;
		}	
	
	
	system("pause");
	return 0;
}
