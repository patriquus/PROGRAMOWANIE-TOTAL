#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	for(int i=5; i>1; i--)
	{	
		for(int j=1; j<=i; j++)
		{
			cout<<"* ";
			}
			
		cout<<endl;
		}
		
	for(int i=1; i<6; i++)
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
