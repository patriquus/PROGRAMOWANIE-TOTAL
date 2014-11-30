#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int x;
	
	cin>>x;
	for(int i=x; i>1; i--)
	{	
		for(int j=1; j<=i; j++)
		{
			cout<<"* ";
			}
			
		cout<<endl;
		}
		
	for(int i=1; i<x+1; i++)
	{
		for(int j=1; j<=i; j++)
		{
			cout<<"* ";
			}
			
		cout<<endl;
		}
	
	system("pause");
	return 0;
}
