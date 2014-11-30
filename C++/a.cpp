#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{	

int n;
cout<<"Podaj n"<<endl;
cin>>n;
cout<<endl;

for(int i=0; i<2*n+1; i++)
cout<<"x";
cout<<endl;

for(int i=0; i<2*n;i++)
{
	for(int i=0; i<n; i++)
	cout<<" ";
	cout<<"x"<<endl;
}

for(int i=0; i<2*n+1; i++)
cout<<"x";
cout<<endl;
	
	cout<<endl;	
	system("pause");
	return 0;
}
