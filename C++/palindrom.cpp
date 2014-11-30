#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
	int r = 100;
	int p = 0;
	char tab[r];
	
	cout<<"Podaj wyraz"<<endl;
	cin>>tab;
	for(int i=0; i<r; i++)
	tolower(tab[i]);
	
	int n = strlen(tab);
	
	for(int i=0; i<n/2; i++)
	{
		if (tab[i]!=tab[n-1])
		{
		p=1;
		break;
		}
		
		n--;
	}
	
	if(p==0)
	cout<<"Podany wyraz jest palindromem"<<endl;
	else
	cout<<"Podany wyraz nie jest palindromem"<<endl;
		
	system("pause");
	return 0;
}
